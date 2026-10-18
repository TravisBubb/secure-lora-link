PORT ?= /dev/ttyUSB0
SRC  := $(shell find main components \( -name '*.c' -o -name '*.h' \) 2>/dev/null)

.PHONY: build flash monitor fm clean fullclean menuconfig format format-check check-idf

check-idf:
	@test -n "$(IDF_PATH)" || (echo "IDF_PATH not set - run get_idf first" && exit 1)

build: check-idf
	idf.py build

flash: check-idf
	idf.py -p $(PORT) flash

monitor: check-idf
	idf.py -p $(PORT) monitor

fm: check-idf
	idf.py -p $(PORT) flash monitor

clean: check-idf
	idf.py clean

fullclean: check-idf
	idf.py fullclean

menuconfig: check-idf
	idf.py menuconfig

format:
	clang-format -i $(SRC)

format-check:
	clang-format --dry-run --Werror $(SRC)

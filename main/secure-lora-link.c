#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BOARD_PIN_LED GPIO_NUM_35

static const char *TAG = "SecureLoraLink";

void app_main(void)
{
  ESP_ERROR_CHECK(gpio_reset_pin(BOARD_PIN_LED));
  ESP_ERROR_CHECK(gpio_set_direction(BOARD_PIN_LED, GPIO_MODE_OUTPUT));

  int lvl = 0;
  while (1) {
    ESP_LOGI(TAG, "LED level: %d", lvl);
    ESP_ERROR_CHECK(gpio_set_level(BOARD_PIN_LED, lvl));
    vTaskDelay(pdMS_TO_TICKS(1000));
    lvl = !lvl;
  }
}

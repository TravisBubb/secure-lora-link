#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "SecureLoraLink";

void app_main(void)
{
  while (1) {
    ESP_LOGI(TAG, "Hello, World!");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

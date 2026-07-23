#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

#define LED_PIN_1 GPIO_NUM_23
#define LED_PIN_2 GPIO_NUM_21

void app_main(void)
{
    gpio_reset_pin(LED_PIN_1);
    gpio_reset_pin(LED_PIN_2);

    gpio_set_direction(LED_PIN_1, GPIO_MODE_OUTPUT);
    gpio_set_direction(LED_PIN_2, GPIO_MODE_OUTPUT);

    while (1) {

      // for led on gpio 23
        ESP_LOGI("LED1", "ON");
        gpio_set_level(LED_PIN_1, 1);
        vTaskDelay(pdMS_TO_TICKS(200));
        ESP_LOGI("LED1", "OFF");
        gpio_set_level(LED_PIN_1, 0);
        vTaskDelay(pdMS_TO_TICKS(200));

        // for led on gpio 21
        ESP_LOGI("LED1", "ON");
        gpio_set_level(LED_PIN_2, 1);
        vTaskDelay(pdMS_TO_TICKS(200));
        ESP_LOGI("LED1", "OFF");
        gpio_set_level(LED_PIN_2, 0);
        vTaskDelay(pdMS_TO_TICKS(200));
    }
}

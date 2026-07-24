#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define NUM_LEDS 2

gpio_num_t leds[NUM_LEDS] = {
  GPIO_NUM_22,
  GPIO_NUM_23
};

/* Play any pattern */
void play_pattern(const int pattern[][NUM_LEDS], int rows, int delay_ms)
{
  for (int i = 0; i < rows; i++) {

    for (int j = 0; j < NUM_LEDS; j++) {
      gpio_set_level(leds[j], pattern[i][j]);
    }

    vTaskDelay(pdMS_TO_TICKS(delay_ms));
  }
}

void app_main(void)
{
  /* Initialize LEDs */
  for (int i = 0; i < NUM_LEDS; i++) {
    gpio_reset_pin(leds[i]);
    gpio_set_direction(leds[i], GPIO_MODE_OUTPUT);
  }

  /* ---------------- Police ---------------- */
  const int police[][NUM_LEDS] = {
    {1,0},
    {0,1},
    {1,0},
    {0,1},
    {1,0},
    {0,1},
  };

  /* --------------- Blink Together --------------- */
  const int blink[][NUM_LEDS] = {
    {1,1},
    {0,0},
    {1,1},
    {0,0},
    {1,1},
    {0,0},
  };

  /* ---------------- Double Flash ---------------- */
  const int double_flash[][NUM_LEDS] = {
    {1,0},
    {0,0},
    {1,0},
    {0,0},

    {0,1},
    {0,0},
    {0,1},
    {0,0},
  };

  /* ---------------- Ping Pong ---------------- */
  const int ping_pong[][NUM_LEDS] = {
    {1,0},
    {1,1},
    {0,1},
    {1,1},
    {1,0},
    {1,1},
    {0,1},
    {1,1},
  };

  /* ---------------- Binary Counter ---------------- */
  const int binary[][NUM_LEDS] = {
    {0,0},
    {0,1},
    {1,0},
    {1,1},
  };

  while (1) {

    play_pattern(police,
        sizeof(police) / sizeof(police[0]),
        300);

    vTaskDelay(pdMS_TO_TICKS(700));

    play_pattern(blink,
        sizeof(blink) / sizeof(blink[0]),
        400);

    vTaskDelay(pdMS_TO_TICKS(700));

    play_pattern(double_flash,
        sizeof(double_flash) / sizeof(double_flash[0]),
        200);

    vTaskDelay(pdMS_TO_TICKS(700));

    play_pattern(ping_pong,
        sizeof(ping_pong) / sizeof(ping_pong[0]),
        300);

    vTaskDelay(pdMS_TO_TICKS(700));

    play_pattern(binary,
        sizeof(binary) / sizeof(binary[0]),
        500);

    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

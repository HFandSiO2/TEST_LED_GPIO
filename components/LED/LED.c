#include "LED.h"
#include <driver/gpio.h> 

void LED_Init(gpio_num_t gpio_num)
{
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << gpio_num),
        .mode = GPIO_MODE_OUTPUT,
        .pull_up_en = GPIO_PULLUP_DISABLE,
        .pull_down_en = GPIO_PULLDOWN_DISABLE,
        .intr_type = GPIO_INTR_DISABLE
    };
    gpio_config(&io_conf);
}

void LED_Set(gpio_num_t gpio_num, bool state)
{
    gpio_set_level(gpio_num, state ? 1 : 0);
}

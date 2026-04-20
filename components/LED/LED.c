#include "LED.h"
#include "driver/gpio.h"

void LED_Init(gpio_num_t gpio_num)
{
    gpio_config_t gpio_cfg={
        .pin_bit_mask = (1ULL << gpio_num), 
        .mode = GPIO_MODE_OUTPUT, 
        .pull_up_en = GPIO_PULLUP_DISABLE, 
        .pull_down_en = GPIO_PULLDOWN_DISABLE, 
        .intr_type = GPIO_INTR_DISABLE 
    };
    esp_err_t err = gpio_config(&gpio_cfg);
    if (err != ESP_OK)ESP_LOGE("main", "Failed to configure GPIO");
}

void LED_Set(gpio_num_t gpio_num, bool on)
{
    gpio_set_level(gpio_num, on ? 1 : 0);
}
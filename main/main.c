#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <esp_log.h>

void app_main(void)
{
    ESP_LOGI("main","app_main started");
    gpio_config_t gpio_cfg={
        .pin_bit_mask = (1ULL << GPIO_NUM_12) | (1ULL << GPIO_NUM_13), 
        .mode = GPIO_MODE_OUTPUT, 
        .pull_up_en = GPIO_PULLUP_DISABLE, 
        .pull_down_en = GPIO_PULLDOWN_DISABLE, 
        .intr_type = GPIO_INTR_DISABLE 
    };
    esp_err_t err = gpio_config(&gpio_cfg);
    if (err != ESP_OK)ESP_LOGE("main", "Failed to configure GPIO");
    while(1){
        gpio_set_level(GPIO_NUM_12, 1); // Set GPIO12 high
        gpio_set_level(GPIO_NUM_13, 0); // Set GPIO13 low
        vTaskDelay(pdMS_TO_TICKS(500)); // Delay for 0.5 second

        gpio_set_level(GPIO_NUM_12, 0); // Set GPIO12 low
        gpio_set_level(GPIO_NUM_13, 1); // Set GPIO13 high
        vTaskDelay(pdMS_TO_TICKS(500)); // Delay for 0.5 second
    }
}

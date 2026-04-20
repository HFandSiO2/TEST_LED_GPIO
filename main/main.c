#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <driver/gpio.h>
#include <esp_log.h>
#include "LED.h"

void app_main(void)
{
    LED_Init(GPIO_NUM_16);
    while(1){
        LED_Set(GPIO_NUM_16, true);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        LED_Set(GPIO_NUM_16, false);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}

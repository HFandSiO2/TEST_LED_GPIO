#ifndef _LED_H_
#define _LED_H_

#include <driver/gpio.h>

void LED_Init(gpio_num_t);
void LED_Set(gpio_num_t,bool);

#endif
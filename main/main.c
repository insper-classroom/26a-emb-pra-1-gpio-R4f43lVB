/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PIN = 2;
const int MOTOR_1 = 16;
const int MOTOR_2 = 17;
const int MOTOR_3 = 18;
const int MOTOR_4 = 19;
const int BOTAO = 15;

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(MOTOR_1);
    gpio_init(MOTOR_2);
    gpio_init(MOTOR_3);
    gpio_init(MOTOR_4);
    gpio_init(BOTAO);

    gpio_set_dir(MOTOR_1, GPIO_OUT);
    gpio_set_dir(MOTOR_2, GPIO_OUT);
    gpio_set_dir(MOTOR_3, GPIO_OUT);
    gpio_set_dir(MOTOR_4, GPIO_OUT);
    gpio_set_dir(BOTAO, GPIO_IN);

    gpio_pull_up(BOTAO);

    while (true) {
        int i = gpio_get(BOTAO);
        if (!i) {
            gpio_put(LED_PIN, 1);

            for (int j = 0; j < 512; j++) {
                gpio_put(MOTOR_1, 1);
                sleep_ms(5);
                gpio_put(MOTOR_1, 0);

                gpio_put(MOTOR_2, 1);
                sleep_ms(5);
                gpio_put(MOTOR_2, 0);

                gpio_put(MOTOR_3, 1);
                sleep_ms(5);
                gpio_put(MOTOR_3, 0);

                gpio_put(MOTOR_4, 1);
                sleep_ms(5);
                gpio_put(MOTOR_4, 0);
                sleep_ms(5);
            }
        }
    }
}

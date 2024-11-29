// Copyright (c) 2022-2023 Cesanta Software Limited
// SPDX-License-Identifier: MIT

#include "hal.h"
#include "gps.h"

#define BLINK_PERIOD_MS 500  // LED blinking period in millis

#define gps_uart USART1
#define gps_baud 9600

uint32_t SystemCoreClock;  // Required by CMSIS. Holds system core cock value
void SystemInit(void) {    // Called automatically by startup code
    clock_init();            // Sets SystemCoreClock
    uart_init(USART1, 9600);
    uart_init(USART2, 9600);
}

static volatile uint64_t s_ticks;  // Milliseconds since boot
void SysTick_Handler(void) {       // SyStick IRQ handler, triggered every 1ms
  s_ticks++;
}

static void led_task(void) {  // Blink LED every BLINK_PERIOD_MS
  static uint64_t timer = 0;
  if (timer_expired(&timer, BLINK_PERIOD_MS, s_ticks)) {
    gpio_toggle(LED_PIN);
  }
}


void USART1_IRQHandler(void){
    gps_update_buffer();
}

int main(void) {
    gpio_output(LED_PIN);

    USART1->CR1 |= USART_CR1_RXNEIE_Msk;
    NVIC_SetPriority(USART1_IRQn, 22);
    NVIC_EnableIRQ(USART1_IRQn);

    for (;;) {
        led_task();
        update_gps_data();
        if (gps_is_new_data()){
            printf("%s \n", gps_get_time());
        }

    }

    return 0;
}

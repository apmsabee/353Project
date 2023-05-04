/*
 * timer32.c
 *
 *  Created on: Oct 5, 2020
 *      Author: YOUR NAME
 */

#include "timer32.h"

bool ALERT_S2_PRESSED = false;
bool UPDATE_LCD_SCREEN = false;

void initializeTimer32() {

    ece353_T32_1_Interrupt_Ms(10);
/*
    TIMER32_2->CONTROL = 0;
    TIMER32_2->CONTROL = 0x62; //second timer uses prescale 256
    TIMER32_2->LOAD = 2400000;

    NVIC_EnableIRQ(T32_INT2_IRQn);
    NVIC_SetPriority(T32_INT2_IRQn, 0);

    //turn the timers on
    TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE;
    TIMER32_2->CONTROL |= TIMER32_CONTROL_ENABLE;
    //when an interrupt is generated it can be read from the masked interrupt
    //status register which is under T32 registers in tech ref manual
*/
}

void T32_INT1_IRQHandler() {
   //frist debounce s2
  // static uint8_t debounce_status = 0x00;

   //debounce_status = debounce_status << 1;

   //if (ece353_staff_MKII_S2()) {
   //    debounce_status |= 0x01;
  // }

   //if (debounce_status == 0x7F) {
   //    ALERT_S2_PRESSED = true;
   //    debounce_status = 0x00;  //TODO: how to ensure user releases button
   //}
   //start an adc14 conversion
   ADC14->CTL0 |= ADC14_CTL0_SC | ADC14_CTL0_ENC;

   //clear interrupt
   TIMER32_1->INTCLR = 0;
}
/**
void T32_INT2_IRQHandler() {
   UPDATE_LCD_SCREEN = true;
   //clear interrupt
   TIMER32_2->INTCLR = 0;
}
*/

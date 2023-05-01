/*
 * task_accel.c
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "task_accel.h"
TaskHandle_t Task_Accel_Handle;


void Task_Accelerometer(void *pvParameters){
    uint32_t Accel_Direction = 0;
    while(1){
        //ADC14 is not currently configured, but we want to read the value stored in MEM[0]
        Accel_Direction = ADC14->MEM[0];
        //figure out if accelerometer is leaning left or right, take action based on that
    }
}

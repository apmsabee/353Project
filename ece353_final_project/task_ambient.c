/*
 * task_ambient.c
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "task_ambient.h"
#include "math.h"
TaskHandle_t Task_LightSensor_Handle;
volatile float lightValue = 0;
static bool lightsOn = true;

void Task_LightSensor(void *pvParameters){
    while(1){
        lightValue = opt3001_read_lux(); //store the value of the ambient light sensor in lux
        //need to use our lux reading to 1)change the color of the screen and 2) maybe the speed of the meteors?
        //task notification if lux reading has changed enough to change the screen color?
    }
}

float opt3001_read_lux(void)
{
    // Read the Result register of OPT3001 and convert into Lux, then return.
   uint16_t data = i2c_read_16(OPT3001_SLAVE_ADDRESS, RESULT_REG);
   uint16_t exponent = data | 0xF000;
   uint16_t fractional = data | 0x0FFF;

    return 0.01 * pow(2, exponent) * fractional;
}

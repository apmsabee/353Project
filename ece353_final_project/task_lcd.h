/*
 * task_lcd.h
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "msp432p401r.h"
#include "msp.h"
#include <main.h>

#ifndef TASK_LCD_H_
#define TASK_LCD_H_

extern TaskHandle_t Task_LCD_Handle;
void Task_LCD(void *pvParameters);



#endif /* TASK_LCD_H_ */

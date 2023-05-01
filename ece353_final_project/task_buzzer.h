/*
 * task_buzzer.h
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "msp432p401r.h"
#include "msp.h"
#include <main.h>

#ifndef TASK_BUZZER_H_
#define TASK_BUZZER_H_

extern TaskHandle_t Task_Buzzer_Handle;
void Task_Buzzer(void *pvParameters);

#endif /* TASK_BUZZER_H_ */

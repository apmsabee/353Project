/*
 * task_accel.h
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "msp432p401r.h"
#include "msp.h"
#include <main.h>

#ifndef TASK_ACCEL_H_
#define TASK_ACCEL_H_

extern TaskHandle_t Task_Accel_Handle;
void Task_Accelerometer(void *pvParameters);

#endif /* TASK_ACCEL_H_ */

/*
 * task_buzzer.c
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "task_buzzer.h"
#include "music.h"
TaskHandle_t Task_Buzzer_Handle;

void Task_Buzzer(void *pvParameters){
    uint32_t player_died;
    while(1) {
        //TODO: you need to GIVE this notification when a player dies
        player_died = ulTaskNotifyTake(true, portMAX_DELAY);
        music_play_song();

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void initBuzzer() {
    //Initialize Buzzer
        //initialize buzzer as output, set as primary function
        P2->DIR |= BIT7;
        P2->SEL0 |= BIT7;
        P2->SEL1 &= ~BIT7;
}

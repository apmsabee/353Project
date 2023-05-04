/*
 * task_player.c
 *
 *  Created on: May 3, 2023
 *      Author: cschlueter
 */

#include "task_player.h"

TaskHandle_t Task_Player_Handle;
QueueHandle_t Queue_Player;

void Task_Move_Player(void *pvParameters) {
    static int player_x = 64;
    ACCEL_DIR_t dir;

    while(1) {

        xQueueReceive(Queue_Player, &dir, portMAX_DELAY);

        if (dir == ACCEL_CENTER) {
            lcd_draw_image(
               player_x,
               117,
               personWidthPixels,
               personHeightPixels,
               personBitmaps,
               LCD_COLOR_MAGENTA,
               LCD_COLOR_WHITE);
        } else if (dir == ACCEL_LEFT) {
            if (player_x > personWidthPixels / 2)
                player_x--;
            lcd_draw_image(
                           player_x,
                           117,
                           personWidthPixels,
                           personHeightPixels,
                           personBitmaps,
                           LCD_COLOR_MAGENTA,
                           LCD_COLOR_WHITE);

        } else {
            if (player_x < LCD_HORIZONTAL_MAX - personWidthPixels)
                player_x++ % LCD_HORIZONTAL_MAX;
            lcd_draw_image(
               player_x,
               117,
               personWidthPixels,
               personHeightPixels,
               personBitmaps,
               LCD_COLOR_MAGENTA,
               LCD_COLOR_WHITE);
        }



    }

    lcd_draw_image(
                player_x,
                117,
                personWidthPixels,
                personHeightPixels,
                personBitmaps,
                LCD_COLOR_MAGENTA,
                LCD_COLOR_WHITE);
}



/*
 * task_meteor.c
 *
 *  Created on: May 4, 2023
 *      Author: cschlueter
 */

#include "task_meteor.h"

TaskHandle_t Task_Meteor_Handle;

extern uint16_t background_color;
uint16_t meteor_color = LCD_COLOR_RED;

void  Task_Move_Meteors(void *pvParameters) {
    int meteor_y;
    int meteor_x = 64;
    time_t t;
    srand( (unsigned) time(&t) );

    while (1) {
       meteor_y = 17;
       meteor_x = rand() % (LCD_HORIZONTAL_MAX - meteorWidthPixels);
       meteor_x += meteorWidthPixels / 2;
        while(1) {
            lcd_draw_image(
            meteor_x,
            meteor_y++,
            meteorWidthPixels,
            meteorHeightPixels,
            meteorBitmaps,
            meteor_color,
            background_color);
            vTaskDelay(pdMS_TO_TICKS(50));

            if (meteor_y > LCD_VERTICAL_MAX - (meteorHeightPixels / 2)) {

                lcd_draw_rectangle(
                            meteor_x,
                            meteor_y,
                            meteorWidthPixels,
                            meteorHeightPixels + 10,
                            background_color);
                break;
            }
        }


    }

}


/*
void clearPlayerSpace() {
    uint32_t eventOccurred;
        while(1){
            eventOccurred = ulTaskNotifyTake(true, portMAX_DELAY);
            lcd_draw_rectangle(
                            64,
                            117,
                            132,
                            personHeightPixels,
                            LCD_COLOR_WHITE);
        }
}
*/



/*
 * init.c
 *
 *  Created on: Apr 27, 2023
 *      Author: apmcavoy
 */
#include "init.h"

/*
 * Initializes the peripherals used in this project
 * Need the LCD, Ambient Light Sensor, Buzzer, Accelerometer,
 * and maybe the MKII buttons and Timers
 * ALS and Accelerometer will both be done through the ADC I believe
 */
void init_board(){
//initialize LCD
    // LCD_SCK
    LCD_SCK_PORT->SEL0 |= LCD_SCK_PIN;
    LCD_SCK_PORT->SEL1 &= ~LCD_SCK_PIN;

    // LCD_MOSI
    LCD_MOSI_PORT->SEL0 |= LCD_MOSI_PIN;
    LCD_MOSI_PORT->SEL1 &= ~LCD_MOSI_PIN;

    // LCD_CS
    LCD_CS_PORT->DIR |= LCD_CS_PIN;

    // LCD_RST
    LCD_RST_PORT->DIR |= LCD_RST_PIN;

    // LCD_DC
    LCD_DC_PORT->DIR |= LCD_DC_PIN;


//Initialize Buzzer
    //initialize buzzer as output, set as primary function
    P2->DIR |= BIT7;
    P2->SEL0 |= BIT7;
    P2->SEL1 &= ~BIT7;
/* Not sure if we need these in the init function
    //stop timer
    TIMER_A0->CTL = 0;
    //load timer_A with given period
    TIMER_A0->CCR[0] = ticks_period - 1;
    //we want a 50% duty cycle, so load half of given period into CCR[4] for buzzer
    TIMER_A0->CCR[4] = (ticks_period/2) - 1;
    //set timer to be Reset/Set mode
    TIMER_A0->CCTL[4] = TIMER_A_CCTLN_OUTMOD_7;
    //set timer to run based off of the system clock
    TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK;
*/

//Initialize Ambient Light Sensor
    // Initialize OPT3001
    i2c_write_16(OPT3001_SLAVE_ADDRESS, CONFIG_REG, 0xC610);

//Initialize Accelerometer
    //I think doing this in window comparator mode would be easier - if it's tilted to the left, go left at a constant speed, same for tilted right. Not sure though
}

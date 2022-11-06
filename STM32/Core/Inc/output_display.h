/*
 * output_display.h
 *
 *  Created on: Oct 23, 2022
 *      Author: LENOVO
 */

#include "fsm_simple_buttons_run.h"
#include "main.h"
#include "software_timer.h"
#include "global.h"

#ifndef INC_OUTPUT_DISPLAY_H_
#define INC_OUTPUT_DISPLAY_H_

extern int led_buffer;

void display7SEG(int num);
void update7SEG(int index);
void LedBlinky();

#endif /* INC_OUTPUT_DISPLAY_H_ */

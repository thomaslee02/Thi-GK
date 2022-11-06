/*
 * fsm_automatic.c
 *
 *  Created on: Oct 4, 2022
 *      Author: LENOVO
 */


#include "fsm_simple_buttons_run.h"

void fsm_simple_buttons_run() {

	switch (status) {
		case INIT:
			update7SEG(led_buffer);
			status = NORMAL_PRESSED;
			setTimer1(10000);
			break;

		case NORMAL_PRESSED:
			if (timer1_flag) {
				status = AUTO;
				if (led_buffer > 0) {
					update7SEG(--led_buffer);
					setTimer1(1000);
				}
			}
			if (isButtonPressed(0) || isButtonLPressed(0)) status = RESET_STATE;
			if (isButtonPressed(1)) status = COUNT_UP;
			if (isButtonLPressed(1)) status = AUTO_COUNT_UP;
			if (isButtonPressed(2)) status = COUNT_DOWN;
			if (isButtonLPressed(2)) status = AUTO_COUNT_DOWN;
			break;

		case RESET_STATE:
			status = NORMAL_PRESSED;
			led_buffer = 0;
			update7SEG(led_buffer);
			setTimer1(10000);
			break;

		case COUNT_UP:
			if (led_buffer >= 9) led_buffer = -1;
			update7SEG(++led_buffer);
			status = NORMAL_PRESSED;
			setTimer1(10000);
			break;

		case COUNT_DOWN:
			if (led_buffer <= 0) led_buffer = 10;
			update7SEG(--led_buffer);
			status = NORMAL_PRESSED;
			setTimer1(10000);
			break;

		default:
			break;
	}
}

/*
 * fsm_count.c
 *
 *  Created on: Nov 5, 2022
 *      Author: LENOVO
 */

#include "fsm_count.h"

void fsm_count_run() {
	switch(status) {
		case AUTO_COUNT_UP:
			if (timer1_flag) {
				if (led_buffer >= 9) led_buffer = -1;
				update7SEG(++led_buffer);
				setTimer1(1000);
			}
			if (!isButtonLPressed(1)) {
				status = NORMAL_PRESSED;
				setTimer1(10000);
			}
			break;

		case AUTO_COUNT_DOWN:
			if (timer1_flag) {
				if (led_buffer <= 0) led_buffer = 10;
				update7SEG(--led_buffer);
				setTimer1(1000);
			}
			if (!isButtonLPressed(2)) {
				status = NORMAL_PRESSED;
				setTimer1(10000);
			}
			break;

		case AUTO:
			if (timer1_flag) {
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
		default:
			break;
	}
}

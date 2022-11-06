/*
 * output_display.c
 *
 *  Created on: Oct 23, 2022
 *      Author: LENOVO
 */


#include "output_display.h"

int led_buffer = 0;

void display7SEG(int num) {
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg1_Pin|seg2_Pin|seg3_Pin|seg4_Pin|seg5_Pin, RESET);
			HAL_GPIO_WritePin(seg6_GPIO_Port, seg6_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg3_Pin|seg4_Pin|seg5_Pin|seg6_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, seg1_Pin|seg2_Pin, RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg3_Pin|seg4_Pin|seg1_Pin|seg6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, seg5_Pin|seg2_Pin, SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg3_Pin|seg1_Pin|seg2_Pin|seg6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, seg4_Pin|seg5_Pin, SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg3_Pin|seg4_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, seg1_Pin|seg2_Pin|seg5_Pin|seg6_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg3_Pin|seg2_Pin|seg5_Pin|seg6_Pin, RESET);
			HAL_GPIO_WritePin(GPIOA, seg1_Pin|seg4_Pin, SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg2_Pin|seg3_Pin|seg4_Pin|seg5_Pin|seg6_Pin, RESET);
			HAL_GPIO_WritePin(seg1_GPIO_Port, seg1_Pin, SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOA, seg3_Pin|seg4_Pin|seg5_Pin|seg6_Pin, SET);
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg1_Pin|seg2_Pin, RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg1_Pin|seg2_Pin|seg3_Pin|seg4_Pin|seg5_Pin|seg6_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOA, seg0_Pin|seg1_Pin|seg2_Pin|seg3_Pin|seg5_Pin|seg6_Pin, RESET);
			HAL_GPIO_WritePin(seg4_GPIO_Port, seg4_Pin, SET);
			break;
	}
}

void update7SEG (int led_buffer) {
	HAL_GPIO_WritePin(q0_GPIO_Port, q0_Pin, RESET);
	display7SEG(led_buffer);
}

void LedBlinky() {
	if (timer5_flag == 1) {
		HAL_GPIO_TogglePin(led_GPIO_Port, led_Pin);
		setTimer5(1000);
	}
}

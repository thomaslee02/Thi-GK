/*
 * button.c
 *
 *  Created on: Sep 27, 2022
 *      Author: LENOVO
 */

#include "button.h"

int TimeOutForKeyPress[3] = {300,300,300};

int button_flag[3] = {0,0,0};

int flagForLPress[3] = {0,0,0};

int KeyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

uint16_t Pin[3] = {button0_Pin, button1_Pin, button2_Pin};

int isButtonPressed(int i) {
	if (button_flag[i]) {
		button_flag[i] = 0;
		return 1;
	}
	return 0;
}

int isButtonLPressed(int i) {
	if (flagForLPress[i]) {
		flagForLPress[i] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int i) {
	// Set value
	button_flag[i] = 1;
}

void getKeyInput() {
	// Pressed
	for (int i = 0; i < 3; i++) {
		KeyReg0[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg2[i];
		KeyReg2[i] = HAL_GPIO_ReadPin(GPIOA, Pin[i]);

		if ((KeyReg0[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg3[i] != KeyReg2[i]) {
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg2[i] == PRESSED_STATE) {
					if (!flagForLPress[i]) {
						TimeOutForKeyPress[i] = 300;
						subKeyProcess(i);
					}
					else TimeOutForKeyPress[i] = 100;
				}
				else flagForLPress[i] = 0;
			}
			else {
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0) {
					if (KeyReg2[i] == PRESSED_STATE) {
						flagForLPress[i] = 1;
						TimeOutForKeyPress[i] = 0;
						KeyReg3[i] = NORMAL_STATE;
					}
				}
			}
		}
	}
}


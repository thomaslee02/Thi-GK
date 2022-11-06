/*
 * button.h
 *
 *  Created on: Sep 27, 2022
 *      Author: LENOVO
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

extern int button_flag[3];

int isButtonPressed(int button_flag);
int isButtonLPressed(int i);
void subKeyProcess(int i);
void getKeyInput();

#endif /* INC_BUTTON_H_ */

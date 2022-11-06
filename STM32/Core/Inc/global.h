/*
 * global.h
 *
 *  Created on: Oct 4, 2022
 *      Author: LENOVO
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "button.h"
#include "software_timer.h"

#define INIT 0
#define RESET_STATE 1
#define COUNT_UP 2
#define COUNT_DOWN 3
#define NORMAL_PRESSED 4

#define AUTO_COUNT_UP 12
#define AUTO_COUNT_DOWN 13
#define AUTO 14

#define TIMER_BUTTON 0
#define TIMER_SOFTWARE 5

extern int status;

#endif /* INC_GLOBAL_H_ */

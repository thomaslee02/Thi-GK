/*
 * software_timer.h
 *
 *  Created on: Oct 23, 2022
 *      Author: LENOVO
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer1_count;
extern int timer2_flag;
extern int timer2_count;
extern int timer3_flag;
extern int timer3_count;
extern int timer4_flag;
extern int timer4_count;
extern int timer5_flag;
extern int timer5_count;

void setTimer1(int duration);
void setTimer2(int duraiton);
void setTimer3(int duration);
void setTimer4(int duration);
void setTimer5(int duration);
void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */

/*
 * use.h
 *
 *  Created on: Mar 27, 2026
 *      Author: Lenovo
 */

#ifndef INC_USER_H_
#define INC_USER_H_

#include "stm32l4xx.h"

#define MOTOR_WHEEL_SEPARATION 0.1;

void move_motor1_forward();

void move_motor1_backward();

void move_motor2_forward();

void move_motor2_backward();

void move_sima_forward();

void move_sima_backward();

void rotate_sima_left();

void rotate_sima_right();

void calculate_steps_from_angle(uint32_t angle);

void user();

#endif /* INC_USER_H_ */

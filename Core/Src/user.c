/*
 * user.c
 *
 *  Created on: Mar 27, 2026
 *      Author: Lenovo
 */

#include "user.h"
#include <math.h>

uint8_t flg_moving = 0;
uint32_t precnik_tocka = 70;

typedef enum{
	KorakA, KorakB, KorakC, KorakD, KorakE, KorakF, KorakG, // Dodati jos po potrebi
}Enum_States;

Enum_States Koraci;

void user(){

	switch(Koraci)
	{
		case(KorakA):
		{
			//Ovde pisati kako da se krece sima u koraku (npr move_sima_forward(zeljeni put koji zelis da predje)
			break;
		}
		case(KorakB):
				{
					//Ovde pisati kako da se krece sima u koraku (npr move_sima_forward(zeljeni put koji zelis da predje)
					break;
				}
		case(KorakC):
				{
					//Ovde pisati kako da se krece sima u koraku (npr move_sima_forward(zeljeni put koji zelis da predje)
					break;
				}
		case(KorakD):
				{
					//Ovde pisati kako da se krece sima u koraku (npr move_sima_forward(zeljeni put koji zelis da predje)
					break;
				}
		case(KorakE):
				{
					//Ovde pisati kako da se krece sima u koraku (npr move_sima_forward(zeljeni put koji zelis da predje)
					break;
				}
		case(KorakF):
				{
					//Ovde pisati kako da se krece sima u koraku (npr move_sima_forward(zeljeni put koji zelis da predje)
					break;
				}
	}
}

void move_motor1_forward(uint32_t step_number)
{

		GPIOA->ODR |= (1 << 1);

		for(int i = 1; i <= step_number; i++)
		{
			GPIOA->ODR |= (1 << 7);
			HAL_Delay(1);
			GPIOA->ODR &= ~(1 << 7);
			HAL_Delay(1);
		}
//	}
}

void move_motor1_backward(uint32_t step_number)
{
//	if(flg_moving)
//		return;
//	else
//	{
		GPIOA->ODR &= ~(1 << 1);

		for(int i = 1; i <= step_number; i++)
		{
			GPIOA->ODR |= (1 << 7);
			HAL_Delay(1);
			GPIOA->ODR &= ~(1 << 7);
			HAL_Delay(1);
		}
//	}
}

void move_motor2_forward(uint32_t step_number)
{
	GPIOA->ODR |= (1 << 3);

	for(int i = 1; i <= step_number; i++)
	{
		GPIOA->ODR |= (1 << 2);
		HAL_Delay(10);
		GPIOA->ODR &= ~(1 << 2);
		HAL_Delay(10);
	}
}

void move_motor2_backward(uint32_t step_number)
{
	GPIOA->ODR &= ~(1 << 3);

	for(int i = 1; i <= step_number; i++)
	{
		GPIOA->ODR |= (1 << 2);
		HAL_Delay(10);
		GPIOA->ODR &= ~(1 << 2);
		HAL_Delay(10);
	}
}

void move_sima_forward(uint32_t distance)
{
	move_motor1_forward(calculate_steps_from_distance(distance));
	move_motor2_forward(calculate_steps_from_distance(distance));
}

void move_sima_backward(uint32_t distance)
{
	move_motor1_backward(calculate_steps_from_distance(distance));
	move_motor2_backward(calculate_steps_from_distance(distance));
}

void rotate_sima_left(uint32_t angle)
{
	move_motor1_backward(calculate_steps_from_angle(angle));
	move_motor2_forward(calculate_steps_from_angle(angle));
}

void rotate_sima_right(uint32_t angle)
{
	move_motor1_backward(calculate_steps_from_angle(angle));
	move_motor2_forward(calculate_steps_from_angle(angle));
}

void calculate_steps_from_angle(uint32_t angle)
{
	int br_stepova;
	br_stepova = angle/1.8;
	br_stepova /= 2;
	return br_stepova;
}

void calculate_steps_from_distance(uint32_t distance)
{
	//distance = br_obrtaja*precnik
	// obrtaj = 360/1.8
	uint32_t br_obrtaja;
	br_obrtaja = distance/precnik;
	br_obrtaja = br_obrtaja*360/1.8;
	return br_obrtaja;

}

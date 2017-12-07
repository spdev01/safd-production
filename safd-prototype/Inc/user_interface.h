/*
 * user_interface.h
 *
 *  Created on: Dec 6, 2017
 *      Author: Schwin
 */

#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

#include "ssd1306.h"
#include "stm32l4xx_hal.h"
#include "font5x7.h"
#include "font7x10.h"

typedef struct frame
{
	uint8_t previous;
	uint8_t next;
	uint8_t parent;
	uint8_t child;
	uint8_t a_index;
	uint8_t b_index;
	void (* a_action)(void);
	void (* b_action)(void);
	char* a_string;
	char* b_string;
	char* main_msg;
	char* sub_msg;

}frame;

frame frame_lookup[10];
int current_frame_index;



void init_userinterface();
void to_child();
void stay();
void to_root();
void to_parent();
void delayed_to_root(int sec);
void turn_off();
void refresh_oled();
void to_next();
void to_prev();

#endif /* USER_INTERFACE_H_ */

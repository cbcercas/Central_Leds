/*
Central LEDs A Central to manage all room ledstrip
Copyright (C) 2017  Christopher BRAVO CERCAS

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HEADER_H
# define HEADER_H

# define _TASK_LTS_POINTER
# define _TASK_WDT_IDS
# include <TaskScheduler.h>
# include <Arduino.h>

//#define DELAY_WC 60000

# define CORRIDOR_LED_NUM 82
# define CORRIDOR_LED_PIN 4
//# define CORRIDOR_LED_TYPE WS2811
//# define CORRIDOR_LED_COLOR BRG
//# define CORRIDOR_MOTION_PIN 3
# define CORRIDOR_DELAY 5000

typedef struct s_room		t_room;
struct						s_room
{
	volatile bool			state;
	volatile unsigned long	time;
	uint8_t					led_pin;
	uint8_t					led_num;
	unsigned long			delay;
	Task					*timer;
};

/*
 * interrupt.cpp
 */
void	int_corridor(void);

/*
 * room.cpp
 */
t_room*	setup_rooms(void);

/*
 * Generic timer loop for room
 */
void	timer_loop(void);

#endif

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

#include "header.h"

extern t_room		*g_corridor;
extern Scheduler	runner;
extern Task timer_corridor;

static t_room	*room_create(unsigned long delay, uint8_t led_pin, uint8_t led_num)
{
	t_room	*room;

	room = (t_room *)malloc(sizeof(*room));
	bzero(room, sizeof(*room));
	room->delay = delay;
	room->led_pin = led_pin;
	room->led_num = led_num;
	return (room);
}

t_room*	setup_rooms(void)
{
	g_corridor = room_create(CORRIDOR_DELAY, CORRIDOR_LED_PIN, CORRIDOR_LED_NUM);

	runner.addTask(timer_corridor);
	timer_corridor.setLtsPointer(g_corridor);
}
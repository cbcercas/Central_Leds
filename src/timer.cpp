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

Scheduler runner;

Task timer_corridor(TASK_SECOND, TASK_FOREVER, &timer_loop, &runner);

void	timer_loop(void)
{
	t_room	*room;

	room = (t_room *)runner.currentLts();

	Serial.println(millis() - room->time);

	if ((millis() - room->time) < room->delay)
	{
		Serial.println("Do nothing");
		return ;
	}
	Serial.println("turn OFF corridor leds");
	room->state = false;
	room->time  = 0;
	timer_corridor.disable();
	//TODO turn off leds;
}

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

#include <Arduino.h>
#include <HardwareSerial.h>
#include "header.h"

extern t_room *g_corridor;
extern Task timer_corridor;

void	int_corridor(void)
{
	if (g_corridor->state)
	{
		g_corridor->time = millis();
		return;
	}
	Serial.println("turn ON corridor leds");
	g_corridor->state = true;
	g_corridor->time = millis();
	//TODO turn on leds
	timer_corridor.restart();
}

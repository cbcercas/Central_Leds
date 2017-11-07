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

#include <ESP8266WiFi.h>

#include "header.h"

t_room	*g_corridor;
//t_room	*g_wc;

extern Scheduler runner;
extern Task timer_corridor;

void setup() {
	// Ouverture du port serie en 115200 baud pour envoyer des messages de debug à l'ide par exemple
	Serial.begin(9600);
	delay(10);


	runner.init();
	setup_rooms();
	attachInterrupt((uint8_t)digitalPinToInterrupt(g_corridor->led_pin), int_corridor, RISING);

	Serial.println("Setup done");


}

void loop()
{
	while (1)
	{
		runner.execute();
		delay(150);
	}
}
/*
 Name:		BatteryChargeIndicatorRGB.ino
 Created:	1/10/2023 9:12:08 AM
 Author:	Imami Joel Betofe
*/

#include "ArduinoC.h"
Setting Setting_main;
// the setup function runs once when you press reset or power the board
void setup() {

	Serial.begin(115200);
	Setting_main.init();


}

// the loop function runs over and over again until power down or reset
void loop() {
	Setting_main.run();
}

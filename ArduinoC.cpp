// 
// 
// 

#include "ArduinoC.h"

void Setting::init() {


	// kalman variables
	varVolt = 1.12184278324081E-05;  // variance determined using excel and reading samples of raw sensor data
	varProcess = 1e-8;
	Pc = 0.0;
	G = 0.0;
	P = 1.0;
	Xp = 0.0;
	Zp = 0.0;
	Xe = voltage;
	sensorVal = analogRead(sensorPin);     // read the value on AnalogIn pin 0 and store it in a variable
	voltage = (((sensorVal * 5) / 1023));



}
void Setting::run() {
	// Measures the value of the potentiometer
	int sensorVal = analogRead(sensorPin);     // read the value on AnalogIn pin 0 and store it in a variable
	float voltage = (((sensorVal * 5) / 1023));  // convert the ADC reading to voltage

	// Serial.println(voltage);

	  // kalman process
	Pc = P + varProcess; //Predict the next variance
	G = Pc / (Pc + varVolt);    // Computer the kalman gain
	P = (1 - G) * Pc; // Update variance estimation
	Xp = Xe; // Predict the next state
	Zp = Xp; // Predict the next state
	Xe = G * (voltage - Zp) + Xp;   // Update the Kalman state estimation
	z = map(Xe, 0, 5, 0, 100);
	Serial.println(voltage);
	delay(200);


	if (z >= 70 && z <= 100) {
		digitalWrite(LedOneRPin, HIGH);
		digitalWrite(LedTwoRPin, HIGH);
		digitalWrite(LedThreeRPin, HIGH);

		//digitalWrite(LedOneBPin, LOW);
		//digitalWrite(LedTwoBPin, LOW);
		//digitalWrite(LedThreeBPin, LOW);

		//digitalWrite(LedOneGPin, LOW);
		//digitalWrite(LedTwoGPin, LOW);
		//digitalWrite(LedThreeGPin, LOW);
		delay(200);
	}

	else if (z >= 50 && z < 70) {
		digitalWrite(LedOneGPin, HIGH);
		digitalWrite(LedTwoGPin, HIGH);
		digitalWrite(LedThreeGPin, HIGH);

	/*	digitalWrite(LedOneRPin, LOW);
		digitalWrite(LedTwoRPin, LOW);
		digitalWrite(LedThreeRPin, LOW);

		digitalWrite(LedOneBPin, LOW);
		digitalWrite(LedTwoBPin, LOW);
		digitalWrite(LedThreeBPin, LOW);*/
		delay(200);

	}
	else if (z >= 0 && z < 50) {
		digitalWrite(LedOneBPin, HIGH);
		digitalWrite(LedTwoBPin, HIGH);
		digitalWrite(LedThreeBPin, HIGH);

		//digitalWrite(LedOneRPin, LOW);
		//digitalWrite(LedTwoRPin, LOW);
		//digitalWrite(LedThreeRPin, LOW);

		//digitalWrite(LedOneGPin, LOW);
		//digitalWrite(LedTwoGPin, LOW);
		//digitalWrite(LedThreeGPin, LOW);
		delay(200);
	}



}
// ArduinoC.h
#pragma once

#include <Arduino.h>
#include <EEPROM.h>
#define EEPROM_SIZE 1

class Setting {
private:
	const int sensorPin = A0;
	const int LedOneRPin = 3; 
	const int LedOneGPin = 4;
	const int LedOneBPin = 5;

	const int LedTwoRPin = 6;
	const int LedTwoGPin = 7;
	const int LedTwoBPin = 8;

	const int LedThreeRPin = 10;
	const int LedThreeGPin = 11;
	const int LedThreeBPin = 12;

	float varVolt; // variance determined using excel and reading samples of raw sensor data
	float varProcess; //variance Process
	float Pc; // Next variance predictor
	float G; // Kalman Gain
	float P; // update variance estimator
	float Xp; // Next state predictor
	float Zp; // Next state predictor
	float Xe; // Kalman Estimator
	float voltage;
	int sensorVal;
	
	
	int z; //voltage in percentage
public:
	void init();
	void run();
};
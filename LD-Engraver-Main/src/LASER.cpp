/*
 * LASER.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: debian
 */


#include "LASER.h"
#include "LDE.h"

bool IsRunning;
bool IsON;
int currentLevel = 0;

GPIO *Laser_Master_Relais;
GPIO *Laser_Driver_PSU;
GPIO *Laser_Peltier_PSU;
GPIO *Laser_Diode_PSU;
GPIO *Laser_Fan;

GPIO *LaserSequence[5] = {Laser_Master_Relais, Laser_Fan, Laser_Peltier_PSU, Laser_Driver_PSU, Laser_Diode_PSU };

DAC *dac;

int laser_Init() {
	IsON = false;
	IsRunning = false;
	// Level à 0
	currentLevel = 0;
	Laser_Master_Relais = new GPIO(LASER_MASTER_RELAIS);
	Laser_Driver_PSU = new GPIO(LASER_DRIVER_PSU);
	Laser_Peltier_PSU = new GPIO(LASER_PELTIER_PSU);
	Laser_Diode_PSU = new GPIO(LASER_DIODE_PSU);
	Laser_Fan = new GPIO(LASER_FAN);
	// D'abord les commandes des relais pour éviter déclenchement (doivent être LOW)
	Laser_Diode_PSU->setDirection(GPIO::OUTPUT);
	Laser_Diode_PSU->setValue(GPIO::LOW);
	Laser_Driver_PSU->setDirection(GPIO::OUTPUT);
	Laser_Driver_PSU->setValue(GPIO::LOW);
	Laser_Peltier_PSU->setDirection(GPIO::OUTPUT);
	Laser_Peltier_PSU->setValue(GPIO::LOW);
	Laser_Driver_PSU->setDirection(GPIO::OUTPUT);
	Laser_Driver_PSU->setValue(GPIO::LOW);
	Laser_Master_Relais->setDirection(GPIO::OUTPUT);
	Laser_Master_Relais->setValue(GPIO::LOW);

	return 1;
}

int laser_SetLevel(int level) {
	if ((level < 0) || (level > 255)) return LASER_ERROR_02;
	if (level == currentLevel) return level;
	currentLevel = level;
	return 1;
}

int laser_GetLevel() {
	return currentLevel;
}

int p_laser_ForceLevel(int level) {
	// force level, en cas de problème
	currentLevel = level;
	return level;
}

int laser_Alimentation_ON() {
	// shutdown laser power
	p_laser_ForceLevel(0);
	for (int i = 0; i < 5; i++) {
		LaserSequence[i]->setValue(GPIO::LOW);
		// Tempo
		usleep(LASER_DELAY_SEQUENCE);
	}
	IsON = true;
	return 1;
}

int laser_Alimentation_OFF() {
	// shutdown laser power
	p_laser_ForceLevel(0);
	for (int i = 4; i < 0; i++) {
		LaserSequence[i]->setValue(GPIO::LOW);
		// Tempo
		usleep(LASER_DELAY_SEQUENCE);
	}
	IsON= true;
	IsRunning = false;
	return 1;
}

int p_setLaserPower(int level) {
	if (level == currentLevel) return level;
	currentLevel = level;
	return level;
}

int laser_ON() {
	if (IsON == false) return LASER_ERROR_01;
	IsRunning = true;
	return p_setLaserPower(currentLevel);
}

int laser_ON(int level) {
	if (IsON == false) return LASER_ERROR_01;
	IsRunning = true;
	return p_setLaserPower(level);
}

int laser_OFF() {
	if (IsON == false) return LASER_ERROR_01;
	IsRunning = false;
	return p_setLaserPower(0);
}

int laser_EmergencyStop() {
	p_laser_ForceLevel(0);
	for (int i = 4; i < 0; i++) {
		LaserSequence[i]->setValue(GPIO::LOW);
		// pas de tempo
	}
	IsRunning = false;
	IsON = false;
	return 1;
}




float laser_Temp() {
		// resistance at 25 degrees C
		#define THERMISTORNOMINAL 10000  // 10K
		// temp. for nominal resistance (almost always 25 C)
		#define TEMPERATURENOMINAL 25
		// how many samples to take and average, more takes longer
		// but is more 'smooth'
		#define NUMSAMPLES 10
		// The beta coefficient of the thermistor (usually 3000-4000)
		#define BCOEFFICIENT 3950
		// the value of the 'other' resistor
		#define SERIESRESISTOR 9870

		static uint8_t i;
		static float average = 0.0;
		static float steinhart = 0.0;

		// take N samples in a row, with a slight delay
		average = 0;
		for (i = 0; i< NUMSAMPLES; i++) {
			//average += analogRead(pinNumber);
			usleep(10000);
		}
		average /= NUMSAMPLES;
		average = 1023 / average - 1;
		average = SERIESRESISTOR / average;
		steinhart = average / THERMISTORNOMINAL;     // (R/Ro)
		steinhart = log(steinhart);                  // ln(R/Ro)
		steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
		steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
		steinhart = 1.0 / steinhart;                 // Invert
		steinhart -= 273.15;                         // convert to C
		return steinhart;
}

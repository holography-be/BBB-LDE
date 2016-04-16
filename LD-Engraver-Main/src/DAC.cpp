/*
 * DAC.cpp
 *
 *  Created on: Apr 16, 2016
 *      Author: debian
 */

#include "DAC.h"
#include "util.h"

DAC::DAC() {
	// TODO Auto-generated constructor stub
	initI2C();
	currentLevel = 0;
	setLevel(0);
}

DAC::~DAC() {
	// TODO Auto-generated destructor stub
}

void DAC::initI2C() {

}

unsigned char DAC::setLevel(unsigned char level) {
	if (level == this->currentLevel) {
		return this->currentLevel;
	}
/*	if ((level < 0) || (level > 255)) {
		return this->currentLevel;
	}*/
	sendI2C(volt[level]);
	return level;
}

void DAC::sendI2C(unsigned short int level) {

}

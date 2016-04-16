/*
 * LASER.h
 *
 *  Created on: Apr 16, 2016
 *      Author: debian
 */

#ifndef LASER_H_
#define LASER_H_

#include "pins.h"
#include "DAC.h"

class LASER {
public:
	LASER();
	virtual ~LASER();
	int setLevel(int level);
	void start();
	void stop();
	void emergencyStop();

private:
	DAC *dac;


};

#endif /* LASER_H_ */

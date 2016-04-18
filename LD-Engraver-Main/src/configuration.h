/*
 * configuration.h
 *
 *  Created on: Apr 15, 2016
 *      Author: debian
 */


#ifndef CONFIGURATION_H

#include "pins.h"

#define CONFIGURATION_H

// Laser
#define MAX_LASER_TEMP			35
#define LASER_DELAY_SEQUENCE	500000		// delais entre les étapes start/stop (en microseconde - 1 milli = 1000 micro)

// Security check interval
#define SecurityCheck			1			//en seconde

// Travel limits after homing
#define X_MAX_POS 500
#define X_MIN_POS 0
#define Y_MAX_POS 500
#define Y_MIN_POS 0
#define Z_MAX_POS 200
#define Z_MIN_POS 0

#define UDP_PORT_LISTENER		9000		// port pour communication TCP
#define BAUDRATE				115200		// Serial Speed



#endif


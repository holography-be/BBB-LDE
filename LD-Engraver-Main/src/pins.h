/*
 * pins.h
 *
 *  Created on: Apr 15, 2016
 *      Author: debian
 */

#ifndef PINS_H

#define PINS_H

// Pins pour moteurs (must be available in PRU) : Debug seulement !
#define X_DIR				86		// P8_27
#define X_STEP				88		// P8_28
#define X_ENABLE			87		// P8_29
#define Y_DIR				89		// P8_30
#define Y_STEP				76		// P8_39
#define Y_ENABLE			77		// P8_40
#define Z_DIR				74		// P8_41
#define Z_STEP				75		// P8_42
#define Z_ENABLE			72		// P8_43
#define A_DIR				73		// P8_44
#define A_STEP				70		// P8_45
#define A_ENABLE			71		// P8_46

// Pins pour Laser (Commandes Relais)
#define	LASER_MASTER_RELAIS	10		// P8_31
#define LASER_DRIVER_PSU	11		// P8_32
#define LASER_PELTIER_PSU	9		// P8_33
#define LASER_DIODE_PSU		81		// P8_34
#define LASER_FAN			8		// P8_35

// Pins pour END-STOP (Interrupt via I2C)
#define ENDSTOP_INTERRUPT	80		// P8_36		INPUT_MODE

// Bits pour END_STOP & INTERLOCK
#define X_MAX_BIT		0
#define	X_MIN_BIT		1
#define Y_MAX_BIT		2
#define	Y_MIN_BIT		3
#define	Z_MAX_BIT		4
#define Z_MIN_BIT		5
#define INTERLOCK_BIT	6



#endif



/*
 * LASER.h
 *
 *  Created on: Apr 16, 2016
 *      Author: debian
 */

#ifndef LASER_H_
#define LASER_H_

#include "LDE.h"
#include "DAC.h"



int laser_Init();
int laser_SetLevel(int level);
int laser_GetLevel();
void laser_Start();
void laser_Stop();
void laser_EmergencyStop();
float laser_Temp();


#endif /* LASER_H_ */

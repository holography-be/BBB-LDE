//
// LDE-Main.cpp
//
// Master file
//


#include "LDE.h"
#include "LASER.h"

#include <iostream>
/**
 *
 */

using namespace std;

void emergencyStop() {
	laser_EmergencyStop();
	cout << "EMERGENCY STOP." << endl;

	for (;;) {}
}

void init() {
	laser_Init();

}

void masterLoop() {
	for (;;) {

	}
}

int main() {
	unsigned char level = 10;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	cout << volt[level] <<endl;
	cout << "Initialisation" << endl;
	init();
	//masterLoop();
	//GPIO *led = new GPIO(15);

	return 0;  // never reached
}



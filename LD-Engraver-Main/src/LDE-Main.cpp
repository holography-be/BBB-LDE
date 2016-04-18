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

int emergencyStop() {
	laser_EmergencyStop();
	return 1;
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
	//init();
	//masterLoop();
	GPIO *led = new GPIO(15);

	return 0;  // never reached
}



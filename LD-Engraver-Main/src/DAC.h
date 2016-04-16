/*
 * DAC.h
 *
 *  Created on: Apr 16, 2016
 *      Author: debian
 *
 *
 */

#ifndef DAC_H_
#define DAC_H_

class DAC {

private:
	unsigned char currentLevel;
	unsigned char realLevel;

public:
	DAC();
	virtual ~DAC();
	unsigned short int test;

	unsigned char setLevel(unsigned char level);
	unsigned char getLevel() { return currentLevel;  };
private:
	void initI2C();
	void sendI2C(unsigned short int level);

};

#endif /* DAC_H_ */

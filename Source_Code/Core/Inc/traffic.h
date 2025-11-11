/*
 * traffic.h
 *
 *  Created on: Nov 10, 2025
 *      Author: LENOVO
 */

#ifndef INC_TRAFFIC_H_
#define INC_TRAFFIC_H_

#include "global.h"

// LED set 1
void turnOnRed1(void);
void turnOffRed1(void);
void turnOnYellow1(void);
void turnOffYellow1(void);
void turnOnGreen1(void);
void turnOffGreen1(void);
void toggleRed1(void);
void toggleYellow1(void);
void toggleGreen1(void);

// LED set 2
void turnOnRed2(void);
void turnOffRed2(void);
void turnOnYellow2(void);
void turnOffYellow2(void);
void turnOnGreen2(void);
void turnOffGreen2(void);
void toggleRed2(void);
void toggleYellow2(void);
void toggleGreen2(void);

void turnOffAll(void);

#endif /* INC_TRAFFIC_H_ */

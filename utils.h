/*
 * utils.h
 *
 *  Created on: Apr 13, 2026
 *      Author: leome
 */

#ifndef INC_UTILS_H_
#define INC_UTILS_H_

#include "stm32l4xx_hal.h"

#define SPR 200.0f
#define STEPS_PER_DEGREE (SPR / 360.0f)


void setup(void);
void loop(void);
void Moteur_AllerA_Angle(float angle);
void Moteur_MiseAJour(void);



/*

#define SPR2 1600.0f
#define STEPS_PER_DEGREE2 (SPR2 / 360.0f)

void Moteur_AllerA_Angle2(float angle2);
void Moteur_MiseAJour2(void);
*/
#endif /* INC_UTILS_H_ */


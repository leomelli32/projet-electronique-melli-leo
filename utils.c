
/*
 * utils.c
 *
 *  Created on: Apr 13, 2026
 *      Author: leome
 */




#include "utils.h"

extern TIM_HandleTypeDef htim3;

volatile int32_t current_pos = 0;
volatile int32_t target_pos = 0;

void setup(void) {
    //activation driver
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
    HAL_Delay(10);

    //démarrage compteur
    HAL_TIM_Base_Start_IT(&htim3);

    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);


    //Moteur_AllerA_Angle(720.0f);
}

void Moteur_AllerA_Angle(float angle) {
    //On définit des limites
    float angle_securise = angle;

    float angle_min = -180.0f;
    float angle_max = 180.0f;



    if (angle_securise > angle_max) {
        angle_securise = angle_max;
    }
    if (angle_securise < angle_min) {
        angle_securise = angle_min;
    }

    //On met à jour l'angle
    target_pos = (int32_t)(angle_securise * STEPS_PER_DEGREE);
}

void Moteur_MiseAJour(void) {
    // Si on est arrivé à destination, on ne fait rien
    if (current_pos == target_pos) {
        return;
    }

    //direction
    if (target_pos > current_pos) {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
        current_pos++;
    } else {
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
        current_pos--;
    }

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
    for(volatile int i=0; i<50; i++);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);

    // LED témoin
    HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
}


/*

// Variables globales avec un 2
volatile int32_t current_pos2 = 0;
volatile int32_t target_pos2 = 0;

void Moteur_AllerA_Angle2(float angle2) {
    // Butées logicielles
    if (angle2 > 90.0f) angle2 = 90.0f;
    if (angle2 < -90.0f) angle2 = -90.0f;

    target_pos2 = (int32_t)(angle2 * STEPS_PER_DEGREE2);
}

void Moteur_MiseAJour2(void) {
    if (current_pos2 == target_pos2) return;

    // Sens (DIR) sur PB4
    if (target_pos2 > current_pos2) {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
        current_pos2++;
    } else {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
        current_pos2--;
    }

    // STEP sur PB6
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
    for(volatile int i=0; i<20; i++);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
}
*/

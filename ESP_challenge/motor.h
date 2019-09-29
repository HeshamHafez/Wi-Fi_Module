/******************************************************************************
 *
 * Module: Motor Driver
 *
 * File Name: motor.h
 *
 * Description: Header file of Motor Driver
 *
 * Created on: Sep 29, 2019
 *
 * Author: Ahmed El-Dakhly & Hesham Hafez
 *
 *******************************************************************************/


#ifndef INCFILE1_H_
#define INCFILE1_H_

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "std_types.h"
#include "Macro.h"
#include "DIO.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define MOTORA_IN1_PIN				26u
#define MOTORA_IN2_PIN				27u
#define MOTORA_ENABLE               28u
#define MOTORB_ENABLE               29u
#define MOTORB_IN1_PIN				30u
#define MOTORB_IN2_PIN				31u

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*******************************************************************************
 * Function Name:	motor_Init
 *
 * Description: 	Initialize Motor Driver
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void motor_Init(void);

/*******************************************************************************
 * Function Name:	motor_forward
 *
 * Description: 	move Motor forward
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void motor_forward(void);

/*******************************************************************************
 * Function Name:	motor_backward
 *
 * Description: 	move Motor backward
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void motor_backward(void);

/*******************************************************************************
 * Function Name:	motor_Right
 *
 * Description: 	move Motor Right
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void motor_Right(void);

/*******************************************************************************
 * Function Name:	motor_left
 *
 * Description: 	move Motor left
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void motor_left(void);

/*******************************************************************************
 * Function Name:	motor_stop
 *
 * Description: 	stop the motor
 *
 * Inputs:			NULL
 *
 * Outputs:			NULL
 *
 * Return:			NULL
 *******************************************************************************/
void motor_stop(void);



#endif /* INCFILE1_H_ */
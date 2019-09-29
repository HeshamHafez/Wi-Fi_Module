/******************************************************************************
 *
 * Module: Motor Driver
 *
 * File Name: motor.c
 *
 * Description: source file of Motor Driver
 *
 * Created on: Sep 29, 2019
 *
 * Author: Ahmed El-Dakhly & Hesham Hafez
 *
 *******************************************************************************/

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "motor.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
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
void motor_Init(void)
{
	/*Motor A Initialization*/
	DIO_SetPinDirection(MOTORA_IN1_PIN,OUTPUT);
	DIO_SetPinDirection(MOTORA_IN2_PIN,OUTPUT);
	DIO_WritePin(MOTORA_IN1_PIN,LOW);
	DIO_WritePin(MOTORA_IN2_PIN,LOW);
	
	/*Motor B Initialization*/
	DIO_SetPinDirection(MOTORB_IN1_PIN,OUTPUT);
	DIO_SetPinDirection(MOTORB_IN2_PIN,OUTPUT);
	DIO_WritePin(MOTORB_IN1_PIN,LOW);
	DIO_WritePin(MOTORB_IN2_PIN,LOW);
}

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
void motor_forward(void)
{
	/*Motor A*/
	DIO_WritePin(MOTORA_IN1_PIN,HIGH);
	DIO_WritePin(MOTORA_IN2_PIN,LOW);
	/*Motor B*/
	DIO_WritePin(MOTORB_IN1_PIN,LOW);
	DIO_WritePin(MOTORB_IN2_PIN,HIGH);
}

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
void motor_backward(void)
{
	/*Motor A*/
	DIO_WritePin(MOTORA_IN1_PIN,LOW);
	DIO_WritePin(MOTORA_IN2_PIN,HIGH);
	/*Motor B*/
	DIO_WritePin(MOTORB_IN1_PIN,HIGH);
	DIO_WritePin(MOTORB_IN2_PIN,LOW);
}

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
void motor_Right(void)
{
	/*Motor A*/
	DIO_WritePin(MOTORA_IN1_PIN,LOW);
	DIO_WritePin(MOTORA_IN2_PIN,HIGH);
	/*Motor B*/
	DIO_WritePin(MOTORB_IN1_PIN,LOW);
	DIO_WritePin(MOTORB_IN2_PIN,HIGH);
}

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
void motor_left(void)
{
	/*Motor A*/
	DIO_WritePin(MOTORA_IN1_PIN,HIGH);
	DIO_WritePin(MOTORA_IN2_PIN,LOW);
	/*Motor B*/
	DIO_WritePin(MOTORB_IN1_PIN,HIGH);
	DIO_WritePin(MOTORB_IN2_PIN,LOW);
}

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
void motor_stop(void)
{
	/*Motor A*/
	DIO_WritePin(MOTORA_IN1_PIN,LOW);
	DIO_WritePin(MOTORA_IN2_PIN,LOW);
	/*Motor B*/
	DIO_WritePin(MOTORB_IN1_PIN,LOW);
	DIO_WritePin(MOTORB_IN2_PIN,LOW);
}

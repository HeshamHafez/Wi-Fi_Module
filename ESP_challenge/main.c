/******************************************************************************
 *
 * Module: ESP challenge APP
 *
 * File Name: main.c
 *
 * Description: Source file of WI-FI Module App Code
 *
 * Created on: Sep 29, 2019
 *
 * Author: Ahmed El-Dakhly & Hesham Hafez
 *
 *******************************************************************************/
#define SYSTEM_FREQ	8000000UL
#define F_CPU		8000000UL

/*******************************************************************************
 *                       	Included Libraries                                 *
 *******************************************************************************/
#include "ESP_Driver.h"
#include "DIO.h"
#include "motor.h"

/*
#define SSID        "HAFEZ"
#define PASSWORD    "1234567891"
#define PORT	    "1111"
*/
/*******************************************************************************
 *                       	Global Variables                                   *
 *******************************************************************************/
uint8 DataComming = 0;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void UART_Read(uint8 data);
/*******************************************************************************
 *                             Main Function                                   *
 *******************************************************************************/
int main(void)
{
	/*Initialize pinb4,b5,b6 to be output*/
	DIO_SetPinDirection(DIO_PIN12,OUTPUT);
	DIO_SetPinDirection(DIO_PIN13,OUTPUT);
	DIO_SetPinDirection(DIO_PIN14,OUTPUT);
	/*Motors*/
	motor_Init();
	
	Disable_Interrupts();
	/*Initialize uart with 9600 baudrate*/
	UART_Init(9600,UART_Read);
	Enable_Interrupts();
	
	/*Configure Esp to work as a server with port number 1234 and ssdi wifi_ekram*/
	UART_Write_String("AT+CWMODE=2");
	UART_Write_Byte(0xD);
	UART_Write_Byte(0xA);
	_delay_ms(1000);
	
	UART_Write_String("AT+CIPMUX=1");
	UART_Write_Byte(0xD);
	UART_Write_Byte(0xA);
	_delay_ms(1000);

	UART_Write_String("AT+CIPSERVER=1,1111"); /*port number is 1111*/
	UART_Write_Byte(0xD);
	UART_Write_Byte(0xA);
	_delay_ms(1000);

	UART_Write_String("AT+CWSAP=\"HAFEZ\",\"1234567891\",1,3");
	UART_Write_Byte(0xD);
	UART_Write_Byte(0xA);
	_delay_ms(1000);

    while (1) 
    {
		/*Move forward*/
		if(DataComming == 'w')
		{
			motor_forward();
			DIO_WritePin(DIO_PIN13,HIGH);
			DIO_WritePin(DIO_PIN12,LOW);
			DIO_WritePin(DIO_PIN14,LOW);
		}
		/*Move backward*/
		else if(DataComming == 's')
		{
			motor_backward();
			DIO_WritePin(DIO_PIN13,LOW);
			DIO_WritePin(DIO_PIN12,LOW);
			DIO_WritePin(DIO_PIN14,LOW);
		}
		/*move right*/
		else if(DataComming == 'a')
		{
			motor_left();
			DIO_WritePin(DIO_PIN14,HIGH);
			DIO_WritePin(DIO_PIN12,LOW);
			DIO_WritePin(DIO_PIN13,LOW);
		}
		/*move left*/
		else if(DataComming == 'd')
		{
			motor_Right();
			DIO_WritePin(DIO_PIN12,HIGH);
			DIO_WritePin(DIO_PIN14,LOW);
			DIO_WritePin(DIO_PIN13,LOW);
		}
		/*stop*/
		else if(DataComming == 'x')
		{
			motor_stop();
			DIO_WritePin(DIO_PIN12,LOW);
			DIO_WritePin(DIO_PIN13,LOW);
			DIO_WritePin(DIO_PIN14,LOW);
		}
		else
		{
			/*Do Nothing*/
		}
		
		
	}
}

void UART_Read(uint8 data)
{
	DataComming = data;
}
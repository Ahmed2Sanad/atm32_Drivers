/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> DIO_interface.h <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*   
*    Author:Ahmed Mohamed Sanad
*    Layer:MCAL
*    SWC:DIO/GPIO
*   
*/




typedef enum
{
	DIO_NOK=0,
	DIO_OK=1,
	
	
	
}DIO_Error_Status;





#ifndef  _DIO_INTERFACE_H_H
#define  _DIO_INTERFACE_H_H


#include "STD_TYPES.h"


// PORT Direction
#define DIO_PORT_HIGH       0xff
#define DIO_PORT_LOW        0x00


// PORT Value
#define DIO_PORT_OUTPUT     0xff
#define DIO_PORT_INPUT      0x00


// PIN Direction
#define   DIO_PIN_OUTPUT    1
#define   DIO_PIN_INPUT     0

// PIN Value
#define  DIO_PIN_HIGH       1
#define  DIO_PIN_LOW        0

// PORT Define
#define   DIO_PORTA         0
#define   DIO_PORTB         1
#define   DIO_PORTC         2
#define   DIO_PORTD         3

// PIN Define
#define   DIO_PIN0          0
#define   DIO_PIN1          1
#define   DIO_PIN2          2
#define   DIO_PIN3          3
#define   DIO_PIN4          4
#define   DIO_PIN5          5
#define   DIO_PIN6          6
#define   DIO_PIN7          7

//define PIN2 (PUD) in SFIOR Reg 
#define   DIO_PUD           2



  


DIO_Error_Status DIO_enumSetPinDirection     (u8 Copy_u8PORT,u8 Cop_u8PIN,u8 Copy_u8Direction);

DIO_Error_Status DIO_enumSetPinValue         (u8 Copy_u8PORT,u8 Cop_u8PIN,u8 Copy_u8Value);

DIO_Error_Status DIO_enumGetPinValue         (u8 Copy_u8PORT,u8 Cop_u8PIN, u8 *Copy_PtrData);

DIO_Error_Status DIO_enumTogPinValue         (u8 Copy_u8PORT,u8 Copy_u8PIN);


DIO_Error_Status DIO_enumSetPortDirection    (u8 Copy_u8PORT,u8 Copy_u8Ditection);

DIO_Error_Status DIO_enumSetPortValue        (u8 Copy_u8PORT,u8 Copy_u8Value);

DIO_Error_Status DIO_enumGetPortValue        (u8 Copy_u8PORT,u8 *Copy_PtrData);

DIO_Error_Status DIO_enumTogPortValue        (u8 Copy_u8Port);

DIO_Error_Status DIO_enumSetLowNibble        (u8 Copy_u8Port,u8 Copy_u8Value);

DIO_Error_Status DIO_enumSetHighNibble       (u8 Copy_u8Port,u8 Copy_u8Value);

DIO_Error_Status DIO_enumEnablPullUp         (u8 Copy_u8Port,u8 Copy_u8Pin);



#endif

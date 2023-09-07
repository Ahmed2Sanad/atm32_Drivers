/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Seven_Segment_Display_program.c <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*   
*    Author:Ahmed Mohamed Sanad
*    Layer:HAL
*    SWC:Seven_Segment
*   
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_confiq.h"


static u8 Local_u8SSDNumbers[10] = SSD_NUMBER_ARR;


// ------------------------------------------------------------------------------------------------------------

/*
* Brief: This Function Initialize the port which connected to 7 seg leds as output pins (8 pins or port)  
* parameters:       
*            => Copy_u8PORT  : DataPort( PORTX )
*            => Copy_u8Value :  SSD_PORT_HIGH , SSD_PORT_LOW
* return: void
*/

void  SSD_voidIntiDataPort (SSD_Type Copy_StructConfiq)
{
	
	DIO_enumSetPortValue   (Copy_StructConfiq.DataPort,  SSD_PORT_HIGH);
	
	
}

//---------------------------------------------------------------------------------------------------------------
/*
* Brief: This Function Enable Common PIN 
* parameters:       
*            => Copy_u8PORT      : EnablePort ( PORTX )
*            => Cop_u8PIN        : EnablePin  ( PINX  )
             => Copy_u8Direction : SSD_PIN_OUTPUT 
             => Copy_u8Value     : SSD_Common_Cathode_Enable
* return: void
*/

void SSD_voidEnable(SSD_Type Copy_StructConfiq)
{
	if(Copy_StructConfiq.Type == COMMON_ANODE)
	{   
        DIO_enumSetPinDirection  (Copy_StructConfiq.EnablePort, Copy_StructConfiq.EnablePin, SSD_PIN_OUTPUT );
	    DIO_enumSetPinValue      (Copy_StructConfiq.EnablePort, Copy_StructConfiq.EnablePin, SSD_Common_Anode_Enable);
	}
	else if(Copy_StructConfiq.Type == COMMON_CATHODE )
	{
		DIO_enumSetPinDirection  (Copy_StructConfiq.EnablePort,  Copy_StructConfiq.EnablePin, SSD_PIN_OUTPUT );
		DIO_enumSetPinValue      (Copy_StructConfiq.EnablePort,  Copy_StructConfiq.EnablePin, SSD_Common_Cathode_Enable);
	
	}
	
}

//---------------------------------------------------------------------------------------------------------------
/*
* Brief: This Function Disable Common PIN 
* parameters:       
*            => Copy_u8PORT       : EnablePort ( PORTX )
*            => Cop_u8PIN         : EnablePin  ( PINX  )
             => Copy_u8Direction  : SSD_PIN_OUTPUT , SSD_PIN_INPUT
             => Copy_u8Value      : SSD_Common_Cathode_Disable  
* return: void
*/

void SSD_voidDisable(SSD_Type Copy_StructConfiq)
{
	if(Copy_StructConfiq.Type == COMMON_ANODE)
	{   
        DIO_enumSetPinDirection  (Copy_StructConfiq.EnablePort, Copy_StructConfiq.EnablePin, SSD_PIN_OUTPUT );
	    DIO_enumSetPinValue      (Copy_StructConfiq.EnablePort, Copy_StructConfiq.EnablePin, SSD_Common_Anode_Disable);
	}
	else if(Copy_StructConfiq.Type == COMMON_CATHODE )
	{
		DIO_enumSetPinDirection  (Copy_StructConfiq.EnablePort,  Copy_StructConfiq.EnablePin, SSD_PIN_OUTPUT );
		DIO_enumSetPinValue      (Copy_StructConfiq.EnablePort,  Copy_StructConfiq.EnablePin, SSD_Common_Cathode_Disable);
	
	}
	
}

//----------------------------------------------------------------------------------------------------------------------
/*
* Brief      : This Function Display Numbers [1:9]
* parameters :  struct has SSD_Type , Data_port  
*              
* return: void
*/

void SSD_voidSendData ( SSD_Type Copy_StructConfiq ,u8 Copy_u8Number)
{
	if(Copy_StructConfiq.Type == COMMON_ANODE)
	{
		DIO_enumSetPortValue ( Copy_StructConfiq.DataPort , ~(Local_u8SSDNumbers[Copy_u8Number]));
	}
	else if(Copy_StructConfiq.Type == COMMON_CATHODE )
	{
		DIO_enumSetPortValue ( Copy_StructConfiq.DataPort , Local_u8SSDNumbers[Copy_u8Number]);
	}
	
}


/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> LED_program.c <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*   
*    Author:Ahmed Mohamed Sanad
*    Layer:HAL
*    SWC:LED
*   
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"



//-----------------------------------------------------------------------------------------
/*
* Brief:the function intialize the pin which connect to led as output pin
* parameter:
            =>struct has the led port, pin, active state
* return: void

*/


void LED_voidInit (LED_Type LED_Configration)
{
	
	 
	 DIO_enumSetPinDirection  (LED_Configration.Port,LED_Configration.Pin,LED_OUTPUT);
}

//--------------------------------------------------------------------------------------

/*
* Brief: This Function Set High on Led pin (Led on) 
* parameter: 
             =>struct has the led port, pin, status	
* return: void

*/

//---------------------------------------------------------------------------------------------------

void LED_voiOn (LED_Type LED_Configration)
{
	
	if(LED_Configration.Active_State == Active_HiGH)
	{
		 DIO_enumSetPinValue(LED_Configration.Port,  LED_Configration.Pin,  DIO_HIGH);

	}
	else if(LED_Configration.Active_State == Active_LOW)
	{

	    DIO_enumSetPinValue(LED_Configration.Port,  LED_Configration.Pin,  DIO_LOW);
	}
	
}


//---------------------------------------------------------------------------------------------------

/*
* Brief: This Function Set LOW on Led pin (Led off)
* parameters: 
             =>struct has the led port, pin, status	
* return: void
*/


void LED_voidOff (LED_Type LED_Configration)
{
	if(LED_Configration.Active_State == Active_HiGH)
	{
          DIO_enumSetPinValue(LED_Configration.Port,  LED_Configration.Pin,  DIO_LOW);
	}
	else if(LED_Configration.Active_State == Active_HiGH)
	{
		
		 DIO_enumSetPinValue(LED_Configration.Port,  LED_Configration.Pin,  DIO_HIGH);
	
	}
	
}

//----------------------------------------------------------------------------------------------

/*
* Brief: This Function Toggle Led pin
* parameters: 
             =>struct has the led port, pin, status	
* return: void
*/

void LED_voidToggle (LED_Type LED_Configration)
{
	    DIO_enumTogPinValue (LED_Configration.Port,  LED_Configration.Pin);
	
	
}
 


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  END  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

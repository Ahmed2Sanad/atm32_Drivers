/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> LED_interface.h <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*   
*    Author:Ahmed Mohamed Sanad
*    Layer:HAL
*    SWC:LED
*   
*/


#ifndef  _INTERFACE_H_H
#define  _INTERFACE_H_H



typedef struct 
{
	u8 Port;
	u8 Pin;
	u8 Active_State;
	
	
	
}LED_Type;



// Direction Define
#define LED_OUTPUT       1
#define LED_INPUT        0






// Active Satutes
#define Active_HiGH      1
#define Active_LOW       0

//MC OUT PINS
#define DIO_HIGH         1
#define DIO_LOW          0

// PORT Define
#define   LED_PORTA      0
#define   LED_PORTB      1
#define   LED_PORTC      2
#define   LED_PORTD      3

// PIN Define
#define   LED_PIN0       0
#define   LED_PIN1       1
#define   LED_PIN2       2
#define   LED_PIN3       3
#define   LED_PIN4       4
#define   LED_PIN5       5
#define   LED_PIN6       6
#define   LED_PIN7       7


void LED_voidInit    (LED_Type LED_Configration);
void LED_voiOn       (LED_Type LED_Configration);
void LED_voidOff     (LED_Type LED_Configration);
void LED_voidToggle  (LED_Type LED_Configration);




#endif

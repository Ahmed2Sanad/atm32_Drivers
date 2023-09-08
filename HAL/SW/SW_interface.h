/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SWITCH_interface.h <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*   
*    Author:Ahmed Mohamed Sanad
*    Layer:HAL
*    SWC:SWITCH
*   
*/

#ifndef  _INTERFACE_H_H
#define  _INTERFACE_H_H


typedef struct
{
	
	u8 SW_PORT;
	u8 SW_PIN;
	u8 SW_Pull_Status;
	
	
}SW_Data;

// PIN DIRECTION

#define SW_PIN_INPUT         0
#define SW_PIN_OUTPUT        1


// PULL Status
#define   EX_Pull_Down       0 
#define   EX_Pull_UP         1
#define   IN_Pull_UP         2



#define   SW_pressed         1
#define   SW_Not_Pressed     0

#define SW_RES_HIGH          1
#define SW_RES_LOW           0

#endif








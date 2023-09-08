/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> SWitch_program.c <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*   
*    Author:Ahmed Mohamed Sanad
*    Layer:HAL
*    SWC:SWITCH
*   
*/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"


//--------------------------------------------------------------------------------------------------------------------

/* Brief     : This Function Initializion for Switch 
   Parameters: 
             => struct contain switch port - switch pin - switch_pull status
    return : void
*/

void SW_voidInit( SW_Data Confiqration_Switch )
{
	
	DIO_enumSetPinDirection( Confiqration_Switch.SW_PORT, Confiqration_Switch.SW_PIN , SW_PIN_INPUT);
	
	if(Confiqration_Switch.SW_Pull_Status == IN_Pull_UP )
	{
		
		DIO_enumEnablPullUp(Confiqration_Switch.SW_PORT, Confiqration_Switch.SW_PIN);
		
		
	}

	
}

//--------------------------------------------------------------------------------------------------------------------

/* Brief     : This Function Get switch status  
   Parameters: 
             => struct contain switch port - switch pin - switch_pull status
    return : LOC_u8Result -> indecator of switch status
*/

u8 SW_u8GetPressed ( SW_Data Confiqration_Switch )
{
	  u8 LOC_u8Result= SW_Not_Pressed ;
	  u8 LOC_u8pinVal= SW_Not_Pressed ;
	
	 if( Confiqration_Switch.SW_Pull_Status == IN_Pull_UP ) &&( Confiqration_Switch.SW_Pull_Status == EX_Pull_UP)
	 {
		 
		DIO_enumGetPinValue ( Confiqration_Switch.SW_PORT, Confiqration_Switch.SW_PIN, &LOC_u8pinVal)    

	      if(LOC_u8pinVal == SW_RES_LOW )
		  {
			   LOC_u8Result= SW_pressed;
			  
		  }
		  else
		  {
			  
			  LOC_u8Result = SW_Not_Pressed ;
			  
		  }			  

	}
	else if(  Confiqration_Switch.SW_Pull_Status == EX_Pull_Down ) 
	 {
		 
		DIO_enumGetPinValue( Confiqration_Switch.SW_PORT, Confiqration_Switch.SW_PIN, &LOC_u8pinVal)    
           
		   
	      if(LOC_u8pinVal == SW_RES_LOW )
		  {
			   LOC_u8Result= SW_Not_Pressed;
			  
		  }
		  else
		  {
			  
			  LOC_u8Result = SW_pressed;
			  
		  }			  

	
     }

	 return LOC_u8Result;
}

//--------------------------------------------------------------------------------------------------------------------





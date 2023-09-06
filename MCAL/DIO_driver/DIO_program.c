/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> DIO_program.c <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*   
*    Author:Ahmed Mohamed Sanad
*    Layer:MCAL
*    SWC:DIO/GPIO
*   
*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


/* Brief : This Function Set The Direction 
 Parameters:
       =>Copy_u8PORT      --> PORT Name(DIO_PORTA ,DIO_PORTB ,DIO_PORTC ,DIO_PORTD)
       =>Cop_u8PIN        --> PIN Name(DIO_PIN0,...........................,DIO_PIN7)
       =>Copy_u8Direction --> Data Direction (DIO_PIN_OUTPUT  )/(DIO_PIN_INPUT )  
	   return Error_Status;
*/

DIO_Error_Status DIO_enumSetPinDirection(u8 Copy_u8PORT,u8 Cop_u8PIN,u8 Copy_u8Direction)
{
	   DIO_Error_Status LOC_enumState=DIO_OK;
	
	if((Copy_u8PORT<=DIO_PORTD)&&(Cop_u8PIN<=DIO_PIN7 ))
	{
		if(Copy_u8Direction==DIO_PIN_OUTPUT)
	    {
		   switch(Copy_u8PORT)
		    {
			 
			  case DIO_PORTA : SET_BIT(DDRA ,Cop_u8PIN) ; break;
			  case DIO_PORTB : SET_BIT(DDRB ,Cop_u8PIN) ; break;
			  case DIO_PORTC : SET_BIT(DDRC ,Cop_u8PIN) ; break;
		      case DIO_PORTD : SET_BIT(DDRD ,Cop_u8PIN) ; break;
		 
		    }
		 
	   }
	    else if(Copy_u8Direction==DIO_PIN_INPUT)
	    {
		    switch(Copy_u8PORT)
		    {
			 
			  case DIO_PORTA : CLR_BIT(DDRA ,Cop_u8PIN) ; break;
			  case DIO_PORTB : CLR_BIT(DDRB ,Cop_u8PIN) ; break;
			  case DIO_PORTC : CLR_BIT(DDRC ,Cop_u8PIN) ; break;
		      case DIO_PORTD : CLR_BIT(DDRD ,Cop_u8PIN) ; break;
		 
		    }
		 
		 
	    }
	
	
	}
	else
	{
		LOC_enumState=DIO_NOK;
		
	}
	
	return LOC_enumState;
}


/* Brief : This Function Set The PIN Value 
 Parameters:
       =>Copy_u8PORT      --> PORT Name(DIO_PORTA ,DIO_PORTB ,DIO_PORTC ,DIO_PORTD)
       =>Cop_u8PIN        --> PIN Name(DIO_PIN0,...........................,DIO_PIN7)
       => Copy_u8Value    --> The Value (DDIO_PIN_HIGH  ,DIO_PIN_HIGH  )  
	   return Error_Status;
*/


DIO_Error_Status DIO_enumSetPinValue(u8 Copy_u8PORT,u8 Cop_u8PIN,u8 Copy_u8Value)
{   
      DIO_Error_Status LOC_enumState=DIO_OK;
	  
	if((Copy_u8PORT<=DIO_PORTD)&&(Cop_u8PIN<=DIO_PIN7 ))
	{
	  
	  if(Copy_u8Value == DIO_PIN_HIGH)
	    {
	   	    switch(Copy_u8PORT)
	   	    {
	   		 
	   		   case DIO_PORTA : SET_BIT(PORTA,Cop_u8PIN) ; break;
	   		   case DIO_PORTB : SET_BIT(PORTB,Cop_u8PIN) ; break;
	   		   case DIO_PORTC : SET_BIT(PORTC,Cop_u8PIN) ; break;
	   	       case DIO_PORTD : SET_BIT(PORTD,Cop_u8PIN) ; break;
	   	 
	   	    }
	   	 
	    }
	    else if(Copy_u8Direction==DIO_PIN_LOW)
	    {
	   	    switch(Copy_u8PORT)
	   	    {
	   		 
	   		   case DIO_PORTA : CLR_BIT(PORTA,Cop_u8PIN) ; break;
	   		   case DIO_PORTB : CLR_BIT(PORTB,Cop_u8PIN) ; break;
	   		   case DIO_PORTC : CLR_BIT(PORTC,Cop_u8PIN) ; break;
	   	       case DIO_PORTD : CLR_BIT(PORTD,Cop_u8PIN) ; break;
	   	 
	   	    }
	   	 
	   	 
	    }
	   
	   
	}
	else
	{
		LOC_enumState=DIO_NOK;
		
	}
	return LOC_enumState;
}


/* Brief : This Function Get The Value of The Pin
 Parameters:
       =>Copy_u8PORT  --> PORT Name(DIO_PORTA ,DIO_PORTB ,DIO_PORTC ,DIO_PORTD)
       =>Cop_u8PIN    --> PIN Name(DIO_PIN0,...........................,DIO_PIN7)
       =>Copy_PtrData --> Return by Refernce The Value of PIN From Register 
	   return Error_Status;
*/



DIO_Error_Status DIO_enumGetPinValue(u8 Copy_u8PORT,u8 Cop_u8PIN, u8 *Copy_PtrData)
{
	
	    DIO_Error_Status LOC_enumState=DIO_OK;
	
	if((Copy_u8PORT<=DIO_PORTD)&&(Cop_u8PIN<=DIO_PIN7 ))
	{

	    switch(Copy_u8PORT)
	    {
		
		case DIO_PORTA  : *Copy_PtrData =(GET_BIT(PINA,Cop_u8PIN));
		case DIO_PORTB  : *Copy_PtrData =(GET_BIT(PINB,Cop_u8PIN));
		case DIO_PORTC  : *Copy_PtrData =(GET_BIT(PINC,Cop_u8PIN));
		case DIO_PORTD  : *Copy_PtrData =(GET_BIT(PIND,Cop_u8PIN));

	    }
      

	}
	else
	{
		LOC_enumState=DIO_NOK;
	}

	return LOC_enumState;
}
/* Brief : This Function Toggle The Value of The Pin
 Parameters:
       =>Copy_u8PORT  --> PORT Name(DIO_PORTA ,DIO_PORTB ,DIO_PORTC ,DIO_PORTD)
       =>Cop_u8PIN    --> PIN Name(DIO_PIN0,...........................,DIO_PIN7)
	   return Error_Status;
*/


DIO_Error_Status DIO_enumTogPinValue(u8 Copy_u8PORT,u8 Copy_u8PIN)
{
	   DIO_Error_Status LOC_enumState=DIO_OK;
	if((Copy_u8PORT<=DIO_PORTD)&&(Cop_u8PIN<=DIO_PIN7 ))
	{
	    switch(Copy_u8PORT)
	    {
			case DIO_PORTA :TOG_BIT(PORTA,Copy_u8PIN) ;
			case DIO_PORTB :TOG_BIT(PORTB,Copy_u8PIN) ;
			case DIO_PORTC :TOG_BIT(PORTC,Copy_u8PIN) ;
			case DIO_PORTD :TOG_BIT(PORTD,Copy_u8PIN) ;
	
	    }

	}
	else
	{
		LOC_enumState=DIO_NOK;
	}
  
     return LOC_enumState;
	
}



/* Brief : This Function SET The PORT Value
 Parameters:
       =>Copy_u8PORT      --> PORT Name(DIO_PORTA ,DIO_PORTB ,DIO_PORTC ,DIO_PORTD)
       => Copy_u8Value    --> The Value (DDIO_PIN_HIGH  ,DIO_PIN_HIGH  )  
	   return Error_Status;
*/


DIO_Error_Status DIO_enumSetPortValue(u8 Copy_u8PORT,u8 Copy_u8Value)
{
	DIO_Error_Status LOC_enumState=DIO_OK;
	
	
	if(Copy_u8PORT <= DIO_PORTD  )
	{
	    if(Copy_u8PortValu == DIO_PORT_HIGH )
	    {
	        switch(Copy_u8PORT)
	        {
	     		case DIO_PORTA :PORTA==DIO_PORT_HIGH;break;
	     		case DIO_PORTB :PORTB==DIO_PORT_HIGH;break;
	     		case DIO_PORTC :PORTC==DIO_PORT_HIGH;break;
	     		case DIO_PORTD :PORTD==DIO_PORT_HIGH;break;
	     
	         }

	     	
	    }
	     
	    else if(Copy_u8PortValu == DIO_PORT_LOW)
	    {
	        switch(Copy_u8PORT)
	        {
	     		case DIO_PORTA :PORTA==DIO_PORT_LOW;break;
	     		case DIO_PORTB :PORTB==DIO_PORT_LOW;break;
	     		case DIO_PORTC :PORTC==DIO_PORT_LOW;break;
	     		case DIO_PORTD :PORTD==DIO_PORT_LOW;break;
	     
	        }
	     
	    }
	}
	else
	{
		LOC_enumState=DIO_NOK;
		
	}
	
	return LOC_enumState;
}

/* Brief : This Function Set PORT Direction 
 Parameters:
       =>Copy_u8PORT      --> PORT Name(DIO_PORTA ,DIO_PORTB ,DIO_PORTC ,DIO_PORTD)
       =>Copy_u8Direction --> Data Direction ( DIO_PIN_OUTPUT)/( DIO_PIN_INPUT )  
	   return Error_Status;
*/





DIO_Error_Status DIO_enumSetPortDirection(u8 Copy_u8PORT,u8 Copy_u8Ditection)
{
	  DIO_Error_Status LOC_enumState=DIO_OK;
	  
	if(Copy_u8PORT <= DIO_PORTD  )
	{
		
	
	    
	   
	    	switch(Copy_u8PORT)
	    	{
	    		 
	    		case DIO_PORTA : DDRA=Copy_u8Ditection ; break;
	    		case DIO_PORTB : DDRB=Copy_u8Ditection ; break;
	    		case DIO_PORTC : DDRC=Copy_u8Ditection ; break;
	    	    case DIO_PORTD : DDRD=Copy_u8Ditection ; break;
	    	 
	    	}
	    	 
	}
	  
        
	
	else
	{
	 	LOC_enumState=DIO_NOK;
		
	}
	return LOC_enumState;
}


/* Brief : This Function Get PORT Value 
 Parameters:
       =>Copy_u8PORT      --> PORT Name(DIO_PORTA ,DIO_PORTB ,DIO_PORTC ,DIO_PORTD)
       =>*Copy_PtrData    --> Return by Refernce The Value of whole Register(PINX) 
	   return Error_Status;
*/



DIO_Error_Status DIO_enumGetPortValue(u8 Copy_u8PORT,u8 *Copy_PtrData)
{
	 DIO_Error_Status LOC_enumState=DIO_OK;
	  
	if(Copy_u8PORT <= DIO_PORTD  )
	{
	    switch(Copy_u8PORT)
	    	 {
	    		 
	    		 case DIO_PORTA : *Copy_PtrData=PINA ; break;
	    		 case DIO_PORTB : *Copy_PtrData=PINB ; break;
	    		 case DIO_PORTC : *Copy_PtrData=PINC ; break;
	    	     case DIO_PORTD : *Copy_PtrData=PIND ; break;
	    	 
	    	 }
	    
	          
	}
    else
	{
		LOC_enumState=DIO_NOK;
		
	}		

	return LOC_enumState;

}


/* Brief : This Function Toggle PORT Value 
 Parameters:
       =>Copy_u8PORT      --> PORT Name(DIO_PORTA ,DIO_PORTB ,DIO_PORTC ,DIO_PORTD)
	   return Error_Status;
*/

DIO_Error_Status DIO_enumTogPortValue(u8 Copy_u8Port)
{
	DIO_Error_Status LOC_enumState=DIO_OK;
	  
	if(Copy_u8PORT <= DIO_PORTD  )
	{
	    switch(Copy_u8PORT)
	    	 {
	    		 
	    		 case DIO_PORTA : PORTA= ~PORTA  ; break;
	    		 case DIO_PORTB : PORTB= ~PORTB  ; break;
	    		 case DIO_PORTC : PORTC= ~PORTC  ; break;
	    	     case DIO_PORTD : PORTD= ~PORTD  ; break;
	    	                          
	    	 }
	    
	    
	}
    else
	{
		
		LOC_enumState=DIO_NOK;
		
	}	
	
	return LOC_enumState;
}
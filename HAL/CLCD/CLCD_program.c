/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Char_Liquid_Crystal_Display_program.c <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*   
*    Author:Ahmed Mohamed Sanad
*    Layer:HAL
*    SWC:CLCD
*   
*/

#include <utile/delay>
#include "DIO_interface.h"

//-------------------------------------------------------------------------------------------------------

/* Brief : This Function Intialization for LCD -> 2*16
 Parameters:  void 
	 return   void
*/

void CLCD_voidInit                 (void)
{
	#if     CLCD_Mode      8
	
	// 1- wait more than 39ms until VDD rises to 4.5v
	  _delay_ms(50);
	  
	
	
	// OUTPUT DIRECTION
	DIO_enumSetPortDirection (CLCD_DATA_PORT, CLCD_PORT_OUTPUT);
	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT,CLCD_RS,CLCD_PIN_OUTPUT);
	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT,CLCD_RW,CLCD_PIN_OUTPUT);
	DIO_enumSetPinDirection  (CLCD_CONTROL_PORT,CLCD_EN,CLCD_PIN_OUTPUT);
	
	
	// Return cursor to first line
	CLCD_voidSendCommand (Return_HOME);
	_delay_ms(1);
	
	/* 
     *                	------------------------------------------- 
	 *  Function Set   |  RS  RW  DB7 DB6 DB5 DB4 DB3 DB2 DB1 DB0  |
	 *                 |  0   0    0   0   1   1   N   F   X   X   |
	 *                  -------------------------------------------  
	*/
     // 
    CLCD_voidSendCommand (EIGHT_BITS); // ->0x38
		_delay_ms(1);

	CLCD_voidSendCommand (lcd_DisplayON_CursorOff);
	    _delay_ms(1);
	
    CLCD_voidClearScreen();
	
	CLCD_voidSendCommand(lcd_EnteryMode);
	    _delay_ms(1);
	
	
}
//-------------------------------------------------------------------------------------------------------

/* Brief : This Function Dend Only one character to LCD 
 Parameters:  Copy_U8Data 
                          => like any ASCII of any character that the internal MC in LCD will translate it into char  
	 return   void
*/



void CLCD_voidSendData             (u8 Copy_U8Data)
{
	
	#if     CLCD_Mode      8
	 

	 // CLCD_DATA_PORT    => there is in conifiq where user can change port of data in easy way 
	 DIO_enumSetPortValue(CLCD_DATA_PORT, Copy_U8Data);

	 // CLCD_CONTROL_PORT => like CLCD_DATA_PORT  user can changr pins of control pins (RS,RW,EN)
	 DIO_enumSetPinValue (CLCD_CONTROL_PORT,CLCD_RS,CLCD_PIN_HIGH);
	 DIO_enumSetPinValue (CLCD_CONTROL_PORT,CLCD_RW,CLCD_PIN_LOW);

	 // Enable should be falling edge transfer from 1 to 0 to be active so i wrote its func alone just made it for 1ms in high then made it 1ms in low	
	 CLCD_voidSendFallingEdge ();
	
	#elif   CLCD_Mode        4
	
	
	
}

//-------------------------------------------------------------------------------------------------------

/* Brief : This Function send commands to set LCD
 Parameters:  Copy_U8Commend 
                             => you can check commands in data sheet there are many commands like set function (0x38) 
	 return   void
*/



void CLCD_voidSendCommand          (u8 Copy_U8Command) 
{
	
	#if     CLCD_Mode      8
	 
	// this like func of send data but the onlu difference between them in RS(TO send commend make it 0)

	 DIO_enumSetPortValue(CLCD_DATA_PORT, Copy_U8Command);
	 
	 DIO_enumSetPinValue (CLCD_CONTROL_PORT,CLCD_RS,CLCD_PIN_LOW);
	 DIO_enumSetPinValue (CLCD_CONTROL_PORT,CLCD_RW,CLCD_PIN_LOW);
	
	  CLCD_voidSendFallingEdge ();
	
	#elif   CLCD_Mode        4
	
	
	
}

//-------------------------------------------------------------------------------------------------------

/* Brief : This Function for Enable you make it because enable activated when EN PIN be high then be low
 Parameters:  Void                           
	 return   void

     this function cannot be used in another file because it is static 	 
*/


static void   CLCD_voidSendFallingEdge ( void )
{
	
		 DIO_enumSetPinValue (CLCD_CONTROL_PORT,CLCD_EN,CLCD_PIN_HIGH);
          _delay_ms(1);
		 DIO_enumSetPinValue (CLCD_CONTROL_PORT,CLCD_RS,CLCD_PIN_LOW);
           _delay_ms(1);
	
}


//--------------------------------------------------------------

/* Brief : This Function for Clear your screan i made it alone to be easy to use in main by user
 Parameters:  Void                           
	 return   void

                    * you can wrote it inside initialization function * 	 
*/



void CLCD_voidClearScreen(void)
{
	
	
	CLCD_voidSendCommand(CLEAR_DISPLAY);
	     _delay_ms(10);
	
	
	
}




//-----------------------------------------------------------


/* Brief : This Function for Send String to LCD i use the func that send the char  
 Parameters:  *Copy_U8PtrSting[]
                                 => pointer point in the begining of array then increment addrease to print sec char and so on 
	 return   void

                   	 
*/


void CLCD_voidSendString (const u8 *Copy_U8PtrSting[])
{
	
	u8 Loc_Iterator =0;
	 
	 while(*(Copy_U8PtrSting+Loc_Iterator) 1= '\0')
	 {
		 
		 CLCD_voidSendData((*(Copy_U8PtrSting+Loc_Iterator)));
		 
		 Loc_Iterator++;
		 
	 }
	
}  

//----------------------------------------------------------------------------------------------------------------




/* Brief : This Function for setting cursor on display using DDRAM REG 
 Parameters: 
            => Copy_u8ROW -> ROW_1 , ROW_2 
            => Copy_u8COL -> COL_1..................................COL_16                
	 return   void

                   	 
*/



void CLCD_voidSetPosition (u8 Copy_u8ROW,  u8 Copy_u8COL    )
{
	  u8 LOC_u8data;
	
	if(Copy_u8ROW>2 || Copy_u8ROW<1 || Copy_u8COL>16 || Copy_u8COL <1)
	{
		
		LOC_u8data= lcd_SetCursor ;
		
		
	}
	else if (Copy_u8ROW == CLCD_ROW_1)
	{
		
		LOC_u8data = lcd_SetCursor + (Copy_u8COL-1);
		
		
	}
	else if (Copy_u8ROW == CLCD_ROW_2)
	{
		
		LOC_u8data = lcd_SetCursor + 64+ (Copy_u8COL-1);
		
		
	}
	 CLCD_voidSendCommand(LOC_u8data);
	   _delay_ms(1);
	
	
	
	
} 





//----------------------------------------------------------------------------------------------------------------



void CLCD_voidCreateExtraChar(u8 Copy_u8ROW,  u8 Copy_u8COL )
{
	u8 LOC_Iterator=0;
	LCD_voidSendCommand(lcd_CGRAM);
	
	
	
	for(LOC_Iterator=0;LOC_Iterator<sizeof(CLCD_CreateChar)/sizeof(CLCD_CreateChar[LOC_Iterator];LOC_Iterator)
	{
		  CLCD_voidSendData(CLCD_CreateChar[LOC_Iterator]);
	
	}

	
	CLCD_voidSetPosition (u8 Copy_u8ROW,  u8 Copy_u8COL);
	
	
	for(LOC_Iterator=0;LOC_Iterator<8;LOC_Iterator++)
	{
		 CLCD_voidSendData(LOC_Iterator);
		
	}
	
}



//------------------------------------------------------------------------------------------------------------------

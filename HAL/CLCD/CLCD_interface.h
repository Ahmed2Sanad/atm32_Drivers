/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Char_Liquid_Crystal_Display_interface.h <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*   
*    Author:Ahmed Mohamed Sanad
*    Layer:HAL
*    SWC:CLCD
*   
*/


#ifndef  _CLCD_INTERFACE_H_H
#define  _CLCD_INTERFACE_H_H
  
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "CLCD_private.h"
#include "CLCD_confiq.h"

  
//-------------------------
 
#if CLCD_Mode == 4
#define FOUR_BITS      0x28

#elif CLCD_Mode == 8
#define EIGHT_BITS     0x38  
  
  
//------------------------- 
  
#define Return_HOME                    0x02
#define CLEAR_DISPLAY                  0x01
#define lcd_DisplayON_CursorOff        0x0c
#define lcd_DisplayON_CursorOn         0x0e
#define lcd_DisplayOff_CursorOff       0x08
#define lcd_EnteryMode                 0x06
#define lcd_FunctionRest               0x30
#define lcd_SetCursor                  0x80
#define lcd_CGRAM                      0x40
  
//---------------------------
  
  
  
	  
// PORT Direction
#define CLCD_PORT_OUTPUT     0xff
#define CLCD_PORT_INPUT      0x00
  
#define CLCD_PIN_OUTPUT      1
#define CLCD_PIN_INPUT       0
  
  
#define CLCD_PIN_HIGH        1
#define CLCD_PIN_LOW         0



#define   CLCD_ROW_1           1
#define   CLCD_ROW_2           2
                             
                             
                             
                             
//defin   COL                              
#define   CLCD_COL_1         1
#define   CLCD_COL_2         2
#define   CLCD_COL_3         3
#define   CLCD_COL_4         4
#define   CLCD_COL_5         5
#define   CLCD_COL_6         6
#define   CLCD_COL_7         7
#define   CLCD_COL_8         8
#define   CLCD_COL_9         9
#define   CLCD_COL_10        10
#define   CLCD_COL_11        11
#define   CLCD_COL_12        12
#define   CLCD_COL_13        13
#define   CLCD_COL_14        14
#define   CLCD_COL_15        15
#define   CLCD_COL_16        16

 
  
void CLCD_voidInit                 (void                       );
void CLCD_voidSendData             (u8 Copy_U8Data             );  
void CLCD_voidSendCommand          (u8 Copy_U8Command          );  
void CLCD_voidClearScreen          (void                       );  
  
void CLCD_voidSendString           (const u8 *Copy_U8PtrSting[]);  
 
void CLCD_voidSetPosition          (u8 CLCD_ROW,u8 CLCD_COL    ); 
 
#endif  

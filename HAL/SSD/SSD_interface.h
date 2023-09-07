/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Seven_Segment_Display_interface.h <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*   
*    Author:Ahmed Mohamed Sanad
*    Layer:HAL
*    SWC:Seven_Segment
*   
*/

#ifndef  _INTERFACE_H_H
#define  _INTERFACE_H_H


typedef struct
{
	u8 Type;
	u8 DataPort;
	u8 EnablePort;
	u8 EnablePin;
	
	
}SSD_Type;

//
#define SSD_PORT_HIGH                 0xff
#define SSD_PORT_LOW                  0x00
                                     
// Tyepes_Seven_Segment              
#define COMMON_CATHODE                 0
#define COMMON_ANODE                   1 
                                     
// SSD_PIN_Enable_Value              
#define SSD_Common_Anode_Enable        1
#define SSD_Common_Cathode_Enable      0
                                     
// Seven_Segment_Pin_Direction        
#define  SSD_PIN_OUTPUT                1
#define  SSD_PIN_INPUT                 0
                                     
// SSD_PIN_Disable_Value             
#define SSD_Common_Anode_Disable       0
#define SSD_Common_Cathode_Disable     1
                                     

// PORT Define
#define   SSD_PORTA                    0
#define   SSD_PORTB                    1
#define   SSD_PORTC                    2
#define   SSD_PORTD                    3
                                    
// PIN Define                       
#define   SSD_PIN0                     0
#define   SSD_PIN1                     1
#define   SSD_PIN2                     2
#define   SSD_PIN3                     3
#define   SSD_PIN4                     4
#define   SSD_PIN5                     5
#define   SSD_PIN6                     6
#define   SSD_PIN7                     7



void  SSD_voidIntiDataPort (SSD_Type Copy_StructConfiq);

void  SSD_voidEnable       (SSD_Type Copy_StructConfiq);

void  SSD_voidDisable      (SSD_Type Copy_StructConfiq);

void SSD_voidSendData      ( SSD_Type Copy_StructConfiq ,u8 Copy_u8Number);




#endif

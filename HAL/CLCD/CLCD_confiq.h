/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> Char_Liquid_Crystal_Display_confiq.h <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*   
*    Author:Ahmed Mohamed Sanad
*    Layer:HAL
*    SWC:CLCD
*   
*/

#ifndef  _CLCD_CONFIQ_H_
#define  _CLCD_CONFIQ_H_






#define CLCD_Mode    8



//--------------------------------------------------------



// any port
#define CLCD_DATA_PORT       DIO_PORTA

// RS*RW*EN
#define CLCD_CONTROL_PORT    DIO_PORTC


#define   CLCD_RS        0
#define   CLCD_RW        1
#define   CLCD_EN        2
  

#endif
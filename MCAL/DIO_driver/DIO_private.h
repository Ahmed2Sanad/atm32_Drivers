/*>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> DIO_private.h <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
*   
*    Author:Ahmed Mohamed Sanad
*    Layer:MCAL
*    SWC:DIO/GPIO
*   
*/


#ifndef  _DIO_PRIVATE_H_H
#define  _DIO_PRIVATE_H_H


/*  GROUP A */

#define PORTA      *((volatile u8*)0x3B)
#define DDRA       *((volatile u8*)0x3A)
#define PINA       *((volatile u8*)0x39)


/*  GROUP B */

#define PORTB      *((volatile u8*)0x38)
#define DDRB       *((volatile u8*)0x37)
#define PINB       *((volatile u8*)0x36)

/*  GROUP C */

#define PORTC      *((volatile u8*)0x35)
#define DDRC       *((volatile u8*)0x34)
#define PINC       *((volatile u8*)0x33)

/*  GROUP D */
#define PORTD      *((volatile u8*)0x32)
#define DDRD       *((volatile u8*)0x31)
#define PIND       *((volatile u8*)0x30)




#endif
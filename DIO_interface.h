/* 
 * <<<<<<DIO_interface.h>>>>>
 * Author : zahwa
 * Layer  : MCAL
 * SWC    : DIO/GPIO
 */

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INPUT 0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW  0

#define DIO_PORT_OUTPUT 0xff
#define DIO_PORT_INPUT 0x00

#define DIO_PORT_HIGH 0xff
#define DIO_PORT_LOW  0x00

typedef enum
{
	DIO_NOK,
	DIO_OK
}DIO_ERRORStatus;

DIO_ERRORStatus DIO_EnumSetPinDirection   (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Direction);
DIO_ERRORStatus DIO_EnumSetPinValue       (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value    );
DIO_ERRORStatus DIO_EnumGetPinValue       (u8 copy_u8PORT, u8 copy_u8PIN , u8 *copy_PtrData  );
DIO_ERRORStatus DIO_EnumTogglePinValue    (u8 copy_u8PORT, u8 copy_u8PIN                     );

void DIO_VoidSetPortDirection (u8 copy_u8PORT, u8 copy_u8Direction);
void DIO_VoidSetPortValue     (u8 copy_u8PORT, u8 copy_u8Value);
u8   DIO_u8GetPortValue       (u8 copy_u8PORT );
void DIO_VoidTogglePortValue  (u8 copy_u8PORT );

#endif

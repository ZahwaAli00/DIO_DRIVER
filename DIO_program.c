/* 
 * <<<<<<DIO_program.c>>>>>
 * Author : zahwa
 * Layer  : MCAL
 * SWC    : DIO/GPIO
 */
#include "STD_Types.h"
#include "BIT_MATN.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

DIO_ERRORStatus DIO_EnumSetPinDirection (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Direction)
{
	u8 LOC_Status=DIO_OK;
	if(copy_u8PORT<=DIO_PORTD && copy_u8PIN<=DIO_PIN7)
	{
		if(copy_u8Direction == DIO_PIN_OUTPUT ){
			switch (copy_u8PORT)
			{
			case DIO_PORTA:SET_BIT(DDRA,copy_u8PIN);break;
			case DIO_PORTB:SET_BIT(DDRB,copy_u8PIN);break;
			case DIO_PORTC:SET_BIT(DDRC,copy_u8PIN);break;
			case DIO_PORTD:SET_BIT(DDRD,copy_u8PIN);break;
			}
		}
		else if(copy_u8Direction == DIO_PIN_INPUT ){
			switch (copy_u8PORT)
			{
			case DIO_PORTA:CLEAR_BIT(DDRA,copy_u8PIN);break;
			case DIO_PORTB:CLEAR_BIT(DDRB,copy_u8PIN);break;
			case DIO_PORTC:CLEAR_BIT(DDRC,copy_u8PIN);break;
			case DIO_PORTD:CLEAR_BIT(DDRD,copy_u8PIN);break;
			}
		}
	}
	else
	{
		LOC_Status=DIO_NOK;
	}
	return LOC_Status;
}
DIO_ERRORStatus DIO_EnumSetPinValue (u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value)
{
	u8 LOC_Status=DIO_OK;
	if(copy_u8PORT<=DIO_PORTD && copy_u8PIN<=DIO_PIN7){
		if(copy_u8Value == DIO_PIN_HIGH )
		{
				switch (copy_u8PORT)
				{
				case DIO_PORTA:SET_BIT(PORTA,copy_u8PIN);break;
				case DIO_PORTB:SET_BIT(PORTB,copy_u8PIN);break;
				case DIO_PORTC:SET_BIT(PORTC,copy_u8PIN);break;
				case DIO_PORTD:SET_BIT(PORTD,copy_u8PIN);break;
				}
			}
			else if(copy_u8Value == DIO_PIN_LOW ){
				switch (copy_u8PORT)
				{
				case DIO_PORTA:CLEAR_BIT(PORTA,copy_u8PIN);break;
				case DIO_PORTB:CLEAR_BIT(PORTB,copy_u8PIN);break;
				case DIO_PORTC:CLEAR_BIT(PORTC,copy_u8PIN);break;
				case DIO_PORTD:CLEAR_BIT(PORTD,copy_u8PIN);break;
				}
			}
	}
	else
	{
		LOC_Status=DIO_NOK;
	}
	return LOC_Status;
}
DIO_ERRORStatus DIO_EnumGetPinValue (u8 copy_u8PORT, u8 copy_u8PIN , u8 *copy_PtrData  )
{
	u8 LOC_Status=DIO_OK;
		if(copy_u8PORT<=DIO_PORTD && copy_u8PIN<=DIO_PIN7)
		{
			switch (copy_u8PORT)
			{
			case DIO_PORTA:*copy_PtrData = GET_BIT(PINA,copy_u8PIN);break;
			case DIO_PORTB:*copy_PtrData = GET_BIT(PINB,copy_u8PIN);break;
			case DIO_PORTC:*copy_PtrData = GET_BIT(PINC,copy_u8PIN);break;
			case DIO_PORTD:*copy_PtrData = GET_BIT(PIND,copy_u8PIN);break;
			}
		}
		else
		{
			LOC_Status=DIO_NOK;
		}
		return LOC_Status;
}
DIO_ERRORStatus DIO_EnumTogglePinValue  (u8 copy_u8PORT, u8 copy_u8PIN )
{

	u8 LOC_Status=DIO_OK;
		if(copy_u8PORT<=DIO_PORTD && copy_u8PIN<=DIO_PIN7)
		{
			switch (copy_u8PORT)
			{
			case DIO_PORTA: TOGGLE_BIT(PORTA,copy_u8PIN);break;
			case DIO_PORTB: TOGGLE_BIT(PORTB,copy_u8PIN);break;
			case DIO_PORTC: TOGGLE_BIT(PORTC,copy_u8PIN);break;
			case DIO_PORTD: TOGGLE_BIT(PORTD,copy_u8PIN);break;
			}
		}
		else
		{
			LOC_Status=DIO_NOK;
		}
		return LOC_Status;
}
void DIO_VoidSetPortDirection (u8 copy_u8PORT, u8 copy_u8Direction)
{
	if(copy_u8Direction == DIO_PORT_OUTPUT )
	{
		switch (copy_u8PORT)
		{
		case DIO_PORTA:DDRA =0xff;break;
		case DIO_PORTB:DDRB =0xff;break;
		case DIO_PORTC:DDRC =0xff;break;
		case DIO_PORTD:DDRD =0xff;break;
		}
	}
	else if(copy_u8Direction == DIO_PORT_INPUT )
	{
		switch (copy_u8PORT)
		{
		case DIO_PORTA:DDRA =0x00;break;
		case DIO_PORTB:DDRB =0x00;break;
		case DIO_PORTC:DDRC =0x00;break;
		case DIO_PORTD:DDRD =0x00;break;
		}
	}
}
void DIO_VoidSetPortValue     (u8 copy_u8PORT, u8 copy_u8Value)
{

	if(copy_u8Value == DIO_PORT_HIGH )
	{
		switch (copy_u8PORT)
		{
		case DIO_PORTA:PORTA =0xff;break;
		case DIO_PORTB:PORTB =0xff;break;
		case DIO_PORTC:PORTC =0xff;break;
		case DIO_PORTD:PORTD =0xff;break;
		}
	}
	else if(copy_u8Value == DIO_PORT_LOW )
	{
		switch (copy_u8PORT)
		{
		case DIO_PORTA:PORTA =0x00;break;
		case DIO_PORTB:PORTB =0x00;break;
		case DIO_PORTC:PORTC =0x00;break;
		case DIO_PORTD:PORTD =0x00;break;
		}
	}
}
u8   DIO_u8GetPortValue       (u8 copy_u8PORT )
{
	u8 LOC_u8Status=0x00 ;
	switch (copy_u8PORT)
	{
	case DIO_PORTA:LOC_u8Status= PINA;break;
	case DIO_PORTB:LOC_u8Status= PINB;break;
	case DIO_PORTC:LOC_u8Status= PINC;break;
	case DIO_PORTD:LOC_u8Status= PIND;break;
	}
	return LOC_u8Status;
}
void DIO_VoidTogglePortValue  (u8 copy_u8PORT )
{
	switch (copy_u8PORT)
	{
	case DIO_PORTA: PORTA=~PORTA;break;
	case DIO_PORTB: PORTB=~PORTB;break;
	case DIO_PORTC: PORTC=~PORTC;break;
	case DIO_PORTD: PORTD=~PORTD;break;
	}
}



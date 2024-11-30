
#include "../../common/Bit_Math.h"
#include "../../common/STD_types.h"
#include "DIO_interface.h"
#include "DIO_Private.h"


void DIO_voidSetPinDir(u8 copy_u8Reg,u8 pinNum,u8 pin_dir)
{
	if(pin_dir == Output)
	{
	switch(copy_u8Reg)
	{
		case GroupA : set_Bit(DDRA,pinNum); break;
		case GroupB : set_Bit(DDRB,pinNum); break;
		case GroupC : set_Bit(DDRC,pinNum); break;
		case GroupD : set_Bit(DDRD,pinNum); break;
	}
	}
	else if(pin_dir == Input)
	{
		switch(copy_u8Reg)
	{
		case GroupA : clr_Bit(DDRA,pinNum); break;
		case GroupB : clr_Bit(DDRB,pinNum); break;
		case GroupC : clr_Bit(DDRC,pinNum); break;
		case GroupD : clr_Bit(DDRD,pinNum); break;
	}
}
}
void DIO_voidSetPinValue(u8 copy_u8Reg,u8 pinNum,u8 pin_value)
{
	if(pin_value == High)
		{
		switch(copy_u8Reg)
		{
			case GroupA : set_Bit(PORTA,pinNum); break;
			case GroupB : set_Bit(PORTB,pinNum); break;
			case GroupC : set_Bit(PORTC,pinNum); break;
			case GroupD : set_Bit(PORTD,pinNum); break;
		}
		}
		else if(pin_value == Low)
		{
			switch(copy_u8Reg)
		{
			case GroupA : clr_Bit(PORTA,pinNum); break;
			case GroupB : clr_Bit(PORTB,pinNum); break;
			case GroupC : clr_Bit(PORTC,pinNum); break;
			case GroupD : clr_Bit(PORTD,pinNum); break;
		}
	}
}

u8 DIO_u8GetPinValue(u8 copy_u8Reg,u8 pinNum)
{
	u8 Local_u8Value = -1;
	switch(copy_u8Reg)
	{
	case GroupA:Local_u8Value = get_Bit(PINA,pinNum); break;
	case GroupB:Local_u8Value = get_Bit(PINB,pinNum); break;
	case GroupC:Local_u8Value = get_Bit(PINC,pinNum); break;
	case GroupD:Local_u8Value = get_Bit(PIND,pinNum); break;

	}
	return Local_u8Value;
}

void DIO_voidTogPinValue(u8 copy_u8Reg,u8 pinNum)
{
	switch(copy_u8Reg)
	{
	case GroupA: tog_Bit(PORTA,pinNum); break;
	case GroupB: tog_Bit(PORTB,pinNum); break;
	case GroupC: tog_Bit(PORTC,pinNum); break;
	case GroupD: tog_Bit(PORTD,pinNum); break;
}
}

void DIO_voidSetPortDir(u8 copy_u8Reg,u8 PortDir)
{
	switch(copy_u8Reg)
	{
	case GroupA: DDRA = PortDir; break;
	case GroupB: DDRB = PortDir; break;
	case GroupC: DDRC = PortDir; break;
	case GroupD: DDRD = PortDir; break;
	}
}

void DIO_voidSetPortValue(u8 copy_u8Reg,u8 PortValue)
{
	switch(copy_u8Reg)
	{
	case GroupA: PORTA = PortValue; break;
	case GroupB: PORTB = PortValue; break;
	case GroupC: PORTC = PortValue; break;
	case GroupD: PORTD = PortValue; break;
	}
}

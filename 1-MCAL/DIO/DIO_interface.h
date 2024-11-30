#ifndef DIO_interface_h
#define DIO_interface_h



void DIO_voidSetPinDir(u8 copy_u8Reg,u8 pinNum,u8 pin_dir);
void DIO_voidSetPinValue(u8 copy_u8Reg,u8 pinNum,u8 pin_value);
u8 DIO_u8GetPinValue(u8 copy_u8Reg,u8 pinNum);
void DIO_voidTogPinValue(u8 copy_u8Reg,u8 pinNum);
void DIO_voidSetPortDir(u8 copy_u8Reg,u8 PortNum);
void DIO_voidSetPortValue(u8 copy_u8Reg,u8 PortValue);


#define PIN0   0
#define PIN1   1
#define PIN2   2
#define PIN3   3
#define PIN4   4
#define PIN5   5
#define PIN6   6
#define PIN7   7


#define GroupA 1
#define GroupB 2
#define GroupC 3
#define GroupD 4

#define High   1
#define Low    0

#define High_Port  0xff
#define Low_Port   0

#define Output 1
#define Input  0

#define Output_Port 0xff
#define Input_Port  0

#endif

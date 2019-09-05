#include "STD_TYPE.h"
#include "BIT_CALC.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "OS_interface.h"
#include "App1.h"
#include "App2.h"


void Func1(void)
{
static int toggle_var=0;
if(toggle_var==0)
{
	GPIO_u8SetPinValue(PORTA_PIN0,GPIO_PIN_HIGH);
toggle_var=1;
}else
{
	GPIO_u8SetPinValue(PORTA_PIN0,GPIO_PIN_LOW);
	toggle_var=0;

}


}
void Func2(void)
{

	static int toggle_var=0;
	if(toggle_var==0)
	{
		GPIO_u8SetPinValue(PORTA_PIN1,GPIO_PIN_HIGH);

	toggle_var=1;
	}else
	{
		GPIO_u8SetPinValue(PORTA_PIN1,GPIO_PIN_LOW);
		toggle_var=0;
	}


}
int main()
{
RCC_VInit();
RCC_u8EnablePerphieral(PERIPHERAL_GPIO_PORTA);
RCC_u8EnablePerphieral(PERIPHERAL_GPIO_PORTB);
RCC_u8EnablePerphieral(PERIPHERAL_GPIO_PORTC);
GPIO_VInit();

GPIO_u8SetPinDirectionType(PORTA_PIN0,OUTPUT_50MHZ_GP_PUSHPULL);
GPIO_u8SetPinDirectionType(PORTA_PIN1,OUTPUT_50MHZ_GP_PUSHPULL);




App1_VInit();
App2_VInit();

SYSTICK_Init();

OS_VInit();
OS_VEnable();

while(1)
{
/*
GPIO_u8SetPinValue(PORTA_PIN0,GPIO_PIN_HIGH);
GPIO_u8SetPinValue(PORTA_PIN1,GPIO_PIN_HIGH);
*/
}
return 0;



}

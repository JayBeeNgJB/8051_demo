#include <f200.h>

// Define your hardware components
#define SWITCH_1 				P02
#define SWITCH_2 				P03
#define LED_BAR					P1
#define PRESSED					0x00
#define NOT_PRESSED				0x01
#define ENABLE_INTERRUPTS		0xE0
#define EXTERNAL_INTERRUPT_0	0x01
#define EXTERNAL_INTERRUPT_1	0x04
// Define starting condition
#define LED_BAR_DEFAULT			0xE0


void delay(unsigned long duration)
{
 while((duration--)!=0);
}

void switch1(void) interrupt 0
{
	delay(10000);
	while(SWITCH_1 == PRESSED);
	delay(10000);
	LED_BAR = (LED_BAR > 0x07) ? LED_BAR >> 1 : LED_BAR_DEFAULT;
}

void switch2(void) interrupt 2
{
	LED_BAR = LED_BAR_DEFAULT;
}
void setSystem();

void main()
{
	setSystem();
	IE = ENABLE_INTERRUPTS | EXTERNAL_INTERRUPT_0 | EXTERNAL_INTERRUPT_1; 
	LED_BAR = LED_BAR_DEFAULT;									 
	for(;;)														
	{
	}
}
#include <f200.h>

void delay(unsigned long duration)
{
 while((duration--)!=0);
}
void setSystem();

void main()
{
	setSystem();
	P1 = 0xE0;									// Set the Led to default position.[11100000] 

	for(;;)										// Loop this forever
	{
		if(P02 == 0)							// If SW1 is pressed
		{
			delay(10000);						// Delay to for deboucing
			while(P02 == 0);					// deboucing
			delay(10000);						// deboucing
			switch (P1)
			{
				case 0xE0:	P1 = 0x70;			// Set the Led Position from [11100000] to [01110000]
							break;
				case 0x70:	P1 = 0x38;			// Set the Led Position from [01110000] to [00111000]
							break;
				case 0x38:	P1 = 0x1C;			// Set the Led Position from [00111000] to [00011100]
							break;
				case 0x1C:	P1 = 0x0E;			// Set the Led Position from [00011100] to [00001110]
							break;
				case 0x0E:	P1 = 0x07;			// Set the Led Position from [00001110] to [00000111]
							break;
				case 0x07:	P1 = 0xE0;			// Set the Led Position from [00000111] to [11100000]
							break;
			}
							
		}
		if(P03 == 0)							// If SW2 is pressed
			P1 = 0xE0;							// Set LED Position to [11100000]
	}
}
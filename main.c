#include <p18f8722.h>  


#define b0000_0001 1
#define b0000_0010 2
#define b0000_0100 4
#define b0000_1000 8
#define b0001_0000 16
#define b0010_0000 32
#define b0100_0000 64
#define b1000_0000 128

 
#define reverse(num) ( \
    ((num & 0x01) << 7)  \
    | ((num & 0x02) << 5) \
    | ((num & 0x04) << 3) \
    | ((num & 0x08) << 1) \
    | ((num & 0x10) >> 1) \
    | ((num & 0x20) >> 3) \
    | ((num & 0x40) >> 5) \
    | ((num & 0x80) >> 7) \
)

#define led_format(input) ((~reverse(input)) ^ (~(0xff)))

void main (void)
{	
	int Counter = 0;
	int DoSomething = 0;
	
	ADCON1=0xff;	//Disable ADC
	
	// Column
	TRISE = 0x00;
	PORTE = 0xFF;

	TRISH = 0x00;
	PORTH = 0xFF;

	// Row
	TRISAbits.TRISA0 = 0;
	TRISAbits.TRISA1 = 0;
	TRISAbits.TRISA2 = 0;
	TRISAbits.TRISA3 = 0;
	TRISAbits.TRISA4 = 0;
	TRISAbits.TRISA5 = 0;

	PORTAbits.RA0 	 = 1;
	PORTAbits.RA1 	 = 1;
	PORTAbits.RA2 	 = 1;
	PORTAbits.RA3 	 = 1;
	PORTAbits.RA4 	 = 1;
	PORTAbits.RA5 	 = 1;

	TRISBbits.TRISB1 = 0;
	TRISBbits.TRISB2 = 0;
	TRISBbits.TRISB3 = 0;
	TRISBbits.TRISB4 = 0;
	TRISBbits.TRISB5 = 0;

	PORTBbits.RB1 	 = 1;
	PORTBbits.RB2 	 = 1;
	PORTBbits.RB3 	 = 1;
	PORTBbits.RB4 	 = 1;
	PORTBbits.RB5 	 = 1;

	TRISCbits.TRISC1 = 0;
	TRISCbits.TRISC2 = 0;
	TRISCbits.TRISC3 = 0;

	PORTCbits.RC1 	 = 1;
	PORTCbits.RC2 	 = 1;
	PORTCbits.RC3 	 = 1;

	TRISDbits.TRISD1 = 0;
	TRISDbits.TRISD2 = 0;
	TRISDbits.TRISD3 = 0;

	PORTDbits.RD1 	 = 1;
	PORTDbits.RD2 	 = 1;
	PORTDbits.RD3 	 = 1;

	TRISFbits.TRISF0 = 0;
	TRISFbits.TRISF1 = 0;
	TRISFbits.TRISF2 = 0;
	TRISFbits.TRISF3 = 0;
	TRISFbits.TRISF4 = 0;
	TRISFbits.TRISF5 = 0;

	PORTFbits.RF0 	 = 1;
	PORTFbits.RF1 	 = 1;
	PORTFbits.RF2 	 = 1;
	PORTFbits.RF3 	 = 1;
	PORTFbits.RF4 	 = 1;
	PORTFbits.RF5 	 = 1;

	TRISJbits.TRISJ0 = 0;
	TRISJbits.TRISJ1 = 0;
	TRISJbits.TRISJ2 = 0;
	TRISJbits.TRISJ3 = 0;
	TRISJbits.TRISJ4 = 0;
	TRISJbits.TRISJ5 = 0;
	TRISJbits.TRISJ6 = 0;
	TRISJbits.TRISJ7 = 0;

	PORTJbits.RJ0 	 = 1;
	PORTJbits.RJ1 	 = 1;
	PORTJbits.RJ2 	 = 1;
	PORTJbits.RJ3 	 = 1;
	PORTJbits.RJ4 	 = 1;
	PORTJbits.RJ5 	 = 1;	
	PORTJbits.RJ6 	 = 1;
	PORTJbits.RJ7	 = 1;


	while(1)
	{
		//============================
		// row 1
		//0x7F >> 0111 1111 >> 1000 0000 >> 0000 0001
		PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte

		//0xBF >> 1011 1111 >> 0100 0000 >> 0000 0010
		PORTH = led_format(b0000_0001); 		// Green Color IO Pin - Byte

		PORTJbits.RJ0 = 0; 	// Row On 
		for(Counter = 0; Counter<10000; Counter++)
		{
			DoSomething = 999;
		}
		PORTJbits.RJ0 = 1; 	// Row Off

		//============================
		// row 2
		PORTE = 0xBF; 		// Red Color   IO Pin - Byte
		//0000 0010 <<
		//0100 0000
		//8421 8421
		//1011 1111 >> BF
		PORTH = 0xFF; 		// Green Color IO Pin - Byte
		PORTJbits.RJ1 = 0; 	// Row On 
		for(Counter = 0; Counter<10000; Counter++)
		{
			DoSomething = 999;
		}
		PORTJbits.RJ1 = 1; 	// Row Off
	}
}

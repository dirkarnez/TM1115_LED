#include <p18f8722.h>  

#define b0000_0000 0
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

#define delay(amount) \
for(Counter = 0; Counter < amount; Counter++) \
{ \
	DoSomething = 999; \
}

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

	TRISCbits.TRISC0 = 0;
	TRISCbits.TRISC1 = 0;
	TRISCbits.TRISC2 = 0;
	TRISCbits.TRISC3 = 0;

	PORTCbits.RC0	 = 1;
	PORTCbits.RC1 	 = 1;
	PORTCbits.RC2 	 = 1;
	PORTCbits.RC3 	 = 1;

	TRISDbits.TRISD0 = 0;
	TRISDbits.TRISD1 = 0;
	TRISDbits.TRISD2 = 0;
	TRISDbits.TRISD3 = 0;

	PORTDbits.RD0 	 = 1;
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
// DM1
		//============================
		// row 1
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(b0000_0000); 		// Green Color IO Pin - Byte

		PORTJbits.RJ0 = 0; 	// Row On 
		delay(10);
		PORTJbits.RJ0 = 1; 	// Row Off

		//============================
		// row 2
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(b0000_0000); 		// Green Color IO Pin - Byte

		PORTJbits.RJ1 = 0; 	// Row On 
		delay(10);
		PORTJbits.RJ1 = 1; 	// Row Off
		
		//==========================
		// row 3
		//PORTE = led_format(b0000_000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(b0000_0001); 		// Green Color IO Pin - Byte

		PORTJbits.RJ2 = 0; 	// Row On 
		delay(10);
		PORTJbits.RJ2 = 1; 	// Row Off

		//==========================
		// row 4
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte

		PORTH = led_format((b0000_0001 | b0000_0100 | b0000_1000 | b0001_0000 | b0010_0000 | b0100_0000));
		PORTJbits.RJ3 = 0; 	// Row On 
		delay(10);
		PORTJbits.RJ3 = 1; 	// Row Off

		//==========================
		// row 5
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format((b0000_0001 | b0001_0000));

		PORTJbits.RJ7 = 0; 	// Row On 
		delay(10);
		PORTJbits.RJ7 = 1; 	// Row Off

		//==========================
		// row 6
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format((b0000_0001 | b0001_0000));

		PORTJbits.RJ6 = 0; 	// Row On 
		delay(10);
		PORTJbits.RJ6 = 1; 	// Row Off

		//==========================
		// row 7
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format((b0000_0001 | b0001_0000));

		PORTJbits.RJ5 = 0; 	// Row On 
		delay(10);
		PORTJbits.RJ5 = 1; 	// Row Off

		//==========================
		// row 8
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format((b0000_0001 | b0000_0100 | b0000_1000 | b0001_0000 | b0010_0000 | b0100_0000));

		PORTJbits.RJ4 = 0; 	// Row On 
		delay(10);
		PORTJbits.RJ4 = 1; 	// Row Off

// DM2
		//============================
		// row 1
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(b0000_0000); 		// Green Color IO Pin - Byte

		PORTAbits.RA1 = 0; 	// Row On 
		delay(10);
		PORTAbits.RA1 = 1; 	// Row Off

		//============================
		// row 2
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(b0000_0100);

		PORTAbits.RA2 = 0; 	// Row On 
		delay(10);
		PORTAbits.RA2 = 1; 	// Row Off
		
		//==========================
		// row 3
		//PORTE = led_format(b0000_000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b1000_0000 
				| b0100_0000
				| b0010_0000
				| b0001_0000
				| b0000_1000
				| b0000_0100
				| b0000_0010)); 		// Green Color IO Pin - Byte

		PORTAbits.RA3 = 0; 	// Row On 
		delay(10);
		PORTAbits.RA3 = 1; 	// Row Off

		//==========================
		// row 4
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte

		PORTH = led_format(
				(b0010_0000
				| b0000_0100)); 		// Green Color IO Pin - Byte

		PORTAbits.RA4 = 0; 	// Row On 
		delay(10);
		PORTAbits.RA4 = 1; 	// Row Off
		//==========================
		// row 5
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b0010_0000
				| b0000_0100)); 		// Green Color IO Pin - Byte

		PORTCbits.RC2 = 0; 	// Row On 
		delay(10);
		PORTCbits.RC2 = 1; 	// Row Off

		//==========================
		// row 6
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b1000_0000 
				| b0100_0000
				| b0010_0000
				| b0001_0000
				| b0000_1000
				| b0000_0100)); 		// Green Color IO Pin - Byte

		PORTCbits.RC1 = 0; 	// Row On 
		delay(10);
		PORTCbits.RC1 = 1; 	// Row Off

		//==========================
		// row 7
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b0010_0000
				| b0000_0100)); 		// Green Color IO Pin - Byte

		PORTCbits.RC0 = 0; 	// Row On 
		delay(10);
		PORTCbits.RC0 = 1; 	// Row Off

		//==========================
		// row 8
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b0010_0000
				| b0000_0100)); 		// Green Color IO Pin - Byte

		PORTAbits.RA5 = 0; 	// Row On 
		delay(10);
		PORTAbits.RA5 = 1; 	// Row Off



// DM3
		//============================
		// row 1
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b0001_0000
				| b0000_0001)); 		// Green Color IO Pin - Byte

		PORTBbits.RB1 = 0; 	// Row On 
		delay(10);
		PORTBbits.RB1 = 1; 	// Row Off

		//============================
		// row 2
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(b0001_0000); 		// Green Color IO Pin - Byte

		PORTBbits.RB2 = 0; 	// Row On 
		delay(10);
		PORTBbits.RB2 = 1; 	// Row Off
		
		//==========================
		// row 3
		//PORTE = led_format(b0000_000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b0001_0000
				| b0000_0100)); 		// Green Color IO Pin - Byte

		PORTBbits.RB3 = 0; 	// Row On 
		delay(10);
		PORTBbits.RB3 = 1; 	// Row Off

		//==========================
		// row 4
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b0001_0000
				| b0000_1000
				| b0000_0001)); 		// Green Color IO Pin - Byte

		PORTBbits.RB4 = 0; 	// Row On 
		delay(10);
		PORTBbits.RB4 = 1; 	// Row Off

		//==========================
		// row 5
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				( b0100_0000
				| b0010_0000
				| b0001_0000)); 		// Green Color IO Pin - Byte

		PORTAbits.RA0 = 0; 	// Row On 
		delay(10);
		PORTAbits.RA0 = 1; 	// Row Off

		//==========================
		// row 6
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(b0000_0000); 		// Green Color IO Pin - Byte

		PORTFbits.RF5 = 0; 	// Row On 
		delay(10);
		PORTFbits.RF5 = 1; 	// Row Off

		//==========================
		// row 7
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b0000_0100
				| b0000_0010
				| b0000_0001)); 		// Green Color IO Pin - Byte

		PORTFbits.RF4 = 0; 	// Row On 
		delay(10);
		PORTFbits.RF4 = 1; 	// Row Off

		//==========================
		// row 8
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(b0000_0000); 		// Green Color IO Pin - Byte

		PORTBbits.RB5 = 0; 	// Row On 
		delay(10);
		PORTBbits.RB5 = 1; 	// Row Off

// DM4
		//============================
		// row 1
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b1000_0000
				| b0100_0000
				| b0010_0000
				| b0001_0000
				| b0000_1000
				| b0000_0100)); 		// Green Color IO Pin - Byte

		PORTDbits.RD0 = 0; 	// Row On 
		delay(10);
		PORTDbits.RD0 = 1; 	// Row Off

		//============================
		// row 2
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(b0010_0000); 		// Green Color IO Pin - Byte

		PORTDbits.RD1 = 0; 	// Row On 
		delay(10);
		PORTDbits.RD1 = 1; 	// Row Off
		
		//==========================
		// row 3
		//PORTE = led_format(b0000_000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b0010_0000
				| b0000_0100)); 		// Green Color IO Pin - Byte

		PORTDbits.RD2 = 0; 	// Row On 
		delay(10);
		PORTDbits.RD2 = 1; 	// Row Off

		//==========================
		// row 4
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b1000_0000
				| b0100_0000
				| b0010_0000
				| b0001_0000
				| b0000_1000
				| b0000_0100
				| b0000_0010)); 		// Green Color IO Pin - Byte

		PORTDbits.RD3 = 0; 	// Row On 
		delay(10);
		PORTDbits.RD3 = 1; 	// Row Off

		//==========================
		// row 5
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(b0010_0000); 		// Green Color IO Pin - Byte

		PORTFbits.RF3 = 0; 	// Row On 
		delay(10);
		PORTFbits.RF3 = 1; 	// Row Off

		//==========================
		// row 6
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(b0010_0000); 		// Green Color IO Pin - Byte

		PORTFbits.RF2 = 0; 	// Row On 
		delay(10);
		PORTFbits.RF2 = 1; 	// Row Off

		//==========================
		// row 7
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(
				(b1000_0000
				| b0100_0000
				| b0010_0000
				| b0001_0000
				| b0000_1000
				| b0000_0100
				| b0000_0010
				| b0000_0001)); 		// Green Color IO Pin - Byte
		
		PORTFbits.RF1 = 0; 	// Row On 
		delay(10);
		PORTFbits.RF1 = 1; 	// Row Off

		//==========================
		// row 8
		//PORTE = led_format(b0000_1000); 		// Red Color   IO Pin - Byte
		PORTH = led_format(b0000_0000); 		// Green Color IO Pin - Byte

		PORTFbits.RF0 = 0; 	// Row On 
		delay(10);
		PORTFbits.RF0 = 1; 	// Row Off
	}
}

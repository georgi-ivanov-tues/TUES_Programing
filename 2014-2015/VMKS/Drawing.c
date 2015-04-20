#include <basedef.h>
#include <Board.h>
#include <stdio.h>

#include <fixedsys.h>
#include <lcd_GE8.h>

//#include "bmp.h"

void Delay (unsigned long a) {while (--a!=0);}
/*
void DrawShit(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4, Color_t border_color, Color_t fill_color) {
	int i = 0;
	
	Delay(5000000);
	LCDSetLine(x2, y2, x4, y4, border_color);
	Delay(5000000);
	LCDSetLine(x3, y3, x4, y4, border_color);
	LCDSetLine(x3, y3+1, x4, y4+1, border_color);
	Delay(5000000);
	LCDSetLine(x1, y1, x3, y3, border_color);
	Delay(5000000);
	LCDSetLine(x1, y1, x2, y2, border_color);
	LCDSetLine(x1, y1+1, x2, y2+1, border_color);
	Delay(5000000);

	
	for(i = 0; i < y4-y2 - 2; i++) {
		 LCDSetLine(x1 + 3 + i, y1 + 2 + i, x2 + 1 + i, y2 +2 + i, fill_color);
	}	
}

void AnimateCircle(int x1, int y1, int x2, int y2, Color_t color) {
	int x_step = (x2 - x1) / 20;
	int y_step = (y2 - y1) / 20;
	while(true) {
		LCDSetCircle(x1, y1,10,color);
		Delay(500000);
		LCDSetCircle(x1, y1,10,LCD_COLOR_WHITE);
		x1 += x_step;
		y1 += y_step;
		if(x1 == x2 && y1 == y2) {
		 	break;
		} 	
	}
	LCDSetCircle(x1, y1,10,color);
}
*/

void DrawGameField(Color_t lineColor){
	LCDSetLine(20, 20, 110, 20, lineColor);
	LCDSetLine(20, 50, 110, 50, lineColor);
	LCDSetLine(20, 80, 110, 80, lineColor);
	LCDSetLine(20, 110, 110, 110, lineColor);

	LCDSetLine(20, 20, 20, 110, lineColor);
	LCDSetLine(50, 20, 50, 110, lineColor);
	LCDSetLine(80, 20, 80, 110, lineColor);
	LCDSetLine(110, 20, 110, 110, lineColor);
}

void DrawIndicator(short x, short y, Color_t lineColor) {
 	int x_coord = 20 + 30*x;
	int y_coord = 20 + 30*y;

	LCDSetLine(x_coord + 3, y_coord + 3, x_coord + 8, y_coord + 3, lineColor);
	LCDSetLine(x_coord + 3, y_coord + 3, x_coord + 3, y_coord + 8, lineColor);

	LCDSetLine(x_coord + 3, y_coord + 27, x_coord + 3, y_coord + 22, lineColor);
	LCDSetLine(x_coord + 3, y_coord + 27, x_coord + 8, y_coord + 27, lineColor);

	LCDSetLine(x_coord + 27, y_coord + 3, x_coord + 22, y_coord + 3, lineColor);
	LCDSetLine(x_coord + 27, y_coord + 3, x_coord + 27, y_coord + 8, lineColor);
	
	LCDSetLine(x_coord + 27, y_coord + 27, x_coord + 22, y_coord + 27, lineColor);
	LCDSetLine(x_coord + 27, y_coord + 27, x_coord + 27, y_coord + 22, lineColor);
}

void DrawX(short x, short y, Color_t lineColor) {
 	int x_coord = 20 + 30*x;
	int y_coord = 20 + 30*y;

	LCDSetLine(x_coord + 5, y_coord + 5, x_coord + 25, y_coord + 25, lineColor);
	LCDSetLine(x_coord + 5, y_coord + 25, x_coord + 25, y_coord + 5, lineColor);
}

void DrawO(short x, short y, Color_t lineColor) {
 	int x_coord = 20 + 30*x;
	int y_coord = 20 + 30*y;

	LCDSetCircle(x_coord + 15, y_coord + 15, 10, lineColor);
}

void DrawWinningLine(short x1, short y1, short x2, short y2, Color_t lineColor) {
 	int x_begin = 20 + 30*x1;
	int y_begin = 20 + 30*y1;
	int x_end = 20 + 30*x2;
	int y_end = 20 + 30*y2;

	int x_begin_offset, x_end_offset, y_begin_offset, y_end_offset;

	if(x1 == x2) {
	 	x_begin_offset = 15;
		x_end_offset = 15;
		y_begin_offset = 5;
		y_end_offset = 25;
	} else if(y1 < y2) {
		x_begin_offset = 5;
		x_end_offset = 25;
	 	y_begin_offset = 5;
		y_end_offset = 25;
	} else if(y1 > y2) {
		x_begin_offset = 5;
		x_end_offset = 25;
	 	y_begin_offset = 25;
		y_end_offset = 5;
	} else {
		x_begin_offset = 5;
		x_end_offset = 25;
	 	y_begin_offset = 15;
		y_end_offset = 15;
	}
	
	LCDSetLine(x_begin + x_begin_offset, y_begin + y_begin_offset, x_end + x_end_offset, y_end + y_end_offset, lineColor);
	if(x1 == x2) {
		LCDSetLine(x_begin + x_begin_offset + 1 , y_begin + y_begin_offset, x_end + x_end_offset + 1 , y_end + y_end_offset, lineColor);
		LCDSetLine(x_begin + x_begin_offset - 1, y_begin + y_begin_offset, x_end + x_end_offset - 1 , y_end + y_end_offset, lineColor);
	} else {
		LCDSetLine(x_begin + x_begin_offset , y_begin + y_begin_offset - 1, x_end + x_end_offset , y_end + y_end_offset - 1, lineColor);
		LCDSetLine(x_begin + x_begin_offset , y_begin + y_begin_offset + 1, x_end + x_end_offset , y_end + y_end_offset + 1, lineColor);
	}					  
}

// 172.16.15.159:8080

int main()
{
	char		msg[100];
	Color_t		bckgColor=LCD_COLOR_WHITE;
	Color_t		lineColor=LCD_COLOR_BLACK;
	int i = 10, current_x, current_y;
	
	AT91PS_PIO    p_pPioA  = AT91C_BASE_PIOA;
	AT91PS_PIO    p_pPioB  = AT91C_BASE_PIOB;
	AT91PS_PMC    p_pPMC   = AT91C_BASE_PMC;
	AT91PS_SYS    p_pSys   = AT91C_BASE_SYS;

	AT91F_LowLevel_Init();

	//enable the clock of the PIO
	p_pPMC->PMC_PCER = 1 << AT91C_ID_PIOA;
	//enable the clock of the PIO
	p_pPMC->PMC_PCER = 1 << AT91C_ID_PIOB;
	
	// GPIO init
	p_pPioA->PIO_ODR    = 0xffffffff;   // All as input
	p_pPioB->PIO_ODR    = 0xffffffff;   // All as input
	p_pSys->PIOA_PPUDR  = 0xffffffff;   // Disable Pull-up resistor
	p_pSys->PIOB_PPUDR  = 0xffffffff;   // Disable Pull-up resistor

#define	BIT_SW1 0x01000000
#define	BIT_SW2 0x02000000
#define	BIT_SW3 0x03000000

#define	BIT_JUP 0x0000200
#define	BIT_JDOWN 0x0000100
#define	BIT_JLEFT 0x000080

#define	BIT_JRIGHT 0x0004000
#define	BIT_JPUSH 0x00008000


	// BUTTON SW1
	p_pPioB->PIO_ODR |= BIT_SW1; //Configure in Input
	p_pPioB->PIO_PER |= BIT_SW1; //Enable PB24

	// BUTTON SW2
	p_pPioB->PIO_ODR |= BIT_SW2; //Configure in Input
	p_pPioB->PIO_PER |= BIT_SW2; //Enable PB25
											   
	// BUTTON SW2
	p_pPioB->PIO_ODR |= BIT_SW3; //Configure in Input
	p_pPioB->PIO_PER |= BIT_SW3; //Enable PB25	  PB24

  
	// JOYSTICK PUSH 
	p_pPioA->PIO_ODR |= BIT_JPUSH; //Configure in Input
	p_pPioA->PIO_PER |= BIT_JPUSH; //Enable PA8

	// JOYSTICK LEFT 
	p_pPioA->PIO_ODR |= BIT_JLEFT; //Configure in Input
	p_pPioA->PIO_PER |= BIT_JLEFT; //Enable PA8
	
	// JOYSTICK RIGHT 
	p_pPioA->PIO_ODR |= BIT_JRIGHT; //Configure in Input
	p_pPioA->PIO_PER |= BIT_JRIGHT; //Enable PA8
	
	// JOYSTICK UP 
	p_pPioA->PIO_ODR |= BIT_JUP; //Configure in Input
	p_pPioA->PIO_PER |= BIT_JUP; //Enable PA8

	// JOYSTICK DWON 
	p_pPioA->PIO_ODR |= BIT_JDOWN; //Configure in Input
	p_pPioA->PIO_PER |= BIT_JDOWN; //Enable PA8	

	

	/* any other variables you need ... */
	// ...

	/* Initialize the Atmel AT91SAM7X256 (watchdog, PLL clock, default interrupts, etc.) */

	InitLCD();
	LCD_ClearScreen( bckgColor );

	DrawGameField(lineColor);
	//DrawIndicator(2, 2, lineColor);
	DrawX(1, 1, lineColor);
	DrawO(1, 2, lineColor);
	DrawX(0, 0, lineColor);
	DrawO(0, 2, lineColor);
	DrawX(2, 2, lineColor);
	DrawWinningLine(0, 0, 2, 2, LCD_COLOR_RED);
	/* put other initializations here ... */
	// ...


	current_x = 0;
	current_y = 0;
	while ( true ) {	  
	    // check button SW3
		
		/*if((p_pPioA->PIO_PDSR) & BIT_JPUSH){
			LCD_WriteString("No Push", &Fixedsys_descriptor, 2, 20, LCD_COLOR_WHITE, LCD_COLOR_BLUE);	
		}
		else{
			LCD_WriteString("PUSHEDDDDDD", &Fixedsys_descriptor, 2, 20, LCD_COLOR_WHITE, LCD_COLOR_BLUE);		
		}*/

		if(((p_pPioA->PIO_PDSR) & BIT_JUP)){
			
			//LCD_WriteString("No UP", &Fixedsys_descriptor, 2, 40, LCD_COLOR_WHITE, LCD_COLOR_BLUE);	
		}
		else{
			current_y--;
			//LCD_WriteString("UPPPPPPPPPP", &Fixedsys_descriptor, 2, 40, LCD_COLOR_WHITE, LCD_COLOR_BLUE);		
		} 

		if(((p_pPioA->PIO_PDSR) & BIT_JLEFT)){
			
			//LCD_WriteString("No LEFT", &Fixedsys_descriptor, 2, 60, LCD_COLOR_WHITE, LCD_COLOR_BLUE);	
		}
		else{
			current_x--;
			//LCD_WriteString("LEFTTTTTTTT", &Fixedsys_descriptor, 2, 60, LCD_COLOR_WHITE, LCD_COLOR_BLUE);		
		} 

		if(((p_pPioA->PIO_PDSR) & BIT_JRIGHT)){
			
			//LCD_WriteString("No RIGHT", &Fixedsys_descriptor, 2, 80, LCD_COLOR_WHITE, LCD_COLOR_BLUE);	
		}
		else{
			current_x++;
			//LCD_WriteString("RIGHTTTTTTT", &Fixedsys_descriptor, 2, 80, LCD_COLOR_WHITE, LCD_COLOR_BLUE);		
		} 

		if((p_pPioA->PIO_PDSR) & BIT_JDOWN){
			
			//LCD_WriteString("No DOWN", &Fixedsys_descriptor, 2, 100, LCD_COLOR_WHITE, LCD_COLOR_BLUE);	
		}
		else{
			current_y++;
			//LCD_WriteString("DOWNNNNNNNN", &Fixedsys_descriptor, 2, 100, LCD_COLOR_WHITE, LCD_COLOR_BLUE);		
		} 

		DrawIndicator(current_x, current_y, lineColor);
		Delay(1000000);
	}
	/* enable interrupts */
	//AT91F_Finalize_Init();

	/* add your program here ... */


	//DrawShit(25, 50, 50, 50, 75, 100, 100, 100, LCD_COLOR_BLACK, LCD_COLOR_RED);
	//AnimateCircle(20, 120, 40, 100, LCD_COLOR_BLACK);

	//LCD_WriteString("   sdfhfgdhg",     FONT_DESCRIPTOR, 10, 25, LCD_COLOR_BLACK, bckgColor);
	//sprintf(msg, "Hello %d!", 5); LCD_WriteString(msg, FONT_DESCRIPTOR, 10, 60, LCD_COLOR_BLACK, bckgColor);
	//LCD_WriteString("    L114E",     FONT_DESCRIPTOR, 10, 90, LCD_COLOR_BLACK, bckgColor);
	//Delay(5000000);

	//LCDShowImage130x130(bmp);

	/* your main loop ... */
	while ( true )
	{
		//...
	}
	
	/* The answer of every question in the universe */
	return 42;
}

#include <basedef.h>
#include <Board.h>
#include <stdio.h>

#include <fixedsys.h>
#include <lcd_GE8.h>

//#include "bmp.h"

void Delay (unsigned long a) {while (--a!=0);}

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

int main()
{
	char		msg[100];
	Color_t		bckgColor=LCD_COLOR_WHITE;
	int i = 10;

	/* any other variables you need ... */
	// ...

	/* Initialize the Atmel AT91SAM7X256 (watchdog, PLL clock, default interrupts, etc.) */
	AT91F_LowLevel_Init();

	InitLCD();
	LCD_ClearScreen( bckgColor );

	/* put other initializations here ... */
	// ...

	/* enable interrupts */
	//AT91F_Finalize_Init();

	/* add your program here ... */


	DrawShit(25, 50, 50, 50, 75, 100, 100, 100, LCD_COLOR_BLACK, LCD_COLOR_RED);
	AnimateCircle(20, 120, 40, 100, LCD_COLOR_BLACK);

	//LCD_WriteString("   sdfhfgdhg",     FONT_DESCRIPTOR, 10, 25, LCD_COLOR_BLACK, bckgColor);
	//sprintf(msg, "Hello %d!", 5); LCD_WriteString(msg, FONT_DESCRIPTOR, 10, 60, LCD_COLOR_BLACK, bckgColor);
	//LCD_WriteString("    L114E",     FONT_DESCRIPTOR, 10, 90, LCD_COLOR_BLACK, bckgColor);
	Delay(5000000);

	//LCDShowImage130x130(bmp);

	/* your main loop ... */
	while ( true )
	{
		//...
	}
	
	/* The answer of every question in the universe */
	return 42;
}

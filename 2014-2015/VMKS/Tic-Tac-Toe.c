#include <basedef.h>
#include <Board.h>
#include <stdio.h>

#include <fixedsys.h>
#include <lcd_GE8.h>

//#include "bmp.h"

int field[3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
Color_t		bckgColor=LCD_COLOR_WHITE;
Color_t		lineColor=LCD_COLOR_BLACK;

void Delay (unsigned long a) {while (--a!=0);}

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

void DrawWinner(int winner) {
 	if(winner == 1) {
	 	LCD_WriteString("Player 1 Wins!", &Fixedsys_descriptor, 10, 3, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
	} else if(winner == -1) {
	 	LCD_WriteString("Player 2 Wins!", &Fixedsys_descriptor, 10, 3, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
	} else {
	 	LCD_WriteString("It's a draw!", &Fixedsys_descriptor, 17, 3, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
	}
}

void DrawMenu() {
	LCD_WriteString("TIC-TAC-TOE", &Fixedsys_descriptor, 20, 20, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
	LCD_WriteString("Single Player", &Fixedsys_descriptor, 20, 50, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
	LCD_WriteString("Local Game", &Fixedsys_descriptor, 20, 70, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
	LCD_WriteString("Host Game", &Fixedsys_descriptor, 20, 90, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
	LCD_WriteString("Join Game", &Fixedsys_descriptor, 20, 110, LCD_COLOR_BLACK, LCD_COLOR_WHITE);
}

void DrawMenuIndicator(int x, Color_t lineColor) {
	int y_offset = 50 + x * 20;
	LCDSetLine(12, y_offset + 7, 15, y_offset + 4, lineColor);
	LCDSetLine(12, y_offset + 7, 15, y_offset + 10, lineColor);
	LCDSetLine(15, y_offset + 4, 18, y_offset + 7, lineColor);
	LCDSetLine(15, y_offset + 10, 18, y_offset + 7, lineColor);
}

int determineWinner() {
	int line = field[0][0] + field[1][0] + field[2][0]; 	

	if(line == 3) {
		DrawWinningLine(0, 0, 2, 0, LCD_COLOR_RED);
		DrawWinner(1);
		return 1;
	} else if (line == -3) {
	 	DrawWinningLine(0, 0, 2, 0, LCD_COLOR_RED);
		DrawWinner(-1);
		return 1;
	}

	line = field[0][1] + field[1][1] + field[2][1];

	if(line == 3) {
		DrawWinningLine(0, 1, 2, 1, LCD_COLOR_RED);
		DrawWinner(1);
		return 1;
	} else if (line == -3) {
	 	DrawWinningLine(0, 1, 2, 1, LCD_COLOR_RED);
		DrawWinner(-1);
		return 1;
	}

	line = field[0][2] + field[1][2] + field[2][2];

	if(line == 3) {
		DrawWinningLine(0, 2, 2, 2, LCD_COLOR_RED);
		DrawWinner(1);
		return 1;
	} else if (line == -3) {
	 	DrawWinningLine(0, 2, 2, 2, LCD_COLOR_RED);
		DrawWinner(-1);
		return 1;
	}

	line = field[0][0] + field[0][1] + field[0][2];

	if(line == 3) {
		DrawWinningLine(0, 0, 0, 2, LCD_COLOR_RED);
		DrawWinner(1);
		return 1;
	} else if (line == -3) {
	 	DrawWinningLine(0, 0, 0, 2, LCD_COLOR_RED);
		DrawWinner(-1);
		return 1;
	}

	line = field[1][0] + field[1][1] + field[1][2];

	if(line == 3) {
		DrawWinningLine(1, 0, 1, 2, LCD_COLOR_RED);
		DrawWinner(1);
		return 1;
	} else if (line == -3) {
	 	DrawWinningLine(1, 0, 1, 2, LCD_COLOR_RED);
		DrawWinner(-1);
		return 1;
	}

	line = field[2][0] + field[2][1] + field[2][2];

	if(line == 3) {
		DrawWinningLine(2, 0, 2, 2, LCD_COLOR_RED);
		DrawWinner(1);
		return 1;
	} else if (line == -3) {
	 	DrawWinningLine(2, 0, 2, 2, LCD_COLOR_RED);
		DrawWinner(-1);
		return 1;
	}

	line = field[0][0] + field[1][1] + field[2][2];

	if(line == 3) {
		DrawWinningLine(0, 0, 2, 2, LCD_COLOR_RED);
		DrawWinner(1);
		return 1;
	} else if (line == -3) {
	 	DrawWinningLine(0, 0, 2, 2, LCD_COLOR_RED);
		DrawWinner(-1);
		return 1;
	}

	line = field[0][2] + field[1][1] + field[2][0];

	if(line == 3) {
		DrawWinningLine(0, 2, 2, 0, LCD_COLOR_RED);
		DrawWinner(1);
		return 1;
	} else if (line == -3) {
	 	DrawWinningLine(0, 2, 2, 0, LCD_COLOR_RED);
		DrawWinner(-1);
		return 1;
	}

	return 0;
}

void PlaySinglePlayer() {
	return;
}

void PlayLocal() {
	int current_x, current_y, turn, remaining;

	LCD_ClearScreen( bckgColor );
	DrawGameField(lineColor);

	current_x = 0;
	current_y = 0;
	remaining = 9;
	turn = 1;
	while ( true ) {
		DrawIndicator(current_x, current_y, LCD_COLOR_WHITE);
		
		if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
		else{
			if(field[current_x][current_y] == 0) {
			 	field[current_x][current_y] = turn;
				remaining--;		   
				if(turn == 1) {
					DrawX(current_x, current_y, lineColor);
					turn = -1;
				} else {
				 	DrawO(current_x, current_y, lineColor);
					turn = 1;
				}
				if(determineWinner() == 1) {
				 	Delay(1000000);
					while(true) {
						if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
						else{
							return;
						}
					}
				} else if(remaining == 0) {
					DrawWinner(0);
					Delay(1000000);
					while(true) {
						if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
						else{
							return;
						}
					}
				}
			}	
		}

		if(((p_pPioA->PIO_PDSR) & BIT_JUP)){}
		else{
			if(current_y == 0) {
			 	current_y = 2;
			} else {
				current_y--;
			}		
		} 

		if(((p_pPioA->PIO_PDSR) & BIT_JLEFT)){}
		else{
			if(current_x == 0){
				current_x = 2;
			}else{
				current_x--;
			}
		} 

		if(((p_pPioA->PIO_PDSR) & BIT_JRIGHT)){}
		else{
			if(current_x == 2){
				current_x = 0;
			}else{
				current_x++;
			}
		} 

		if((p_pPioA->PIO_PDSR) & BIT_JDOWN){}
		else{
			if(current_y == 2){
				current_y = 0;
			}else{
				current_y++;
			}	
		} 

		DrawIndicator(current_x, current_y, lineColor);
		Delay(1000000);
	}
}

void HostGame() {
	int current_x, current_y, remaining;

	LCD_ClearScreen( bckgColor );
	LCD_WriteString("Looking for an opponent...", &Fixedsys_descriptor, 3, 20, LCD_COLOR_BLACK, LCD_COLOR_WHITE);

	//Send message...

	//Wait to receive message

	LCD_ClearScreen( bckgColor );
	DrawGameField(lineColor);
	
	current_x = 0;
	current_y = 0;
	remaining = 9;
	while ( true ) {
		DrawIndicator(current_x, current_y, LCD_COLOR_WHITE);
		
		if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
		else{
			if(field[current_x][current_y] == 0) {
			 	field[current_x][current_y] = 1;
				remaining--;		   
				DrawX(current_x, current_y, lineColor);
				if(determineWinner() == 1) {
				 	Delay(1000000);
					while(true) {
						if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
						else{
							return;
						}
					}
				} else if(remaining == 0) {
					DrawWinner(0);
					Delay(1000000);
					while(true) {
						if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
						else{
							return;
						}
					}
				} else {
					//current_x = wait to receive x
					//current_y = wait to receive y
					field[current_x][current_y] = -1;
					remaining--;
					DrawO(current_x, current_y, lineColor);
					if(determineWinner() == 1) {
				 		Delay(1000000);
						while(true) {
							if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
							else{
								return;
							}
						}
					} 
				}
			}	
		}

		if(((p_pPioA->PIO_PDSR) & BIT_JUP)){}
		else{
			if(current_y == 0) {
			 	current_y = 2;
			} else {
				current_y--;
			}		
		} 

		if(((p_pPioA->PIO_PDSR) & BIT_JLEFT)){}
		else{
			if(current_x == 0){
				current_x = 2;
			}else{
				current_x--;
			}
		} 

		if(((p_pPioA->PIO_PDSR) & BIT_JRIGHT)){}
		else{
			if(current_x == 2){
				current_x = 0;
			}else{
				current_x++;
			}
		} 

		if((p_pPioA->PIO_PDSR) & BIT_JDOWN){}
		else{
			if(current_y == 2){
				current_y = 0;
			}else{
				current_y++;
			}	
		} 

		DrawIndicator(current_x, current_y, lineColor);
		Delay(1000000);
	}	
}

void JoinGame() {
	int current_x, current_y, remaining;

	LCD_ClearScreen( bckgColor );
	LCD_WriteString("Looking for an opponent...", &Fixedsys_descriptor, 3, 20, LCD_COLOR_BLACK, LCD_COLOR_WHITE);

	//Wait to receive message

	//Send message

	LCD_ClearScreen( bckgColor );
	DrawGameField(lineColor);
	
	current_x = 0;
	current_y = 0;
	remaining = 9;

	//current_x = wait to receive x;
	//current_y = wait to receive y;
	field[current_x][current_y] = 1;
	remaining--;
	DrawX(current_x, current_y, lineColor);
	while ( true ) {
		DrawIndicator(current_x, current_y, LCD_COLOR_WHITE);
		
		if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
		else{
			if(field[current_x][current_y] == 0) {
			 	field[current_x][current_y] = -1;
				remaining--;		   
				DrawO(current_x, current_y, lineColor);
				if(determineWinner() == 1) {
				 	Delay(1000000);
					while(true) {
						if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
						else{
							return;
						}
					}
				} else if(remaining == 0) {
					DrawWinner(0);
					Delay(1000000);
					while(true) {
						if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
						else{
							return;
						}
					}
				} else {
					//current_x = wait to receive x
					//current_y = wait to receive y
					field[current_x][current_y] = 1;
					remaining--;
					DrawX(current_x, current_y, lineColor);
					if(determineWinner() == 1) {
				 		Delay(1000000);
						while(true) {
							if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
							else{
								return;
							}
						}
					} else if(remaining == 0) {
						DrawWinner(0);
						Delay(1000000);
						while(true) {
							if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
							else{
								return;
							}
						}
					}
				}
			}	
		}

		if(((p_pPioA->PIO_PDSR) & BIT_JUP)){}
		else{
			if(current_y == 0) {
			 	current_y = 2;
			} else {
				current_y--;
			}		
		} 

		if(((p_pPioA->PIO_PDSR) & BIT_JLEFT)){}
		else{
			if(current_x == 0){
				current_x = 2;
			}else{
				current_x--;
			}
		} 

		if(((p_pPioA->PIO_PDSR) & BIT_JRIGHT)){}
		else{
			if(current_x == 2){
				current_x = 0;
			}else{
				current_x++;
			}
		} 

		if((p_pPioA->PIO_PDSR) & BIT_JDOWN){}
		else{
			if(current_y == 2){
				current_y = 0;
			}else{
				current_y++;
			}	
		} 

		DrawIndicator(current_x, current_y, lineColor);
		Delay(1000000);
	}
}

int main()
{
	int menu_x;
	
	
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

	/* Initialize the Atmel AT91SAM7X256 (watchdog, PLL clock, default interrupts, etc.) */

	InitLCD();
	
	while(true) {
		LCD_ClearScreen( bckgColor );

		DrawMenu();
		menu_x = 0;
		while ( true ) {	  
			DrawMenuIndicator(menu_x, LCD_COLOR_WHITE);
		
			if((p_pPioA->PIO_PDSR) & BIT_JPUSH){}
			else{
				switch(menu_x) {
					case 0: PlaySinglePlayer();
							break;
					case 1: PlayLocal();
							break;
					case 2: HostGame();
							break;
					case 3: JoinGame();
							break;
				}
				break;		
			}
			if(((p_pPioA->PIO_PDSR) & BIT_JUP)){}
			else{
				if(menu_x == 0) {
			 		menu_x = 3;
				} else {
					menu_x--;
				}	
			} 
			if((p_pPioA->PIO_PDSR) & BIT_JDOWN){}
			else{
				if(menu_x == 3){
					menu_x = 0;
				}else{
					menu_x++;
				}
			} 
			DrawMenuIndicator(menu_x, lineColor);
			Delay(1000000);
		}
	}

	/* The answer of every question in the universe */
	return 42;
}

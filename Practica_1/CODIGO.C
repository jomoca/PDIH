//• gotoxy(): coloca el cursor en una posición determinada
//• setcursortype(): fijar el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO.
//• setvideomode(): fija el modo de video deseado
//• getvideomode(): obtiene el modo de video actual
//• textcolor(): modifica el color de primer plano con que se mostrarán los caracteres
//• textbackground(): modifica el color de fondo con que se mostrarán los caracteres
//• clrscr(): borra toda la pantalla
//• cputchar(): escribe un carácter en pantalla con el color indicado actualmente
//• getche(): obtiene un carácter de teclado y lo muestra en pantalla


#include <dos.h>
#define BYTE unsigned char
#include <stdio.h>
#define VGA_256_COLOR_MODE  0x13   /* use to set 256-color mode. */
#define VIDEO_INT           0x10      /* the BIOS video interrupt. */
#define WRITE_DOT           0x0C      /* BIOS func to plot a pixel. */
#define SCREEN_WIDTH        320       /* width in pixels of mode 0x13 */
#define SCREEN_HEIGHT       200       /* height in pixels of mode 0x13 */
#define NUM_COLORS          256       /* number of colors in mode 0x13 */


BYTE MODOTEXTO = 3;
BYTE MODOGRAFICO = 4;

int colortexto = 5;
int colorfondo = 2;

// hace una pausa
void pausa(){
		union REGS inregs, outregs;
		inregs.h.ah = 0x00;
		int86(0x16, &inregs, &outregs);
}
// establece el modo de vídeo: 3-texto, 4-gráfico
void setVideo(BYTE modo){
		union REGS inregs, outregs;
		inregs.h.al = modo;
		inregs.h.ah = 0x00;
		int86(0x10, &inregs, &outregs);
}
// pone un pixel en la coordenada X,Y de color C
void pixel(int x, int y, BYTE C){
		union REGS inregs, outregs;
		inregs.x.cx = x;
		inregs.x.dx = y;
		inregs.h.al = C;
		inregs.h.ah = 0x0C;
		int86(0x10, &inregs, &outregs);
}

void gotoxy(int x, int y){
		union REGS inregs, outregs;
		inregs.h.ah = 2;
		inregs.h.dl = x; //Posicion del cursor x
		inregs.h.dh = y; //Posicion del cursor y
		inregs.h.bh = 0;
		int86(0x10, &inregs, &outregs);
}


void setcursortype(int tipo_cursor){
	union REGS inregs, outregs;
	inregs.h.ah = 0x01;
	switch(tipo_cursor){
		case 0: //invisible
			inregs.h.ch = 010;
			inregs.h.cl = 000;
			break;
		case 1: //normal
			inregs.h.ch = 010;
			inregs.h.cl = 010;
			break;
		case 2: //grueso
			inregs.h.ch = 000;
			inregs.h.cl = 010;
			break;
	}
	int86(0x10, &inregs, &outregs);
}

int getvideomode(void){
		union REGS inregs, outregs;
		int videomode;
		inregs.h.ah = 0x0F;
		int86(0x10, &inregs, &outregs);
		videomode = outregs.h.al;
		return videomode;
}

void textcolor(unsigned char ctexto){
		colortexto = ctexto;
}

void textbackground(unsigned char cfondo){
		colorfondo = cfondo;
}

void clscr(void){
		union REGS inregs, outregs;
		inregs.h.ah = 0x06;
		inregs.h.al = 0;
		inregs.h.dh = 25;
		inregs.h.dl = 80;
		inregs.h.bh = 0x00;
		inregs.x.cx = 0x00;
		int86( 0x10, &inregs, &outregs );
		setvideomode(3);
}

void cputchar(char c){
		union REGS inregs, outregs;
		inregs.h.ah = 0x09;
		inregs.h.al = c;
		inregs.h.bl = colorfondo << 4 | colortexto;
		inregs.h.bh = 0x00;
		inregs.x.cx = 1;
		int86(0x10, &inregs, &outregs);
		return;
}

void getche(void){
		int tmp;
		printf("\nPulsa una tecla: ");
		tmp = getchar();
		printf("\nHas pulsado: ");
		putchar( (char)tmp);
}

int main(){
	 /*	modovideo(MODOGRAFICO); //gráfico
		pixel(10,40,0);
		pixel(10,50,1);
		pixel(15,60,2);
		pixel(20,70,3);
	 */
		setVideo(MODOTEXTO); //texto
		gotoxy(5,9);
		setcursortype(2);
		getvideomode();
		textcolor(5);
		textbackground(2);
		cputchar('J');

		pausa();
		return 0;
}








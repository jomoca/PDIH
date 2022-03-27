# Practica_1

## Ejercicios

**gotoxy(): coloca el cursor en una posición determinada**

```csharp
void gotoxy(int x, int y){
		union REGS inregs, outregs;
		inregs.h.ah = 2;
		inregs.h.dl = x; //Posicion del cursor x
		inregs.h.dh = y; //Posicion del cursor y
		inregs.h.bh = 0;
		int86(0x10, &inregs, &outregs);
}

```

![imagen](https://github.com/jomoca/PDIH/blob/master/Practica_1/img/gotoxy.png)

**setcursortype(): fijar el aspecto del cursor, debe admitir tres valores: INVISIBLE, NORMAL y GRUESO.**

```csharp
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


```

**Cursor Grueso**
![imagen](https://github.com/jomoca/PDIH/blob/master/Practica_1/img/cursor_grueso.png)

**Cursor Invisible**
![imagen](https://github.com/jomoca/PDIH/blob/master/Practica_1/img/cursor_invisible.png)

**Cursor Normal**
![imagen](https://github.com/jomoca/PDIH/blob/master/Practica_1/img/cursor_normal.png)

**setvideomode(): fija el modo de video deseado**

```csharp

void setVideo(BYTE modo){
		union REGS inregs, outregs;
		inregs.h.al = modo;
		inregs.h.ah = 0x00;
		int86(0x10, &inregs, &outregs);
}

```

![imagen](https://github.com/jomoca/PDIH/blob/master/Seminario_2/img/seminario_video.png)

**getvideomode(): obtiene el modo de video actual**

```csharp
int getvideomode(void){
		union REGS inregs, outregs;
		int videomode;
		inregs.h.ah = 0x0F;
		int86(0x10, &inregs, &outregs);
		videomode = outregs.h.al;
		return videomode;
}

```

![imagen](https://github.com/jomoca/PDIH/blob/master/Seminario_2/img/seminario_video.png)

**textcolor(): modifica el color de primer plano con que se mostrarán los caracteres**

```csharp
void textcolor(unsigned char ctexto){
		colortexto = ctexto;
}

```

![imagen](https://github.com/jomoca/PDIH/blob/master/Practica_1/img/letra_color.png)

**textbackground(): modifica el color de fondo con que se mostrarán los caracteres**

```csharp
void textbackground(unsigned char cfondo){
		colorfondo = cfondo;
}
```

![imagen](https://github.com/jomoca/PDIH/blob/master/Practica_1/img/color_fondo.png)

**clrscr(): borra toda la pantalla**

```csharp

```

![imagen]()

**cputchar(): escribe un carácter en pantalla con el color indicado actualmente**

```csharp
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
```

![imagen](https://github.com/jomoca/PDIH/blob/master/Seminario_2/img/pulsateclas.png)

**getche(): obtiene un carácter de teclado y lo muestra en pantalla**

```csharp
void getche(void){
		int tmp;
		printf("\nPulsa una tecla: ");
		tmp = getchar();
		printf("\nHas pulsado: ");
		putchar( (char)tmp);
}
```

![imagen](https://github.com/jomoca/PDIH/blob/master/Seminario_2/img/pulsateclas.png)


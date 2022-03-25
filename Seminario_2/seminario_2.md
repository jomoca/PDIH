# Seminario 2

## Ejercicios

**1. Configurar el inicio de DOSBox para que monte en la unidad C: el directorio donde se encuentra el entorno de programación Borland C. Añadir a la variable “PATH” de inicio el directorio “bin” donde se encuentra el ejecutable BC.EXE**


Configuración del fichero:


![imagen](https://github.com/jomoca/PDIH/blob/master/Seminario_2/img/archivoConfiguracion.png)


![imagen](https://github.com/jomoca/PDIH/blob/master/Seminario_1/img/Captura%20de%20pantalla%20de%202022-03-10%2021-24-53.png)



**2. Realizar un programa en lenguaje C que llame a la función de cambio de modo de vídeo y comprobar su funcionamiento.**

´´´c
void selecciona_modo_video(BYTE modo){
        union REGS inregs, outregs;
        inregs.h.ah = 0x00;
        inregs.h.al = modo;
        int86(0x10,&inregs,&outregs);
        return;
}
´´´

![imagen](https://github.com/jomoca/PDIH/blob/master/Seminario_1/img/archivoConfiguracion.png)



**3. Realizar un programa en lenguaje C que llame a la función de interrupción correspondiente a la lectura de caracteres desde teclado. Ejecutarlo para leer pulsaciones de teclas y mostrarlas por pantalla usando otra función de interrupción.**




![imagen](https://github.com/jomoca/PDIH/blob/master/Seminario_1/img/archivoConfiguracion.png)

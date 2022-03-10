pila segment stack 'stack'
    dw 100h dup (?)
pila ends

datos segment 'data'
    msg db 'Hola mundo$'
datos ends
   
codigo segment 'code'
    assume cs:codigo, ds:datos, ss:pila
    main PROC

        mov cx,0
        mov ax,datos
        mov ds,ax
        
        bucle:

        mov dx,OFFSET msg  ; mostrar por pantalla una cadena de texto
        mov ah,9
        int 21h

        MOV dl, 10
		MOV ah, 02h
		INT 21h

		inc cx 
		cmp cx,7
		jne bucle

        mov ax,4C00h       ; terminar y salir al S.O.
        int 21h
        
        
    main ENDP
codigo ends

END main

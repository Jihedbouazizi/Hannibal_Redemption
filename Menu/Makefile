prog:main.o background.o text.o 	
	gcc main.o background.o text.o -o prog -lSDL -lSDL_ttf -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
background.o:background.c
	gcc -c background.c -g 
text.o:text.c
	gcc -c text.c -g
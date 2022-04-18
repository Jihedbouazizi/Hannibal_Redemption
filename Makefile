all : prog clean
prog : main.o background.o
	@echo "building..."
	gcc main.c background.c -o prog  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
clean:
	@echo "cleaning up..."
	rm *.o
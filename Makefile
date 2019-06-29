# Install CSFML
# sudo apt-get install libcsfml-dev
#

CC = gcc
LIB = -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio
INC= -I/include

space.exe: obj/main.o obj/game.o obj/window.o obj/assets.o
	$(CC) -o $@ $^ $(LIB)

obj/main.o: main/main.c
	$(CC) $(LIB) $(INC) -c -o $@ $^
obj/game.o: src/game.c 
	$(CC) $(LIB) $(INC) -c -o $@ $^
obj/window.o: src/window.c 
	$(CC) $(LIB) $(INC) -c -o $@ $^
obj/assets.o: src/assets.c 
	$(CC) $(LIB) $(INC) -c -o $@ $^

clear:
	rm obj/*.o *.exe

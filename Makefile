# Install CSFML
# sudo apt-get install libcsfml-dev
#

CC = gcc
LIB = -lcsfml-window -lcsfml-system -lcsfml-graphics -lcsfml-audio
INC = -I/include
EXE = ./space.exe

$(EXE): obj/main.o obj/game.o obj/player.o obj/enemy.o \
		obj/scenery.o obj/text.o obj/time.o
	$(CC) -o $@ $^ $(LIB)

obj/main.o: main/main.c
	$(CC) $(LIB) $(INC) -c -o $@ $^
obj/game.o: src/game.c 
	$(CC) $(LIB) $(INC) -c -o $@ $^
obj/player.o: src/player.c 
	$(CC) $(LIB) $(INC) -c -o $@ $^
obj/enemy.o: src/enemy.c 
	$(CC) $(LIB) $(INC) -c -o $@ $^	
obj/scenery.o: src/scenery.c 
	$(CC) $(LIB) $(INC) -c -o $@ $^
obj/text.o: src/text.c 
	$(CC) $(LIB) $(INC) -c -o $@ $^	
obj/time.o: src/time.c 
	$(CC) $(LIB) $(INC) -c -o $@ $^	
clear:
	rm obj/*.o *.exe
run:
	@$(EXE)
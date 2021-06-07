tictactoe: main.o check.o messages.o game.o
	g++ main.o check.o messages.o game.o -o tictactoe

main.o: src/main.cpp
	g++ -c src/main.cpp

game.o: src/game.cpp src/include/game.h
	g++ -c src/game.cpp

check.o: src/check.cpp src/include/check.h
	g++ -c src/check.cpp

messages.o: src/messages.cpp src/include/messages.h
	g++ -c src/messages.cpp

clean:
	del *.o
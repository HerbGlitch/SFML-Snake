all: compile link

compile:
	cd src/compiled/ && g++ -c ../../snake/main.cpp
	cd src/compiled/ && g++ -c ../../snake/game/*.cpp
	cd src/compiled/ && g++ -c ../../snake/manager/*.cpp

link:
	g++ src/compiled/*.o -o main -Lsrc/lib -Isrc/include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
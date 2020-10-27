all: compile link

compile: main handler manager menuState snakeState

main:
	cd src/compiled/ && g++ -c ../../snake/*.cpp

handler:
	cd src/compiled/ && g++ -c ../../snake/handler/*.cpp

manager:
	cd src/compiled/ && g++ -c ../../snake/manager/*.cpp

menuState:
	cd src/compiled/ && g++ -c ../../snake/states/menu/*.cpp

snakeState:
	cd src/compiled/ && g++ -c ../../snake/states/snake/*.cpp
	cd src/compiled/ && g++ -c ../../snake/states/snake/background/*.cpp
	cd src/compiled/ && g++ -c ../../snake/states/snake/player/*.cpp

link:
	g++ src/compiled/*.o -o main -Lsrc/lib -Isrc/include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	main.exe
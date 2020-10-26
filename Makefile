all: compile link

compile: main handler manager states

main:
	cd src/compiled/ && g++ -c ../../snake/*.cpp

handler:
	cd src/compiled/ && g++ -c ../../snake/handler/*.cpp

manager:
	cd src/compiled/ && g++ -c ../../snake/manager/*.cpp

states:
	cd src/compiled/ && g++ -c ../../snake/states/menu/*.cpp

link:
	g++ src/compiled/*.o -o main -Lsrc/lib -Isrc/include -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

run:
	main.exe
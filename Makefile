all: compile link clear

compile:
	g++ -Ilibraries/include -Iheaders -c src/*.cpp

link:
	g++ *.o -o ConnectFour -Llibraries/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

clear:
	del *.o
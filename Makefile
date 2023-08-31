all: oopd oopd1

oopd: oopd.cpp
	g++ -O1 oopd.cpp -o oopd
	g++ -g oopd.cpp -o oopddebug

oopd1: oopd1.cpp
	g++ -O1 oopd1.cpp -o oopd1
	g++ -g oopd1.cpp -o oopddebug1
clean:
	rm -f oopd oopd1 oopddebug oopddebug1

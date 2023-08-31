

oopd: oopd1.cpp
	g++ -O1 oopd1.cpp -o oopd
	g++ -g oopd1.cpp -o oopddebug1


clean:
	rm -f oopd1 oopddebug1

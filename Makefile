
oopd: oopd.cpp
	g++ -O1 oopd.cpp -o oopd
	g++ -g oopd.cpp -o oopddebug

clean:
	rm -f oopd oopddebug

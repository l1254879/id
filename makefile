
main:id.o
	g++ -o a.out  id.o
	g++  -g -c  id.cpp

clean:
	rm -f *.o

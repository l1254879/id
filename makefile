
main:id.o
	g++ -o a.out  id.o
id.o:id.cpp
	g++  -g -c  id.cpp

clean:
	rm -f *.o

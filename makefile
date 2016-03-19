
main:i.o
	##g++ -o main id.o
	##g++ -c id.cpp
	g++ -o test  i.o
	g++  -g -c  i.cpp

clean:
	rm -f *.o

all: generic_container_test

generic_container_test: 
	g++ -ansi -Wall -c GenericContainer.cpp
	g++ -ansi -Wall -c unittests.cpp
	g++ -ansi -Wall -o unittests unittests.o GenericContainer.o

clean: 
	rm *.o

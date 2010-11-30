all: generic_container_test

generic_container_test: 
	g++ -ansi -Wall -c -o GenericContainer.o GenericContainer.cpp
	g++ -ansi -Wall -c -o GenericQueue.o GenericQueue.cpp
	g++ -ansi -Wall -c -o GenericStack.o GenericStack.cpp
	g++ -ansi -Wall -c -o unittests.o unittests.cpp
	g++ -ansi -Wall -o unittests unittests.o GenericContainer.o

clean: 
	rm *.o

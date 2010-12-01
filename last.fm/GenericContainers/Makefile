all: threadunsafe

threadsafe: 
	g++ -ansi -Wall -c -o GenericContainer.o GenericContainer.cpp
	g++ -ansi -Wall -c -o GenericQueue.o GenericQueue.cpp
	g++ -ansi -Wall -c -o GenericStack.o GenericStack.cpp
	g++ -ansi -Wall -c -o Threadsafe.o ThreadSafe.cpp
	g++ -ansi -Wall -c -o unittests.o unittests.cpp
	g++ -ansi -Wall -o unittests unittests.o GenericContainer.o Threadsafe.o

threadunsafe: 
	g++ -ansi -Wall -c -o GenericContainer.o GenericContainer.cpp
	g++ -ansi -Wall -c -o GenericQueue.o GenericQueue.cpp
	g++ -ansi -Wall -c -o GenericStack.o GenericStack.cpp
	g++ -ansi -Wall -c -o Threadunsafe.o ThreadUnsafe.cpp
	g++ -ansi -Wall -c -o unittests.o unittests.cpp
	g++ -ansi -Wall -o unittests unittests.o GenericContainer.o Threadunsafe.o

clean: 
	rm *.o

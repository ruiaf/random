all: container_unit_test queue_unit_test stack_unit_test

container_unit_test: GenericContainer.o ThreadUnsafe.o
	g++ -ansi -Wall -c -o unittestGenericContainer.o unittestGenericContainer.cpp
	g++ -ansi -Wall -o unittestGenericContainer unittestGenericContainer.o GenericContainer.o ThreadUnsafe.o

queue_unit_test: GenericContainer.o GenericQueue.o ThreadUnsafe.o
	g++ -ansi -Wall -c -o unittestGenericQueue.o unittestGenericQueue.cpp
	g++ -ansi -Wall -o unittestGenericQueue unittestGenericQueue.o GenericContainer.o GenericQueue.o ThreadUnsafe.o

stack_unit_test: GenericContainer.o GenericStack.o ThreadUnsafe.o
	g++ -ansi -Wall -c -o unittestGenericStack.o unittestGenericStack.cpp
	g++ -ansi -Wall -o unittestGenericStack unittestGenericStack.o GenericContainer.o GenericStack.o ThreadUnsafe.o

GenericContainer.o: GenericContainer.h GenericContainer.cpp
	g++ -ansi -Wall -c -o GenericContainer.o GenericContainer.cpp

ThreadUnsafe.o: ThreadUnsafe.cpp
	g++ -ansi -Wall -c -o ThreadUnsafe.o ThreadUnsafe.cpp

GenericQueue.o: GenericQueue.cpp
	g++ -ansi -Wall -c -o GenericQueue.o GenericQueue.cpp

GenericStack.o: GenericQueue.cpp
	g++ -ansi -Wall -c -o GenericStack.o GenericStack.cpp

clean: 
	rm *.o

all: unittestGenericContainer unittestGenericQueue unittestGenericStack unittestMultiThreaded

unittestGenericContainer:
	g++ -ansi -Wall -c -o unittestGenericContainer.o unittestGenericContainer.cpp
	g++ -ansi -Wall -o unittestGenericContainer unittestGenericContainer.o ../src/ThreadUnsafe.o

unittestGenericQueue:
	g++ -ansi -Wall -c -o unittestGenericQueue.o unittestGenericQueue.cpp
	g++ -ansi -Wall -o unittestGenericQueue unittestGenericQueue.o ../src/ThreadUnsafe.o

unittestGenericStack:
	g++ -ansi -Wall -c -o unittestGenericStack.o unittestGenericStack.cpp
	g++ -ansi -Wall -o unittestGenericStack unittestGenericStack.o ../src/ThreadUnsafe.o

unittestMultiThreaded:
	g++ -ansi -Wall -c -o unittestMultiThreaded.o unittestMultiThreaded.cpp
	g++ -ansi -Wall -lpthread -o unittestMultiThreaded unittestMultiThreaded.o ../src/ThreadSafe.o

clean: 
	rm unittestGenericContainer unittestGenericQueue unittestGenericStack unittestMultiThreaded
	rm *.o

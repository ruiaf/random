all: unittestGenericContainer unittestGenericQueue unittestGenericStack unittestMultiThreaded

unittestGenericContainer: ThreadUnsafe.o
	g++ -ansi -Wall -c -o unittestGenericContainer.o unittestGenericContainer.cpp
	g++ -ansi -Wall -o unittestGenericContainer unittestGenericContainer.o ThreadUnsafe.o

unittestGenericQueue: ThreadUnsafe.o
	g++ -ansi -Wall -c -o unittestGenericQueue.o unittestGenericQueue.cpp
	g++ -ansi -Wall -o unittestGenericQueue unittestGenericQueue.o ThreadUnsafe.o

unittestGenericStack: ThreadUnsafe.o
	g++ -ansi -Wall -c -o unittestGenericStack.o unittestGenericStack.cpp
	g++ -ansi -Wall -o unittestGenericStack unittestGenericStack.o ThreadUnsafe.o

unittestMultiThreaded: ThreadSafe.o
	g++ -ansi -Wall -c -o unittestMultiThreaded.o unittestMultiThreaded.cpp
	g++ -ansi -Wall -lpthread -o unittestMultiThreaded unittestMultiThreaded.o ThreadSafe.o

ThreadSafe.o: ThreadSafe.cpp
	g++ -ansi -Wall -c -o ThreadSafe.o ThreadSafe.cpp

ThreadUnsafe.o: ThreadUnsafe.cpp
	g++ -ansi -Wall -c -o ThreadUnsafe.o ThreadUnsafe.cpp

clean: 
	rm *.o

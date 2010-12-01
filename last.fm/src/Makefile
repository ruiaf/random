all: ThreadUnsafe.o ThreadSafe.o

ThreadSafe.o: ThreadSafe.cpp
	g++ -ansi -Wall -c -o ThreadSafe.o ThreadSafe.cpp

ThreadUnsafe.o: ThreadUnsafe.cpp
	g++ -ansi -Wall -c -o ThreadUnsafe.o ThreadUnsafe.cpp

clean: 
	rm *.o

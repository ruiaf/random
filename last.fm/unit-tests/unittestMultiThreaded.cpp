#include <assert.h>
#include <stdexcept>
#include "GenericContainer.h"
#include <iostream>
#include <pthread.h>

#define N_THREADS 50
#define N_INSERTS 1000

void *insert_remove_run(void *data) {
	GenericContainer<int> *myints;

	myints= (GenericContainer<int> *) data;

	for (int i=0;i<N_INSERTS;i++) {
		myints->insert(0xDEADBEEF,0);
	}

	for (int i=0;i<N_INSERTS;i++) {
		myints->remove(0);
	}

	return NULL;
}

// start 10 threads that do 1000 inserts and 1000 removes each
void test_insert_remove() {
	pthread_t threads[N_THREADS];
	GenericContainer<int> myints;
	
	for (int i=0;i<N_THREADS; i++) {
		pthread_create(&threads[i],NULL,insert_remove_run,(void*)&myints);
	}

	for (int i=0;i<N_THREADS; i++) {
		pthread_join(threads[i],NULL);
	}

    assert(myints.is_empty());
    assert(myints.size()==0);

}

void *insert_access_remove_run(void *data) {
	GenericContainer<int> *myints;

	myints= (GenericContainer<int> *) data;

	for (int i=0;i<N_INSERTS;i++) {
		myints->insert(0,0);
	}

	for (int i=0;i<N_INSERTS;i++) {
		assert((myints->get_element(i))==0);
	}

	for (int i=0;i<1000;i++) {
		myints->remove(0);
	}

	return NULL;
}

// start 10 threads that do 1000 inserts and read 1000 elements and removes 1000
void test_insert_access_remove() {
	pthread_t threads[N_THREADS];
	GenericContainer<int> myints;
	
	for (int i=0;i<N_THREADS; i++) {
		pthread_create(&threads[i],NULL,insert_access_remove_run,(void*)&myints);
	}

	for (int i=0;i<N_THREADS; i++) {
		pthread_join(threads[i],NULL);
	}

    assert(myints.is_empty());
    assert(myints.size()==0);

}
int main(void) {
	test_insert_remove();
	test_insert_access_remove();
}

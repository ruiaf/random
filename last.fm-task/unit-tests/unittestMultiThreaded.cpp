#include <assert.h>
#include <stdexcept>
#include "../src/GenericContainer.h"
#include <iostream>
#include <pthread.h>

#define N_THREADS 50
#define N_INSERTS 1000

/** \brief The thread that insert, accesses and removes elements
 *
 */
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

/** \brief Test concurrent insertion, access and removal of elements
 *
 *	Start several threads that insert many elements
 *	then access the same number of elements
 *	and then remove the same number of elements inserted
 */
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

/** \brief The thread that insert and removes elements
 *
 */
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

/** \brief Test concurrent insertion and removal of elements
 *
 *	Start several threads that insert many elements
 *	and then remove the same number of elements inserted
 */
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

/** \brief Runs the unit tests for GenericContainer
 *
 *	As all the multi-threading logic is in the GenericContainer there is
 *	no need to test the queue and the stack
 */
int main(void) {
	std::cout << "Testing GenericStack\t";
	test_insert_remove();
	test_insert_access_remove();
	std::cout << "\tOK\n";
}

#include <assert.h>
#include <stdexcept>
#include "../src/GenericQueue.h"
#include <iostream>
#include <string>

using namespace std;

/** \brief Test the order elements come out of the queue.
  *
  * Make sure of FIFO
  */
void order_test(void) {
	GenericQueue<int> myqueue;

	assert(myqueue.is_empty()==true);
	for (int i=0;i<10000;i++) {
		myqueue.push(i);
	}
	assert(myqueue.size()==10000);
	for (int i=0;i<10000;i++) {
		assert(myqueue.front()==i);
		myqueue.pop();
	}

	assert(myqueue.is_empty()==true);
	for (int i=0;i<10000;i++) {
		myqueue.push(i);
	}
	assert(myqueue.size()==10000);
	for (int i=0;i<10000;i++) {
		assert(myqueue.front()==i);
		myqueue.pop();
	}
}

/** \brief Runs the unit tests for GenericQueue
 *
 *	As the queue heavily reuses code from GenericContainer
 *	the only thing left to test is the order of the elements
 */
int main(void) {
	cout << "Testing GenericQueue\t";
	order_test();
	cout << "\tOK\n";
}

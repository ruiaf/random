#include <assert.h>
#include <stdexcept>
#include "GenericQueue.h"
#include <iostream>
#include <string>

using namespace std;

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
}

int main(void) {
	// most tests are done in the container unit test
	// lets just test the order
	order_test();
}

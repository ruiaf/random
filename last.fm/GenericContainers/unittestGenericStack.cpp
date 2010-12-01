#include <assert.h>
#include <stdexcept>
#include "GenericStack.h"
#include <iostream>
#include <string>

using namespace std;

void order_test(void) {
    GenericStack<int> mystack;

	assert(mystack.is_empty()==true);
	for (int i=0;i<10000;i++) {
		mystack.push(i);
	}
	assert(mystack.size()==10000);
	for (int i=9999;i>=0;i--) {
		assert(mystack.top()==i);
		mystack.pop();
	}
}

int main(void) {
	// most tests are done in the container unit test
	// lets just test the order
	order_test();
}

#include <assert.h>
#include <stdexcept>
#include "../src/GenericStack.h"
#include <iostream>
#include <string>

using namespace std;

/** \brief Test the order elements come out of the queue.
  *
  * Make sure of LIFO
  */
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

/** \brief Runs the unit tests for GenericStack
 *
 *	As the stack heavily reuses code from GenericContainer
 *	the only thing left to test is the order of the elements
 */
int main(void) {
	cout << "Testing GenericStack\t";
	order_test();
	cout << "\tOK\n";
}

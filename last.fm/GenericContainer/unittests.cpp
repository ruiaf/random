#include <assert.h>
#include "GenericContainer.h"
#include <iostream>

using namespace std;

int main(void) {

    GenericContainer<int> myintegers;

    assert(myintegers.is_empty());
    assert(myintegers.size()==0);

	myintegers.insert(10,0);
    assert(myintegers.size()==1);
	myintegers.insert(20,1);
    assert(myintegers.size()==2);
	myintegers.insert(10,2);
	myintegers.insert(40,3);
	myintegers.insert(10,4);
    assert(myintegers.size()==5);
	assert(myintegers.exists(20)==true);
	myintegers.remove(1);
	assert(myintegers.exists(20)==false);
	myintegers.insert(50,0);
	assert(myintegers.exists(50)==true);
	myintegers.remove(0);
	assert(myintegers.exists(50)==false);
	assert(myintegers.exists(40)==true);
	assert(myintegers.remove_element(40)==true);
	assert(myintegers.exists(40)==false);
	assert(myintegers.size()==3);
	myintegers.remove(0);
	myintegers.remove(0);
	myintegers.remove(0);
    assert(myintegers.is_empty());
	assert(myintegers.size()==0);
}

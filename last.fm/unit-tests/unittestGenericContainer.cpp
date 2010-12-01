#include <assert.h>
#include <stdexcept>
#include "GenericContainer.h"
#include <iostream>
#include <string>

using namespace std;

void insert_remove_string_test(void) {
    GenericContainer<string> mystrings;

    assert(mystrings.is_empty());
    assert(mystrings.size()==0);

	mystrings.insert("hello",0);
	assert(mystrings.exists("hello")==true);
	assert(mystrings.get_element(0)=="hello");
	mystrings.remove(0);
	assert(mystrings.exists("hello")==false);

    assert(mystrings.is_empty());
    assert(mystrings.size()==0);

	mystrings.insert("hello",0);
	mystrings.insert("goodbye",0);
	assert(mystrings.exists("goodbye")==true);
	assert(mystrings.get_element(1)=="hello");
	mystrings.remove(0);
	assert(mystrings.exists("hello")==true);

    assert(mystrings.is_empty()==false);
    assert(mystrings.size()==1);
}

void out_of_bounds_test(void) {
    GenericContainer<string> mystrings;
	bool flag;

	flag=false;
	try {
		mystrings.insert("hello",-1);
	} catch (std::out_of_range e) {
		flag=true;
	} 
	assert(flag);

	flag=false;
	try {
		mystrings.insert("hello",1);
	} catch (std::out_of_range e) {
		flag=true;
	} 
	assert(flag);

	mystrings.insert("hello",0);
	assert(mystrings.exists("hello")==true);

	flag=false;
	try {
		mystrings.get_element(1);
	} catch (std::out_of_range e) {
		flag=true;
	} 
	assert(flag);

	flag=false;
	try {
		mystrings.get_element(-1);
	} catch (std::out_of_range e) {
		flag=true;
	} 
	assert(flag);
	assert(mystrings.get_element(0)=="hello");
}

void multiple_operations_int_test(void) {
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

void lots_of_inserts_test(void) {
    GenericContainer<int> myintegers;

	for (int i=9999;i>=0;i--) {
		myintegers.insert(i,0);
	}
	myintegers.remove(4000);
	assert(myintegers.size()==9999);
	assert(myintegers.remove_element(7000)==true);
	assert(myintegers.remove_element(4000)==false);
	for (int i=10;i<20;i++) {
		assert(myintegers.get_element(10)==i);
		myintegers.remove(10);
	}
}

int main(void) {
	insert_remove_string_test();
	out_of_bounds_test();
	multiple_operations_int_test();
	lots_of_inserts_test();
}

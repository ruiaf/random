#include "GenericContainer.h"

template <class T>
class GenericStack: private GenericContainer<T> {

	public:
    // get the element at the top of the stack
	T& top(void) const;

    // remove the element at the top of the stack
	void pop(void);

    // push an element to the top of the stack
	void push(T & element);

    // TODO: add a method to merge another stack
};

template <class T>
T& GenericStack<T>::top() const {
	return this->get_element(0);
}

template <class T>
void GenericStack<T>::pop(void) {
	this->remove(0);
}

template <class T>
void GenericStack<T>::push(T& element) {
	this->insert(element,0);
}

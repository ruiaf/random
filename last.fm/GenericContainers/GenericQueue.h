#include "GenericContainer.h"

template <class T>
class GenericQueue: private GenericContainer<T> {

	public:
    // get element from the front of the queue
	T front(void) const;

    // remove element from the top of the queue
	void pop(void);

    // push an element to the back of the queue
	void push(const T & element);

    // TODO: add a method to merge a queue
};

template <class T>
T GenericQueue<T>::front() const {
	return this->get_element(0);
}

template <class T>
void GenericQueue<T>::pop(void) {
	this->remove(0);
}

template <class T>
void GenericQueue<T>::push(const T& element) {
	//TODO: do a custom implementation that doesn't
	//		go arround the list to insert at the end
	this->insert(element,this->size());
}

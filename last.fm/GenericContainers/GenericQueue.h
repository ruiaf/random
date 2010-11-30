#include "GenericContainer.h"

template <class T>
class GenericQueue: private GenericContainer<T> {

	public:
	T& front(void) const;
	void pop(void);
	void push(T & element);

	private:

};

template <class T>
T& GenericQueue<T>::front() const {
	return this->get_element(0);
}

template <class T>
void GenericQueue<T>::pop(void) {
	this->remove(0);
}

template <class T>
void GenericQueue<T>::push(T& element) {
	//TODO: custom implementation that doesn't
	//		go arround the list to insert at the end
	this->insert(element,this->size());
}

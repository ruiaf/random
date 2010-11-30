#include "GenericContainer.h"

template <class T>
class GenericStack: private GenericContainer<T> {

	public:
	T& top(void) const;
	void pop(void);
	void push(T & element);

	private:

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

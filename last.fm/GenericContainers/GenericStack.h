#include "GenericContainer.h"

/** \brief A stack for generic objects
 *
 *  This class implements a stack for generic objects using the doubly-linked list in Generic Container.
 *
 *  If this is linked with ThreadSafe.cpp, it becomes thread safe and supports concurrent
 *  reading of the elements of the container. When writing, it makes sure that no other thread
 *  is reading or writing concurrently
 */

template <class T>
class GenericStack: private GenericContainer<T> {

	public:
    /** \brief Get element at the top of the stack
    *
    *   This method reuses the get_element method implemented in GenericContainer
    *   This method takes O(1) time
    *   @return Returns a copy of the element at the front of the queue
    */
	T top(void) throw (std::out_of_range);

    /** \brief Remove element at the top of the stack
    *
    *   This method reuses the get_element method implemented in GenericContainer
    *   This method takes O(1) time
    */
	void pop(void) throw (std::out_of_range);

    /** \brief Push an element to the top of the stack
    *
    *   This method reuses the get_element method implemented in GenericContainer
    *
    *   This method takes O(1) time
    */
	void push(T & element);

    /** \brief Exposing is_empty method
    */
    using GenericContainer<T>::is_empty;

    /** \brief Exposing size method
    */
    using GenericContainer<T>::size;

    /** \brief Exposing exists method
    */
    using GenericContainer<T>::exists;

    // TODO: add a method to merge another stack
};

template <class T>
T GenericStack<T>::top() throw (std::out_of_range) {
	return GenericContainer<T>::get_element(0);
}

template <class T>
void GenericStack<T>::pop(void)  throw (std::out_of_range) {
	GenericContainer<T>::remove(0);
}

template <class T>
void GenericStack<T>::push(T& element) {
	insert(element,0);
}

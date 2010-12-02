#include "GenericContainer.h"

/** \brief A queue for generic objects
 *
 *  This class implements a queue for generic objects using the doubly-linked list in Generic Container.
 *
 *  If this is linked with ThreadSafe.cpp, it becomes thread safe and supports concurrent
 *  reading of the elements of the container. When writing, it makes sure that no other thread
 *  is reading or writing concurrently
 */

template <class T>
class GenericQueue: private GenericContainer<T> {

	public:
    /** \brief Get element at the front of the queue
    *
    *   This method reuses the get_element method implemented in GenericContainer
    *   This method takes O(1) time
    *   @return Returns a copy of the element at the front of the queue
    */
	T front(void) throw (std::out_of_range);

    /** \brief Remove element at the front of the queue
    *
    *   This method reuses the remove method implemented in GenericContainer
    *
    *   This method takes O(1) time
    */
	void pop(void) throw (std::out_of_range);

    /** \brief Push an element to the back of the queue
    *
    *   This method implement a insert from the back of the linked list method
    *   in order to be more efficient.
    *
    *   This method takes O(1) time
    */
	void push(const T & element);

    /** \brief Exposing private parent is_empty method
    */
    using GenericContainer<T>::is_empty;

    /** \brief Exposing private parent size method
    */
    using GenericContainer<T>::size;

    /** \brief Exposing private parent exists method
    */
    using GenericContainer<T>::exists;

    // TODO: add a method to merge a queue
};

template <class T>
T GenericQueue<T>::front() throw (std::out_of_range) {
	return GenericContainer<T>::get_element(0);
}

template <class T>
void GenericQueue<T>::pop(void) throw (std::out_of_range) {
	GenericContainer<T>::remove(0);
}

template <class T>
void GenericQueue<T>::push(const T& element) {
	//TODO: do a custom implementation that doesn't
	//		go arround the list to insert at the end
	this->insert(element,this->size());
}

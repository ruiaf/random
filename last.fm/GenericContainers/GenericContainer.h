#include <utility>
#include <assert.h>
#include <stdexcept>
#include "ThreadSafe.h"

/** \brief A container for generic objects
 * 
 *  This class implements a container for generic objects using doubly-linked lists.
 *
 *  A copy of the elements inserted is kept in memory.
 *
 *  If this is linked with ThreadSafe.cpp, it becomes thread safe and supports concurrent
 *  reading of the elements of the container. When writing, it makes sure that no other thread
 *  is reading or writing concurrently
 */

template <class T>
class GenericContainer {

    public:
    /** \brief Create a GenericContainer
	* 
    * Initialization of internal variables
    */
    GenericContainer();

    /** \brief Destroy a GenericContainer
	* 
    * Frees objects alocated in the container
    */
    ~GenericContainer();

    /** \brief Check if the Container is empty
    *
    * This method takes O(1) time
    * @return True if the container is empty, False otherwise
    */
    bool is_empty() const;

    /** \brief Get number of elements in the container
    *
    * This method takes O(1) time
    * @return Number of elements in the container
    */
    int size() const;

    /** \brief Check if an element exists in the container
    *
    * This method takes O(n) time for a random position
    * @return True if the element exists in the container, False otherwise
    */
    bool exists(const T& element);

	/** \brief Insert an element at a specified position of the container
    * 
    * Insert an element in the container at a specified position. A Copy of the element is
    * performed
    *
    * Positions start counting from 0.
	* The element is inserted at the first position if none other is specified.
    *
	* When asked to insert an element out of bounds gives an assert error.
    *
    * This method takes O(n) time for a random position
    * This method takes O(1) time for inserting at left of the linked list
    *
    * @param element The element to insert in the container
    * @param position The position where to insert the element 
    */
    void insert(const T& element, int position) throw(std::out_of_range);

	/** \brief Remove the element at a specified position of the container
    * 
    * Positions start counting from 0.
    *
	* When asked to remove an element out of bounds gives an assert error.
    *
    * This method takes O(n) time for a random position
    * This method takes O(1) time for removing at left of the linked list
    *
    * @param position The position where the element to remove is
    */
	void remove(int position) throw(std::out_of_range);

	/** \brief Remove the first occurence of an element
    * 
    * @param element The element to remove
    * @return True if removed an element, False otherwise
    */
	bool remove_element(const T& element);

	/** \brief Retrieve the element at a certain position of the container
    * 
	* When asked to remove an element out of bounds gives an assert error.
    *
    * @param position The position of the element to return
    * @return The element at the specified position
    */
	T get_element(int position) throw(std::out_of_range);

    // TODO: add a method to merge another container
    // TODO: add iterators to the container

    private:

    /** \brief Represents the node of a doubly-linked list
    *
    *   This is a private class that can only be accessed by the
    *   container and that has the elements and links between the
    *   nodes in the linked list
    */
    class ContainerNode {
		public:

        /** \brief  The copy of the element inserted in the container
        *   
        *   This is the only copy of the element in the container.
        */
		T element;

        /** \brief  A link to the next element in the linked list
        *
        *   This is NULL if it's the tail of the list
        */
        ContainerNode *next;

        /** \brief  A link to the previous element in the linked list
        *
        *   This is NULL if it's the tail of the list
        */
        ContainerNode *previous;
    };

    /** \brief  The number of elements in the container
    */
    int n_elements;

    /** \brief  A pointer to the first element of the linked list
    *
    * This first element is a dummy element and it is always created.
    * This is done to avoid special cases when inserting/removing
    * from the endpoints of the list
    */
    ContainerNode *head;

    /** \brief  A pointer to the last element of the linked list
    *
    * This last element is a dummy element and it is always created.
    * This is done to avoid special cases when inserting/removing
    * from the endpoints of the list
    */
    ContainerNode *tail;

    /** \brief A object to support safe race conditions
    *
    * If the code is linked with threadunsafe, there are no actions being performed.
    * If theading is enabled, it allows concurrent reading of the list and locks
    * reading and writing (inserting/removing) when writing
    */
    ThreadSafe mutex;
};

/*
 * Implementation
 *
 * Unfortunately most compilers don't accept template methods in a separate cpp file. So this code goes here.
 */

template <class T>
GenericContainer<T>::GenericContainer() {

    n_elements = 0;

	// there are two dummy elements on the linked list to avoid special cases
	// when inserting/removing at the endpoints
	head = new ContainerNode();
	tail = new ContainerNode();
	head->element = NULL;
	tail->element = NULL;
	head->previous = NULL;
	tail->next = NULL;
	head->next = tail;
	tail->previous = head;
}

template <class T>
GenericContainer<T>::~GenericContainer() {
	ContainerNode *n;
    
    n=head->next;

	// delete all the elements
	while (n!=tail) {
		delete n->previous;
		n=n->next;
	}
	delete tail;
}

template <class T>
bool GenericContainer<T>::is_empty() const {
    return size()==0;
}

template <class T>
int GenericContainer<T>::size() const {
    return n_elements;
}

template <class T>
bool GenericContainer<T>::exists(const T& element) {
	ContainerNode *n;
    
    // do not allow insertion/removal of elements while searching
    mutex.lock_write();
    n=head->next;

	while (n!=tail) {
		if (n->element==element)
			return true;
		n=n->next;
	}
    mutex.unlock_write();

	return false;
}

template <class T>
void GenericContainer<T>::insert(const T & element, int position=0) throw (std::out_of_range) {
	int i=0;
	ContainerNode *cur_ele;

	// check if the position where to insert is within the bounds of the list
	if (position>n_elements || position<0)
        throw std::out_of_range ("Out of bounds insertion in the container");

    mutex.lock_readwrite();
    cur_ele=head;

	// update element count
	this->n_elements++;

	// going through the list to the correct insert position
	while (i<position) {
		i++;
		cur_ele=cur_ele->next;
	}
	ContainerNode *next_ele = cur_ele->next;

	// inserting new_ele inbetween cur_ele and next_ele
	ContainerNode *new_ele = new ContainerNode();
	new_ele->element = element;
	new_ele->previous = cur_ele;
	new_ele->next = next_ele;

	cur_ele->next = new_ele;
	next_ele->previous = new_ele;

    mutex.unlock_readwrite();
}

template <class T>
void GenericContainer<T>::remove(int position=0) throw (std::out_of_range) {
	int i=0;
	ContainerNode *cur_ele;

	// check if the position where to remove is within the bounds of the list
	if (position>=n_elements || position<0)
        throw std::out_of_range ("Out of bounds removal of element");

    mutex.lock_readwrite();
    cur_ele=head->next;

	// going through the list to the correct remove position
	while (i<position) {
		i++;
		cur_ele=cur_ele->next;
	}

	cur_ele->previous->next=cur_ele->next;
	cur_ele->next->previous=cur_ele->previous;
	delete cur_ele;

	// update element count
	n_elements=n_elements-1;
    mutex.unlock_readwrite();

}

// removes the first occurence of an element in a list
template <class T>
bool GenericContainer<T>::remove_element(const T& element) {
	ContainerNode *cur_ele;

    // do not allow searching and insertion / removal concurrently
    mutex.lock_readwrite();
    cur_ele=head->next;

	// going through the list to the correct remove position
	bool was_found=false;
	while (cur_ele!=tail) {
		if (cur_ele->element==element) {
			was_found = true;
			break;
		}
		cur_ele=cur_ele->next;
	}

	// if we found an occurrence of the element, remove it
	if (was_found) {
		cur_ele->previous->next=cur_ele->next;
		cur_ele->next->previous=cur_ele->previous;
		delete cur_ele;

		// update element count
		n_elements--;
	}

    mutex.unlock_readwrite();
	return was_found;
}

// gets an element at a certain position of the list
template <class T>
T GenericContainer<T>::get_element(int position) throw (std::out_of_range) {
	ContainerNode *cur_ele;
	int i;

	// check if the position of the element is within the bounds of the list
	if (position>=n_elements || position<0)
        throw std::out_of_range ("Out of bounds position of element");

    // do not allow insertion / removal concurrently while getting element
    mutex.lock_write();

    cur_ele = head->next;

	// going through the list to the correct remove position
	bool was_found=false;
	i=0;
	while (i!=position) {
		i++;
		cur_ele=cur_ele->next;
	}
    T element=cur_ele->element;
    mutex.unlock_write();

	return element;
}

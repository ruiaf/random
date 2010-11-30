#include <utility>
#include <assert.h>

/*
 * Declaration
 */

template <class T>
class GenericContainer {

    public:
	// constructer of a GenericContainer
    GenericContainer();

	// distructer of a GenericContainer
    ~GenericContainer();

	// returns true if container is empty false otherwise
    bool is_empty() const;

	// returns the number of elements in the container
    int size() const;

	// returns true if an element exists in the container
    bool exists(const T& element) const;

	// insert an element in the container at a specified position
	// the element is inserted at the first position if none specified
	// first position is 0 last position is the size()
	// if asked to insert an element out of bounds gives an assert error
    void insert(const T& element, int position);

	// remove the element at a certain position
	// if asked to remove an element out of bounds gives an assert error
	void remove(int position);

	// removes the first occurrence of an element
	// returns true if it was removed, false otherwise
	bool remove_element(const T& element);

	// returns the element at a certain position
	bool get_element(int position);

    private:

	// the nodes on the linked list used to store the elements in the container
    class ContainerNode {
		public:

		// a copy of the element
		T element;

		// a pointer to the next element
        ContainerNode *next;

		// a pointer to the previous element
        ContainerNode *previous;
    };

	// a counter of the number of elements in the container
    int n_elements;

	// a pointer to the first (dummy) element of the linked list
    ContainerNode *head;

	// a pointer to the last (dummy) element of the linked list
    ContainerNode *tail;
};

/*
 * Implementation
 */

template <class T> GenericContainer<T>::GenericContainer() {

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

template <class T> GenericContainer<T>::~GenericContainer() {
	ContainerNode *n=head->next;

	// delete all the elements
	while (n!=tail) {
		delete n->previous;
		n=n->next;
	}
	delete tail;
}

template <class T> bool GenericContainer<T>::is_empty() const {
    return head->next==tail;
}

template <class T> int GenericContainer<T>::size() const {
    return n_elements;
}

template <class T> bool GenericContainer<T>::exists(const T& element) const {
	ContainerNode *n=head->next;

	while (n!=tail) {
		if (n->element==element)
			return true;
		n=n->next;
	}

	return false;
}

template <class T> void GenericContainer<T>::insert(const T & element, int position=0) {
	int i=0;
	ContainerNode *cur_ele=head;

	// check if the position where to insert is within the bounds of the list
	assert(position>=0);
	assert(position<=n_elements);

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
}

template <class T> void GenericContainer<T>::remove(int position=0) {
	int i=0;
	ContainerNode *cur_ele=head->next;

	// check if the position where to remove is within the bounds of the list
	assert(position<=n_elements && position>=0);

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
}

// removes the first occurence of an element in a list
template <class T> bool GenericContainer<T>::remove_element(const T& element) {
	ContainerNode *cur_ele=head->next;

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
		return true;
	}

	return false;
}

// removes the first occurence of an element in a list
template <class T> bool GenericContainer<T>::get_element(int position) {
	ContainerNode *cur_ele=head->next;
	int i;

	// going through the list to the correct remove position
	bool was_found=false;
	i=0;
	while (i!=position) {
		i++;
		cur_ele=cur_ele->next;
	}

	assert(false);
	return NULL;
}

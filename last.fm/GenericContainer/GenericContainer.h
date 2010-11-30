#include <utility>
#include <assert.h>

/*
 * Declaration
 */

template <class T>
class GenericContainer {

    public:
    GenericContainer();
    ~GenericContainer();

    bool is_empty() const;
    int size() const;
    bool exists(const T& element) const;

    void insert(const T& element, int position);
	void remove(int position);
	bool remove_element(const T& element);

    private:

    class ContainerNode {
		public:

		T element;
        ContainerNode *next;
        ContainerNode *previous;
    };

    int n_elements;
    ContainerNode *head;
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


#include <utility>

/*
 * Declaration
 */

template <class T>
class GenericContainer {

    public:
    GenericContainer();
    ~GenericContainer();

    void insert(const T& element, int position=0);
    bool is_empty() const;
    bool size() const;
    bool exists(const T& element) const;

    private:

    class ContainerNode {
        T& element;
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

    head = NULL;
    tail = NULL;
    n_elements = 0;
}

template <class T> GenericContainer<T>::~GenericContainer() {

}

template <class T> bool GenericContainer<T>::is_empty() const {
    return this->head==NULL;
}

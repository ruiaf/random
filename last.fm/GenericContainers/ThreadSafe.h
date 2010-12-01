#include <pthread.h>

/** \brief Provides thread safeness to containers.
 * 
 *  This class implements methods that provide thread safeness to containers.
 *
 *  It alows that many elements are used at the same time. If a method that modifies the container
 *  is used, i.e. insert/remove, it guaranties that no other thread is reading or writing
 *
 *  If this is linked with ThreadSafe.cpp, it enables thread safeness and supports concurrent
 *  reading of the elements of the container.
 */

class ThreadSafe {

    public:
    /** \brief Constuctor of the thread safe class
    *
    *   Initializes the class that provides safe race conditions
    */
    ThreadSafe();

    /** \brief Locks the container for writing
    *
    *   Waits until there are no threads writing in the container.
    *   Locks the container for writing without doing so for reading.
    *   Keeps count of how many threads are reading the container at the moment
    */
    void lock_write();

    /** \brief Unlocks the container for writing
    *
    *   Unlocks the container for writing if there are no threads reading at the moment
    *   Keeps count of how many threads are reading the container at the moment
    */
    void unlock_write();

    /** \brief Locks the container for Reading and Writing
    *
    *   Waits until there are no threads reading the container.
    *   Locks the container for writing if there are no threads reading at the moment
    */
    void lock_readwrite();

    /** \brief Unlocks the container for Reading and Writing
    *
    *   Unlocks the container for reading and writing
    */
    void unlock_readwrite();

    private:
    /** \brief Mutex for writing (insert/remove)
    *
    *   If locked a thread has to wait to write
    */
    pthread_mutex_t write_mutex;

    /** \brief Mutex for reading (insert/remove)
    *
    *   If locked a thread has to wait to read
    */
    pthread_mutex_t read_mutex;


    /** \brief Mutex for internal synch logic
    *
    *   This mutex makes sure that operations in
    *   the synchorinzation methods are atomic
    */
    pthread_mutex_t logic_mutex;

    /** \brief Number of threads reading the container
    */
    int read_counter;
};

#include <pthread.h>

class ThreadSafe {

    public:
    ThreadSafe();
    ~ThreadSafe();

    void lock_write();
    void unlock_write();
    void lock_readwrite();
    void unlock_readwrite();

    private:
    pthread_mutex_t write_mutex;
    pthread_mutex_t read_mutex;
    pthread_mutex_t logic_mutex;
    int read_counter;
};

#include "ThreadSafe.h"
#include <stdlib.h>

ThreadSafe::ThreadSafe() {
    pthread_mutex_init(&read_mutex,NULL);
    pthread_mutex_init(&write_mutex,NULL);
    pthread_mutex_init(&logic_mutex,NULL);
    read_counter = 0;
}

void ThreadSafe::lock_write() {
    pthread_mutex_lock(&logic_mutex);
    // if we are the first readers lock the writing
    if (read_counter==0)
        pthread_mutex_lock(&write_mutex);
    read_counter++;
    pthread_mutex_unlock(&logic_mutex);
}

void ThreadSafe::unlock_write() {
    pthread_mutex_lock(&logic_mutex);
    read_counter--;
    // if we are the last readers free writing
    if (read_counter==0)
        pthread_mutex_lock(&write_mutex);
    pthread_mutex_unlock(&logic_mutex);
}

void ThreadSafe::lock_readwrite() {
    pthread_mutex_lock(&logic_mutex);
    // make sure there is no one reading
    pthread_mutex_lock(&read_mutex);
    // make sure there is no one writing
    pthread_mutex_lock(&write_mutex);
    pthread_mutex_unlock(&logic_mutex);
}

void ThreadSafe::unlock_readwrite() {
    pthread_mutex_lock(&logic_mutex);
    // let others read
    pthread_mutex_unlock(&read_mutex);
    // let others write
    pthread_mutex_unlock(&write_mutex);
    pthread_mutex_unlock(&logic_mutex);
}

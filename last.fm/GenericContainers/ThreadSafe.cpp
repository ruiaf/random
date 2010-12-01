#include "ThreadSafe.h"
#include <stdlib.h>

ThreadSafe::ThreadSafe() {
    pthread_mutex_init(&read_mutex,NULL);
    pthread_mutex_init(&write_mutex,NULL);
    pthread_mutex_init(&logic_mutex,NULL);
    read_counter = 0;
}

ThreadSafe::~ThreadSafe() {
}

void ThreadSafe::lock_write() {
    pthread_mutex_lock(&logic_mutex);
    if (read_counter==0)
        pthread_mutex_lock(&write_mutex);
    read_counter++;
    pthread_mutex_unlock(&logic_mutex);
}

void ThreadSafe::unlock_write() {
    pthread_mutex_lock(&logic_mutex);
    read_counter--;
    if (read_counter==0)
        pthread_mutex_lock(&write_mutex);
    pthread_mutex_unlock(&logic_mutex);
}

void ThreadSafe::lock_readwrite() {
    pthread_mutex_lock(&logic_mutex);
    pthread_mutex_lock(&read_mutex);
    pthread_mutex_lock(&write_mutex);
    pthread_mutex_unlock(&logic_mutex);
}

void ThreadSafe::unlock_readwrite() {
    pthread_mutex_lock(&logic_mutex);
    pthread_mutex_lock(&read_mutex);
    pthread_mutex_lock(&write_mutex);
    pthread_mutex_unlock(&logic_mutex);
}

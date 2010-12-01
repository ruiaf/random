#include "ThreadSafe.h"
#include <stdlib.h>
#include <iostream>

ThreadSafe::ThreadSafe() {
    pthread_mutex_init(&write_mutex,NULL);
    pthread_mutex_init(&logic_mutex,NULL);
    read_counter = 0;
}

void ThreadSafe::lock_write() {
	// lock logic mutex to make sure counting is atomic
    pthread_mutex_lock(&logic_mutex);
    // if we are the first readers lock the writing
	// if we are not the first readers, some other reader has the writing lock
	//		and we can safely read
    if (read_counter==0) {
        pthread_mutex_lock(&write_mutex);
	}
    read_counter++;
    pthread_mutex_unlock(&logic_mutex);
}

void ThreadSafe::unlock_write() {
	// lock logic mutex to make sure counting is atomic
    pthread_mutex_lock(&logic_mutex);
    read_counter--;
    // if we are the last readers free writing
    if (read_counter==0) {
        pthread_mutex_unlock(&write_mutex);
	}
    pthread_mutex_unlock(&logic_mutex);
}

void ThreadSafe::lock_readwrite() {
    // make sure writting is available
    pthread_mutex_lock(&write_mutex);
}

void ThreadSafe::unlock_readwrite() {
    // let others write
    pthread_mutex_unlock(&write_mutex);
}

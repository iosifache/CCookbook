#ifndef _MULTITHREADING_H

#define _MULTITHREADING_H

#include "../miscellaneous/math_operations.h"

/*
 * Create a number of static threads, run a function on each and wait until join
 */
#define STATIC_THREAD_SETUP(threads_count, threads, thread_ids, threaded_function) \
    for (int i = 0; i < threads_count; i++) \
        thread_ids[i] = i; \
    for (int i = 0; i < threads_count; i++) \
        pthread_create(&(threads[i]), NULL, threaded_function, &(thread_ids[i])); \
    for (int i = 0; i < threads_count; i++) \
        pthread_join(threads[i], NULL);

/*
 * Create a number of dynamic threads, run a function on each and wait until join
 */
#define DYNAMIC_THREAD_SETUP(threads_count, threads, thread_ids, threaded_function) \
    threads = malloc(threads_count * sizeof(pthread_t)); \
    thread_ids = malloc(threads_count * sizeof(int)); \
    for (int i = 0; i < threads_count; i++) \
        thread_ids[i] = i; \
    for (int i = 0; i < threads_count; i++) \
        pthread_create(&(threads[i]), NULL, threaded_function, &(thread_ids[i])); \
    for (int i = 0; i < threads_count; i++) \
        pthread_join(threads[i], NULL);\
    free(threads);\
    free(thread_ids);\

/*
 * Get thread identification number
 */
#define GET_THREAD_ID(argument, thread_id) thread_id = *((int *)argument)

/*
 * Compute an allocated interval for a given thread
 */
#define GET_ALLOCATED_INTERVAL(threads_count, thread_id, full_interval_length, start, stop) \
    start = thread_id * ceil((float)full_interval_length / (float)threads_count); \
    stop = min(full_interval_length, (thread_id + 1) * ceil((float)full_interval_length / (float)threads_count));

#endif
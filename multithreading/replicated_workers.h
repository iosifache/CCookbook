#ifndef _REPLICATED_WORKERS_H

#define _REPLICATED_WORKERS_H

#include <pthread.h>
#include <semaphore.h>

#define QUEUE_SIZE 1000000

extern int threads_count;
 
extern int got_tasks;
extern int put_tasks;

typedef struct task{
    pthread_mutex_t wait_until_finished;
    void (*task_to_run)(void *, int);
    void *data;
} task;

/*
 * Initialize the variables used by workers
 */
void init_workers();

/*
 * Start workers
 */
void start_workers();

/*
 * Put a new task to be executed by workers
 */
void put_task(task new_task);

/*
 * Wait for workers to finish their jobs
 */
void join_worker_threads();

/*
 * Shutdown with force the workers
 */
void force_shutdown_workers();

#endif
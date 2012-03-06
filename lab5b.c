#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10

int glob;

pthread_t thread[NUM_THREADS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *child(void *t)
{
	// Increment glob by 1, wait for 1 second, then increment by 1 again.
	printf("Child %d entering. Glob is currently %d\n", t, glob);
    pthread_mutex_lock(&mutex);
	glob++;
	sleep(1);
	glob++;
    pthread_mutex_unlock(&mutex);
	printf("Child %d exiting. Glob is currently %d\n", t, glob);
}

int main()
{
	int i;
	glob=0;
	for(i=0; i<NUM_THREADS; i++)
	    //child((void *) i);
        if (pthread_create(&thread[i], NULL, child, (void*)i)) {
            printf("Error encountered with thread creation");
            return 1;
        }
    for (i=0; i<NUM_THREADS; i++)
        if (pthread_join(thread[i], NULL))
            return 2;
	printf("Final value of glob is %d\n", glob);
    pthread_mutex_destroy(&mutex);
	return 0;
}


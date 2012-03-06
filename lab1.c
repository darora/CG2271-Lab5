#include <stdio.h>
#include <pthread.h>
// Global variable.

#define NUM_THREADS 10

int ctr=0;
pthread_t thread[NUM_THREADS];

void *child(void *t)
{
	// Print out the parameter passed in, and the current value of ctr.
	printf("I am child %d. Ctr=%d\n", t, ctr);
	// Then increment ctr
	ctr++;
	pthread_exit(NULL);
}

int main()
{
	int i;
	// Initialize ctr
	ctr=0;
	// Create the threads
	for(i=0; i<NUM_THREADS; i++) {
	    pthread_create(&thread[i], NULL, child, (void *) i);
        //If the join op fails, quit & return an error
        if (pthread_join(thread[i], NULL))
            return 1;
    }
	// And print out ctr
	printf("Value of ctr=%d\n", ctr);
	return 0;
}


#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10

int glob;

pthread_t thread[NUM_THREADS];

void *child(void *t)
{
	// Increment glob by 1, wait for 1 second, then increment by 1 again.
	printf("Child %d entering. Glob is currently %d\n", t, glob);
	glob++;
	sleep(1);
	glob++;
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
	return 0;
}


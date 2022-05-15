//14March Monday Linux//
//Buggy code//

/*
#include<stdio.h>
#include<stdlib.h>

void buggy()
{
int *intptr;
int i;
intptr =(int *)malloc(sizeof(int)*5);

printf("MALLOC checking : Addr=%08 and size=%d\n",intptr,sizeof(int)*5);

	for(i=0; i<=4; i++)

	{
		* intptr =100;
		printf("values at ptr intptr =%d\n",
(*intptr));
		intptr++;
	}
}
int main()
{
	buggy();
	return 0;
}
*/

//thread sync semaphore//

/*
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

int sharedVar=5;
sem_t my_sem;

void *thread_inc(void *arg)
		{
		sem_wait(&my_sem);
		sharedVar++;
	printf("after inc =%d \n",sharedVar);
		sem_post(&my_sem);
		}

void *thread_dec(void *arg)
		{
		sem_wait(&my_sem);
		sharedVar--;
	printf("after dec =%d \n",sharedVar);
		sem_post(&my_sem);
		}

int main()
{	
	pthread_t thread1,thread2;
	sem_init(&my_sem,0,1);

	pthread_create(&thread1,NULL,thread_inc,NULL);
	pthread_create(&thread2,NULL,thread_dec,NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("sharedVar = %d \n",sharedVar);
	return 0;
}

*/

//spinlock //
/*

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<bits/types.h>
#include<sys/types.h>

static pthread_spinlock_t spinlock;
volatile int slock;

void *spinlockThread(void *i)

{
	 int rc;
	 int count=0;

printf("Entered thread %d, getting Spin lock \n",(int *)i);
rc = pthread_spin_lock(&spinlock);

printf("%d Thread unlock the spin lock\n",(int *)i);
rc = pthread_spin_lock(&spinlock);

printf("%d Thread Complete\n",(int *)i);
return NULL;
}

int main()
{
	int rc=0;
	pthread_t thread,thread1;

	if(pthread_spin_init(&spinlock,PTHREAD_PROCESS_PRIVATE)!=0)
		perror("init");
	printf("Main get Spinlock\n");
	rc =pthread_spin_lock(&spinlock);

	printf("Main ,create the spin lock thread\n");
	rc=pthread_create(&thread,NULL,spinlockThread,(int *)1);

	printf("Main,wait a bit holding spin lock\n");
	sleep(10);

	printf("main ,now unlock spin lock\n");
	rc= pthread_spin_unlock(&spinlock);
	if(rc==0)
		printf("main thread succesfully unlockecd\n");
	else
		printf("main thread succesfully unlockecd\n");

	printf("Main,wait for the thread to end\n");
	rc=pthread_join(thread,NULL);

	printf("main complete");
	return 0;
}
*/


//thread mutex//
/*

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sharedVar=5;
pthread_mutex_t my_mutex;

void *thread_inc(void *arg)
		{
		pthread_mutex_lock(&my_mutex);
		sharedVar++;
	printf("after inc =%d \n",sharedVar);
		pthread_mutex_lock(&my_mutex);
		}

void *thread_dec(void *arg)
		{
		pthread_mutex_lock(&my_mutex);
		sharedVar--;
	printf("after dec =%d \n",sharedVar);
		pthread_mutex_lock(&my_sem);
		}

int main()
{	
	pthread_t thread1,thread2;
	pthread_mutex_init(&my_mutex,0,1);

	pthread_create(&thread1,NULL,thread_inc,NULL);
	pthread_create(&thread2,NULL,thread_dec,NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("sharedVar = %d \n",sharedVar);
	return 0;
}
*/


//pthread detach//

#include<stdio.h>
#include<pthread.h>
#define NUM_THREADS 3


int i;


void *func(void *arg)
{
i++;
int result =0;


result = result+i*100;


printf("Result : %d\n",result);


pthread_exit(NULL);
}


int main()
{
pthread_t thread[NUM_THREADS];
pthread_attr_t attr;


int rc, t, status, detach_state;


/* Initialize and set thread detach state */
pthread_attr_init(&attr);


pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);


for(int i=0; i <NUM_THREADS; i++)
{
printf("Thread: %d\n",i);
pthread_create(&thread[i], NULL, func, NULL);
}


pthread_attr_getdetachstate(&attr, &detach_state);


printf("Detach state: %d\n",(int *)detach_state);


pthread_attr_destroy(&attr);
printf("Exiting main thread\n");


pthread_exit(NULL);
}


















































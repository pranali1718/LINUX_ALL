#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
//declaring thread condition varibale
pthread_cond_t cond1=PTHREAD_COND_INITIALIZER;

//declaring mutex
pthread_mutex_t lock=PTHREAD_COND_INITIALIZER;

int done=1;

//thread function
void* foo(void *arg)
{
	char *str=(char*)arg;
	printf("Thread task called by:%s\n",str);
	//acquire a lock
	pthread_mutex_lock(&lock);
	if(done==1)
		{
		done=2;

		printf("Waiting on condtion variable cond\n");
		pthread_cond_wait(&cond1,&lock);
		}
	else
	{
		printf("signling condtion variable cond\n");
		pthread_cond_signal(&cond1);
	}
		pthread_mutex_unlock(&lock);
		printf("returning thread\n");
		return NULL;
}

int main()
{
		pthread_t tid1,tid2;
		pthread_create(&tid1,NULL,foo,"thread one");
		sleep(1);

		done=2;
		pthread_create(&tid2,NULL,foo,"thread two");

		pthread_join(tid2,NULL);
	return 0;
}

/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


pthread_t tid, tid2;


int sharedVar = 5; //global variable
void* thread_inc(void *arg)
{
sharedVar++;
printf("Newly created thread is executing\n");
printf("After incr + %d\n",sharedVar);


return NULL;
}


void* thread_dec(void *arg)
{
printf("Newly created thread2 is executing\n");
sharedVar--;


printf("After dec - %d\n",sharedVar);


return NULL;
}


int main(void)
{
int ret=pthread_create(&tid, NULL, thread_inc, NULL);
int ret1=pthread_create(&tid2, NULL, thread_dec, NULL);


if(ret && ret1)
printf("thread not created\n");
else
printf("Thread is created\n");


// sleep(3);


pthread_join(tid, NULL);
pthread_join(tid2, NULL);


printf("Exiting main thread\n");

return 0;
}
*/



//***************************************************************file_thread*******************************************************************//
/*
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void * th_fn(void * p);

int fd;
int main()
{
	pthread_t t1,t2;

	fd=open("/etc/passwd",O_RDONLY);
	printf("file opned with fd: %d \n",fd);

	pthread_create(&t1,NULL,th_fn,"Thread One");
	pthread_create(&t2,NULL,th_fn,"Thread Two");

	pthread_join(&t1,NULL);
	pthread_join(&t2,NULL);

}
void * th_fn(void * p)
{
	char *str, buff[100];
	int n, pid;
	str=(char *)p;
	pid=getpid();
	printf("%s: \t started now: \t for process %d \n\n",str,pid);
	do
	{	
	n=read(fd,buff,100);
	printf("%s: \t Read: \t %d \n\n",str,pid);
	printf("\n------------------\n");
	write(1,buff,n);
	printf("\n----------------------\n");
	sleep(3);
	}while(n);

printf("%s: \t Finished: \t For Process \n\n",str,pid);

}*/













































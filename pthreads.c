//program on 15 march 2022 wednesday//
/*
#include<pthread.h>
#include<stdio.h>

pthread_once_t once = PTHREAD_ONCE_INIT;

void *my_init()
{
	printf("\ni am in init func\n");
}
 
void *my_thread(void *i)
{
	printf("\nI am in my thread func:%d\n",(int *)i);
	pthread_once(&once,(void *)my_init);
	//sleep(10);
	printf("\nExit from my thread function\n");
}

int main()
{
	pthread_t thread1,thread2,thread3;
	pthread_create(&thread1,NULL,my_thread,(void *)1);
	//sleep(2);
	pthread_create(&thread2,NULL,my_thread,(void *)2);
	//sleep(2);
	pthread_create(&thread3,NULL,my_thread,(void *)3);
	//sleep(2);

	printf("Exit main thread\n");
	pthread_exit(NULL);
}*/


/*
//priority new//

#include<pthread.h>
#include<stdio.h>

void *my(void *i)
{
	printf("\n I  am in %d thread \n",(int *)i);
}
main()
{
	pthread_t tid;

struct sched_param param;
int priority,policy,ret;
ret=pthread_getschedparam(pthread_self(),&policy,&param);
printf("In main thread.................policy: %d.................priority:%d\n",policy,param.sched_priority);

policy=SCHED_FIFO;
 
param.sched_priority=3;
pthread_setschedparam(pthread_self(),policy,&param);
pthread_getschedparam(pthread_self(),&policy,&param);
printf("\nIn main thread.................policy: %d.................priority:%d\n",policy,param.sched_priority);
return 0;
}
*/

//change_nice_one//

#include<errno.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
int ret,i,cnt=0;;
errno=0;
ret=nice(1);
if(ret== -1 && errno !=0)
	perror("nice");
else
	printf("nice valuenis now %d\n",ret);
while(1)
	{
	printf("process with nice values :%d nad count :%d\n",ret,cnt);
	for(i=0;i<10000000;i++)
	cnt++;
	}
return 0;
}



































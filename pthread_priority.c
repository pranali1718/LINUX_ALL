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
	/*scheduling paramtetrs of target thread*/	
	ret=pthread_getschedparam(pthread_self(),&policy,&param);
	if(ret !=0)
		perror("getschedparam");
printf("\n.................In main thread.................policy: %d.................priority:%d\n",policy,param.sched_priority);
	policy=SCHED_FIFO;
 	param.sched_priority=3;
pthread_setschedparam(pthread_self(),policy,&param);
pthread_getschedparam(pthread_self(),&policy,&param);
printf("\nIn main thread.................policy: %d.................priority:%d\n",policy,param.sched_priority);
return 0;

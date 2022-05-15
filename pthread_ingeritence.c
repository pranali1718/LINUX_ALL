//pthread attr getinhiritance//
/#include<pthread.h>
#include<stdio.h>
#include<sys/mman.h>

void* Proc(void* param)
{
sleep(3);
return 0;
}

int main(int argc, char *argv[])
{
	pthread_attr_t attr;
	pthread_t Id;
	int err,info;
	pthread_attr_init(&attr);
	pthread_attr_getinheritsched(&attr,&info);

switch(info)
{
	case PTHREAD_INHERIT_SCHED:
		printf("sched from its own thread\n");

	case PTHREAD_EXPLICIT_SCHED:
		printf("Explicit defining its own scheduling policy and prioority\n");
}

pthread_create(&Id,&attr,Proc,NULL);
return 0;
}



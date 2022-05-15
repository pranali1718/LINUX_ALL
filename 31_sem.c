
#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/sem.h>
#include<stdlib.h>

#define KEY (1492)

void main()
{
	int id;
	
	union semun
	{
		int val;
		struct id_ds *buf;
		unsigned short *array
	}argument;

argument.val=1;

id =semget(KEY, 1 ,IPC_CREAT|0666);
	
	if(id<0)
	{
		fprintf(stderr,"unable to obatin semaphore\n ");
		exit(0);
	}
	if(semctl(id,0,SETVAL,argument)<0)
	{
		fprintf(stderr,"cant setv semaphore\n ");
	}
	else
	{
		fprintf(stderr,"Semaphore %d Initialized\n ",KEY);
	}

}


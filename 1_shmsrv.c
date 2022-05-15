#include<stdio.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<sys/shm.h>

#define MY_KEY 199
#define SHM_SIZE 0x1000

void toggleCase(char *buf,int cnt);

union semun
{
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *_buf;
};

union semun sem_union;
int main()
{
		int semId ,shmId;
		char *pshm;
		struct sembuf smop;

		semId=semget(MY_KEY,1,IPC_CREAT|0666);
		if(semId<0)
		{
			printf("Could not create semaphore\n");
			return 0;
		}
		else
			printf("opened semaphore ID is %d\n",semId);

		semctl(semId,0,SETVAL,0);

		shmId=shmget(MY_KEY,SHM_SIZE,IPC_CREAT|0666);
		if(shmId<0)
		{
			printf("Could not create shared memoery\n");
			return (2);
		}

		pshm=shmat(shmId,NULL,0);
		if(!pshm)
		{
			printf("could not attach shared memeory\n");
			return(3);
		}


		while(1)
		{
			smop.sem_num=1;
			smop.sem_op=-1;
			smop.sem_flg=0;
		
		semop(semId,&smop,1);

		printf("Got the sempahore\n");
		strcpy(pshm+256,pshm);
		toggleCase(pshm+256,strlen(pshm+256));
		printf("Processed the request msg and place responses\n");


		smop.sem_num=1;
		smop.sem_op=1;
		smop.sem_flg=0;

		semop(semId,&smop,1);
		}
	return 0;
}

	void toggleCase(char *buf,int cnt)
	{
		int ii;
		for(ii=0;ii<cnt;ii++)
		{
			if((buf[ii] >= 'A') && (buf[ii] <='Z'))
				buf[ii]+= 0x20;
			else if((buf[ii] >= 'a') && (buf[ii] <='z'))
				buf[ii]-= 0x20;
		}
	}

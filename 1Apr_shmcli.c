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
#define MSG_LEN 256
#define RESP_MSG_START 256

int main()
{
		int semId ,shmId;
		char *pshm;
		struct sembuf smop;

		semId = semget(MY_KEY,1,0666);
		if(semId < 0)
		{
			printf("Could not create semaphore\n");
			return 0;
		}
		else
			printf("opened semaphore ID is %d\n",semId);

		semctl(semId,0,SETVAL,0);

		shmId = shmget(MY_KEY,SHM_SIZE,0666);
		if(shmId < 0)
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
			printf("CLient:enter some request message to send to server");
			fgets(pshm,MSG_LEN,stdin);
		
			smop.sem_num = 0;
			smop.sem_op = 1;
			smop.sem_flg = 0;
		
			semop(semId,&smop,1);


			smop.sem_num = 0;
			smop.sem_op = -1;
			smop.sem_flg = 0;

			semop(semId,&smop,1);
	
			puts(pshm+RESP_MSG_START);
		}

	return 0;
}



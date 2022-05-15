
#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<unistd.h>
	union semun
	{
		int val;
		struct sid_ds *buf;
		unsigned short *array;
		struct seminfo *_buf;
	};

int get_release(void);
int get_semaforce(void);
struct sembuf sem_op;
union semun sem_union;

int sid;
int main()
{
		int i;
		sleep(3);
	sid =semget((key_t)10, 1 ,IPC_CREAT|0666);
	printf("\n semafroce ID :%d\n",sid);
	
	sem_union.val=1;

	if(semctl(sid, 0,SETVAL,sem_union)<0)
		printf("Error\n");

	for(i=0;i<=5;i++)
	{
		get_semaforce();
		printf("\n%d:got the semaforce",getpid());
		sleep(1);
		printf("\n%d:release the semaforce\n",getpid());
		get_release();
		sleep(1);
	}
	if(semctl(sid,0,IPC_RMID,sem_union)<0)
		printf("\nfails to detele the semaforce");
	else
		printf("\nsemeforce deleted");
return 0;
}

int get_semaforce()
{
	sem_op.sem_num=0;
	sem_op.sem_op=-1;
	sem_op.sem_flg=SEM_UNDO;

	if(semop(sid,&sem_op,1)<0)
	{
		printf("Failed\n");
		return -1;
	}
}

int get_release()
{
	sem_op.sem_num=0;
	sem_op.sem_op=1;
	sem_op.sem_flg=SEM_UNDO;

	if(semop(sid,&sem_op,1)<0)
	{
		printf("\nFailed\n");
		return -1;
	}
}	


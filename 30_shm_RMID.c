#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>



//#define KEY 8979


int main()
	{
	int shmid;
	struct shmid_ds buff;

	shmid=shmget(48,250,IPC_CREAT|0644);
	printf("SHM ID: %d\n",shmid);

	shmctl(shmid, IPC_RMID, NULL);


return 0;
}

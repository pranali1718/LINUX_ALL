
#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

struct msg_buf
{
long mtype;
char buff[512];
};
  
int main(int args,char *argv[])
{
	struct msg_buf v;
	int id;
	 id =msgget(55,IPC_CREAT|0644);
	printf("id of messge queue:%d\n",id);

	v.mtype=1;
	strcpy(v.buff,"hello");


	msgsnd(id,&v,strlen(v.buff)+1,0);

	return 0;
}


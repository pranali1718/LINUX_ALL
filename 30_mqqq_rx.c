
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
 id= msgget(55,IPC_CREAT|0644);
printf("id of messge queue:%d\n",id);

msgrcv(id,&v,sizeof(v),1,0);
printf("Data : %s\n",v.buff);
return 0;


}


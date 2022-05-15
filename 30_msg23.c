#include<stdio.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdlib.h>


 
int main(int args,char *srgv[])
{
int id;
struct msqid_ds mybuff;

id = msgget(32,IPC_CREAT|0644);
msgctl(id,IPC_STAT,&mybuff);

printf("COntents form the structure are\n");
printf("No of msg in quque %hi\n",mybuff.msg_qnum);
printf("No of bytes in quque %hi\n",mybuff.msg_cbytes);
printf("Max no of bytes in quque %hi\n",mybuff.msg_qbytes);
return 0;


}


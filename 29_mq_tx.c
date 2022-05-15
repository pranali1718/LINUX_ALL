
#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>

struct msgbuf
{
long mtype;
char data[512];
}
 
int main(int args,char *argv[])
{
struct msg buf v;
int id;
 id message=(55,IPC_CREAT|0644);
printf("");


}


#include<stdio.h>
#include<sys/msg.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>

struct mybuff;
{
	int type;
	char data[512];
};
int main()
{

	int mqid;
	char *buff_snd;
	struct mybuff mb
	
	mqid=msgget(44,IPC_CREAT|0644);
	
	printf("MESSAGE ID:%d",mqid);

	msgrcv("mqid,&mb,strlen(mb.data)");

	

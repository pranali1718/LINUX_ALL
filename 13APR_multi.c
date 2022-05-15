#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/time.h>
#include<fcntl.h>
#include<stdlib.h>

void main()
{
	int fd1,fd2;
	fd_set read_set, write_set, except_set;	
	char buf[10];
	
	struct timeval timeout;
	
	int n,p;
	timeout.tv_sec = 90;
	
	fd1=open("./shm_srv",O_RDWR);	
	fd2=open("./shm_cli",O_RDWR);
	
	//FD_ZERO(&read_set);
	FD_ZERO(&write_set);
	//FD_ZERO(&except_set);
	
	FD_SET(fd1,&read_set);
	FD_SET(fd2,&read_set);
	
	p = select(FD_SETSIZE,&read_set,NULL,NULL,&timeout);
	n = select(FD_SETSIZE,&write_set,NULL,NULL,&timeout);
	if(n<0)
	{
		perror("select");
		exit(1);
	}
	printf("no of discriptor is ready = %d\n",n);	
}

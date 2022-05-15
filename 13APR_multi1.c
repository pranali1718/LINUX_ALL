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
	
	int n;
	timeout.tv_sec = 90;
	
	fd1=open("./shm_srv",O_RDWR);	
	fd2=open("./shm_cli",O_RDWR);
	
	FD_ZERO(&read_set);

	//FD_ZERO(&write_set);
	//FD_ZERO(&except_set);
	
	FD_SET(fd1,&read_set);
	FD_SET(fd2,&read_set);
	
	n = select(FD_SETSIZE,&read_set,NULL,NULL,&timeout);
	if(n<0)
	{
		perror("select");
		exit(1);
	}
	
	if(FD_ISSET(fd2,&read_set))
	{
	printf("reading from fd2(shm_cli)\n");
	n = read(fd2,buf,10);
	printf("read %d from shm_cli\n",n);
	}
	printf("no of discriptor is ready = %d\n",n);	
}

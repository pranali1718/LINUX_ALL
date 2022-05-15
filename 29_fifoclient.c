
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
	printf("client process writing");
	char clientmsg[]="Linux SYstem Kernel Programming";

int fd =open("cli_ser_fifo",O_WRONLY);
if (fd==-1)
{
perror("cant open fifo");
return EXIT_FAILURE;
}
write(fd,clientmsg,strlen(clientmsg));
close(fd);
return 0;

}


#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>


int main(void)
{
	printf("Server -Listening");

	int code=mkfifo("cli_ser_fifo",0764);
	if (code==-1)
		{
		perror("mkfifo returned an error-files may already exist\n");
		}
	int fd =open("cli_ser_fifo",O_RDONLY);
	if (fd==-1)
		{
		perror("cant open fifo for reas");
		return 0;
		}
	printf("FIFO OPEN\n");
	char serverrcv[100];
	memset(serverrcv,0,100);
	int res;
	char len;

	read(fd,serverrcv,100);
	printf("Server received %s\n",serverrcv);

	printf("EDF Reached\n");

	close(fd);

	printf("FIFO  Closed\n");
	return 0;

}

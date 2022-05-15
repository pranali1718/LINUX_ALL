#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	char s[20];
	int fd;


	printf("Before Open()......\n");
	fd=open("neiffoll",O_RDONLY);      //open fifo for read only
	printf("After open().......\n");

	read(fd,s,sizeof(s));
	printf("Enter Data: %s\n",s);
	
return 0;	
}

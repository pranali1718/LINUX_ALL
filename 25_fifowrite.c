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
	 
	mkfifo("newfifo",0644);
	perror("mkfifo");
	printf("Before Open()......\n");
	fd=open("neiffoll",O_WRONLY);
	printf("After open().......\n");
	printf("Enter Data.......\n");
	scanf("%s",s);
	write(fd,s,strlen(s)+1);
return 0;	
}

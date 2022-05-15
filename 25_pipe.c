#include<unistd.h>
#include<stdio.h>

int main()
{
	int fds[2];
	int res, i;
	char *buf1="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	char *buf="bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb";
	char buf2[40];

	res=pipe(fds);

	if(res==-1)
	{
	perror("pipe");
	exit(1);
	}
	write(fds[1],buf1,20);
	write(fds[1],buf,20);	
	read(fds[0],buf2,40);
	for(i=0;i<40;i++)
	printf("%c",buf2[i]);
	printf("\n");

	return 0;
}


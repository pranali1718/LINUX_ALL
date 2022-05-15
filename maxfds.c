#include<stdio.h>
#include<unistd.h>

int main()

{
	printf("max fds: %d \n"getdtablesize());
	exit(0);
}

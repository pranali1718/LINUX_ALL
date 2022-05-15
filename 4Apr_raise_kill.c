#include<stdio.h>
#include<unistd.h>

#include<signal.h>

void sig_handler(int signum)
{
	printf("Inside the Handler Function\n");
}
	int main()
	{
	pid_t pid;
		signal(SIGUSR1,sig_handler);
		printf("Inside main function\n");
		pid=getpid();
		
		kill(pid,SIGUSR1);

		printf("Inside Main Function");

		return 0;
}

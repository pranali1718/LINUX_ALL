#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

#include<signal.h>

void abort_handler(int );

int main()
{
	if(signal(SIGABRT,abort_handler)==SIG_ERR)
	{
	fprintf(stderr,"Couldnt set signal handler\n");
	exit(1);
	}
	
abort();
exit(0);
}
void abort_handler(int signum)
{
	fprintf(stderr,"Caught SIGABRT existing applicaiton\n");
	exit(0);
}


#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>


static void signal_handler(int signo)
{
	if(signo == SIGINT)
		printf("Caught SIGINT\n");
	else if(signo == SIGALRM)
		printf("Caught SIGALRM\n");
	else
	{
		printf("Caught ABRT\n");


		fprintf(stderr,"Unexpected signal! \n");
		exit(EXIT_FAILURE);
	}
exit(EXIT_SUCCESS);
}


int main(void)
{
	if(signal(SIGINT,signal_handler) == SIG_ERR)
	{
		fprintf(stderr,"Cannot Handle SIGINT! \n");
		exit(EXIT_FAILURE);
	}


	if(signal(SIGALRM,signal_handler) == SIG_ERR)
	{
		fprintf(stderr,"Cannot Handle SIGALRM! \n");
		exit(EXIT_FAILURE);
	}
alarm(4);


	if(signal(SIGABRT,SIG_DFL) == SIG_ERR)
	{
		fprintf(stderr,"Cannot reset SIFPROF! \n");
		exit(EXIT_FAILURE);
	}


abort();


	if(signal(SIGINT,SIG_IGN) == SIG_ERR)
	{
		fprintf(stderr,"Cannot Ignore SIG_HUP! \n");
		exit(EXIT_FAILURE);
	}


//for(;;)
while(1)
pause();
return 0;
}




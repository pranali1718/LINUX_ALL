#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

void printsignalset(sigset_t *set)
{
const int sigList[]={SIGHUP,SIGINT,SIGQUIT,SIGILL,SIGABRT,SIGFPE,SIGKILL,SIGSEGV};

const char *sigNames[]={"SIGHUP","SIGINT","SIGQUIT","SIGILL","SIGABRT","SIGFPE","SIGKILL","SIGSEGV"};

const int sigLen=8;

	for(int i=0;i<sigLen;i++)
	{
		int ret=sigismember(set,sigList[i]);
		if(ret == -1)
		{
			perror("sigismember:");
			exit(EXIT_FAILURE);
		}
		else if(ret == 1)
		{
			printf("Signal %s=%d IS in the set \n",sigNames[i],sigList[i]);
		}
		else 
		{
			printf("Signal %s=%d IS not in the set \n",sigNames[i],sigList[i]);
		}


	}
}
int main(void)
{
	sigset_t set;
	if(sigprocmask(0,NULL,&set)!=0)
	{
		perror("sigprocmask:");
		exit(EXIT_FAILURE);
	}
printf("-------------Initail Signal Mask for The process---------\n");
printsignalset(&set);

	if(sigaddset(&set,SIGINT)!=0)
	{	
		perror("sigaddset:");
		exit(EXIT_FAILURE);
	}
	
	if(sigprocmask(SIG_SETMASK,&set,NULL)!=0)
	{	
		perror("sigprocmask:");
		exit(EXIT_FAILURE);
	}

printf("-------------New Signal Mask for The process---------\n");
printsignalset(&set);

	int secToSleep=20;
	printf("Try CTRL+C. try killing this programw ith kill -kill %d ,Going sleep fro %d seconds\n",getpid(),secToSleep);
	sleep(secToSleep);	
	printf("Sleep returned");

	printf("removing all signals from the mask\n");
	sigemptyset(&set);
	

	sigprocmask(SIG_SETMASK,&set,NULL);
	printsignalset(&set);

	sleep(1);
	printf("Exited Normally\n");
	return 0;
}

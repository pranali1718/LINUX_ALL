#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>

int main()
{	
	int i;
	signal(SIGINT,SIG_IGN);
	for(i=0;;i++)		
	{
		printf("%d: Inside the main funcation\n",i);
		sleep(1);	
	}	
	
	return 0;
}

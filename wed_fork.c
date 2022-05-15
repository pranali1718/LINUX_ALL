/*
#include<stdio.h>
#include<unistd.h>

int main(void){
	printf("current process \n");
	fork();
	fork();

	printf("LINUX process 22 \n");
	printf("LINUX process 33 \n");
	

while(1);

return 0;
}*/

/*#include<stdio.h>
#include<unistd.h>

int main(void){
	int pid_1;
	printf("current process pid = %d \n",getpid());
	pid_1 =	fork();
	if(pid_1==0)
{	
	printf("new child process pid = %d \n",getpid());
	printf("new child parent process ppid = %d \n",getppid());
}	
	else
{
	sleep(3);
	printf("parent process pid = %d \n",getpid());
	printf("parent parent process ppid = %d \n",getppid());
}
while(1);

return 0;
}*/


#include<stdio.h>
#include<unistd.h>

int main()
{
printf("I am going to execute an'ls' program\n");
execl("/bin/ls","ls","-lh",0);

printf("i excuted ls prorgam");
printf("i excuted ls prorgam");
printf("i excuted ls prorgam");
return 0;
}

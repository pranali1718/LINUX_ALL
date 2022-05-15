//10th march//

//exectest_cmd_line//

/*
#include<stdio.h>
#include<unistd.h>

int main(int args,char *argv[])
{
	int i;
	printf("\nFile Name : %s\n"argv[0]);
	execl("/bin/ls","ls","-lh",0);

	printf("Total No of arguments");
	printf("Arguments passed");

for(i=1;i<argc;i++)
	printf("%s",argc[i]);
	printf("\n");

}
*/
/*

#include<stdio.h>


void callback1()
{
printf("Calling callback1\n");
}


void callback2()
{
printf("Calling callback2\n");
}


void callback3()
{
printf("Calling callback3\n");
}


int main()
{
printf("Registering callback1\n");
atexit(callback1);
printf("Registering callback2\n");
atexit(callback2);
printf("Registering callback3\n");
atexit(callback3);



return 0;
*/

/*
//wait function//


#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(void)
{

	pid_t pid1;
	pid1=fork();

if(pid1==0)
{
	sleep(0);
	printf("I am child with delay of 5 seconds and my chiuold process pid is :%d\n",getpid());
}
else
{
	int pid2;
	printf("I am parent pro pid = %d \n",getpid());
	pid2=wait(0);
	printf("parent saying..child %d exited terminated normally\n",pid2);
	printf("I am parent process pro pid=%d",getpid());
}
return 0;
}

*/

/*
//child exec//

#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{

	pid_t pid1;
	int option,stat;

while(1)
{
	printf("Enter 1 to execl ''ls program in child process and 0 to exit\n");
	scanf("&d",&option);
	exit(0);
	printf("\n");
	if(!option)
		exit(0);
	printf("\n");
	if(fork()==0)
{
	execl("/bin/ls","ls",0);
	exit(0);
}
}
}

*/



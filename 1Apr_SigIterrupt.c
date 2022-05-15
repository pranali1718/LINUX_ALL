#include<stdio.h>
#include<signal.h>
void sighand(int signum)
{
printf("Interrupt signal rec'd.. but no termination\n");
signal(SIGINT,SIG_DFL);
}
main()
{
int i;
signal(SIGINT,sighand);
for(i=0;;i++)
{
printf("%d\n",i);
sleep(1);
}
}

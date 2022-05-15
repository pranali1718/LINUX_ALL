#include<stdio.h>
#include<signal.h>

void check_blocked_sigs()
{
	int i,res;
	sigset_t s;
	sigprocmask(SIG_BLOCK,NULL,&s);
	for(i=1;i<5;i++)
	{
		res=sigismember(&s,i);
		if(res)
		{
		printf("Signal %d is blocked \n",i);
		}
		else
		{
		printf("Signal %d is not blocked \n",i);
		}
	}
}

int main()
{
sigset_t s_set;
sigemptyset(&s_set);
sigaddset(&s_set,2);
sigaddset(&s_set,4);
sigprocmask(SIG_BLOCK|SIG_SETMASK,&s_set,NULL);
check_blocked_sigs();
sigprocmask(SIG_UNBLOCK|SIG_SETMASK,&s_set,NULL);
return 0;
}


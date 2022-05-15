#include<stdio.h>
#include<stdlib.h>
int main()
{
int num;
	do	{
		printf("etnter number:");
		scanf("%d",&num);
		}
	while(num<0);

		int fact ;
		for(int i=1;i<=num ;i++)
		fact=fact*i;
		printf("%d!=%d\n",num,fact);
		return 0;
}

#include<stdio.h>
#include<stdlib.h>

void main()
{
	int n,*p,m;
	printf("How many Numbers?\n");
	scanf("%d",&n);
	p=(int *)calloc(n,sizeof(int));
	for(int i=0;i<n;i++)
	{
		scanf("%d",p+i);
	}
	printf("How many more Numbers you want?\n");
	scanf("%d",&m);
	p=(int *)realloc(p,(n+m)*sizeof(int));
	
	for(int i=n;i<n+m;i++)
	{
		scanf("%d",p+i);
	}

	
	int sum=0;
	for(int i=0;i<n+m;i++)
	{
		sum=sum+*(p+i);
	}
	printf("Sum is : %d \n",sum);
}

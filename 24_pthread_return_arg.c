#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
struct my_thread
{
int thread_id;
char mesg[100];
};

void *PrintHello(void *thredobj)
{
pthread_t thread_ID;
struct my_thread *t1;
t1=(struct my_thread *)thredobj;
thread_ID=pthread_self();
printf("\nThread ID:%u",thread_ID);
printf("\n%d : Thread Messge:%s",t1->thread_id,t1->mesg);
return (void *)strlen(t1->mesg);
}

int main()
{
void *res4,*res3,*res2;
pthread_t thread2,thread3,thread4,thread_ID;
int rc;
struct my_thread t2,t3,t4;
t4.thread_id=4;
strcpy(t4.mesg,"I am Fourth Thrrread\n");
t3.thread_id=3;
strcpy(t3.mesg,"I am Third Thread\n");
t2.thread_id=2;
strcpy(t2.mesg,"I am Second Thread\n");

thread_ID=pthread_self();
printf("MAIN THREAD ID:%u",thread_ID);

pthread_create(&thread4,NULL,PrintHello,&t4);
pthread_create(&thread3,NULL,PrintHello,&t3);
pthread_create(&thread2,NULL,PrintHello,&t2);

pthread_join(thread4,&res4);
pthread_join(thread3,&res3);
pthread_join(thread2,&res2);

printf("\nReturn string length of fourth :%ld\n",(long)res4);
printf("\Return string length of third :%ld\n",(long)res3);
printf("Return string length of second:%ld\n",(long)res2);
printf("\nExit from Main thread\n");
pthread_exit(NULL);
}

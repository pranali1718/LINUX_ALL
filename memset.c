
//lecture on 16 march linux//

/*
#include<stdio.h>
#include<string.h>
int main()
{
	const char str[] ="linuxkernel.com";
const char ch = '#';

printf("string before set initialization is %s\n",str);

memset (str,ch,strlen(str));

printf("string after set is %s\n",str);
return 0;
}
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{
	const char str[] ="pranali";
const char ch = '#';

printf("string before set initialization is %s\n",str);

memset (str,ch,2);

printf("string after set is %s\n",str);
return 0;
}

*/

//memchar program: str is direct pointer that is pointe to be start address and here ret is pointed to dot //
/*
#include<stdio.h>
#include<string.h>
int main()
{
	const char str[] ="pranali#mahale";
	const char ch = '#';
	char *ret;

printf("string before char/scanmis %s\n",str);
ret =memchr(str,ch,strlen(str));

printf("string after set is %c:  %s\n",ch,ret-4);
return 0;
}*/


//memcmp: it is used to compare two memory content /two memeory buffers//
//(1)the moment process excuetes memcrp funcation,jumps to 2 add func and strat comparing addressess bytes by bytes until it get unmatching data,gor given number.(2)comparing data on basis of ASCII value and get differnce of ASCII value//
/*
#include<stdio.h>
#include<string.h>
int main()
{
	char buf1[10];
	char buf2[10];
	int ret;

	memcpy(buf1,"mamdam",6);
	memcpy(buf2,"mamdam",6);

ret=memcmp(buf1,buf2,5);
		
	if(ret>0)
	{
		printf("buf1 is greater than buf2\n");
	}
	else if(ret<0)
	{
		printf("buf1 is less than buf2\n");
	}
	else
	{
		printf("buf1 is equal buf2\n");
	}

return 0;
}

*/
/*
4.memmove :the moment process executes memo operation copies the data from soruce buffer to destination buffer for given n no of bytes.(destination buffer get overritten).memofunction finally returns destination buffer location

5.memcopy:oprate same as memmove

(1)memmove is slow ,generated guaranteed data ,raliable.(2)IN case of memeory overlapping(source and destination)memo provied as guarenteed behaviour on other side (1)memcpy is fast,not reliable due to overlapping.(2)There is no temporary buffer
***************some what memmove in linux is works like \r in c language*****************************
*/

/*
#include<stdio.h>
#include<string.h>
int main()
{	
	char dest[]="oldstring";
	const char src[]="newstring";
	
printf("before memmove dest=%s src= %s\n",dest,src);

memmove(dest,src,2);
printf("after memmove dest=%s src= %s\n",dest,src);

return 0;
}
*/
/*
#include<stdio.h>
#include<string.h>
int main()
{	
	char dest[]="lavkesh";
	const char src[]="pr";
	
printf("before memmove dest=%s src= %s\n",dest,src);

memmove(dest,src,2);
printf("after memmove dest=%s src= %s\n",dest,src);

return 0;
}
*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------
~alloca:
(1)the moment process executes alloac memory call/system call allocates memeory from stat segment(if segment is full)and return pointer to allcoate region on sucess
ADVANTAGES:
a.minimum memory wastage and opearaion faster as compare to malloc().
b.alloc doesn't maintain pool of fixed block sizes & hense no memeory fragmentation.
c.need not to call free memeory call because the memeory is automatically deallocated when funcation end/terminates.

*****if repetative call is there, then there will be a stack overflow.


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *name=(char *)alloca(10);
	strcpy(name,"linux");
	printf("the copied data string is:%s\n",name);
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
	char *name=(char *)alloca(10);
	strcpy(name,"pranalii");
	printf("the copied data string is:%s\n",name);
	return 0;
}
*/	
/*
~SWAPPING PROCESS:
(1)when RAM is running out of memory and OS want to launch new application into the RAM then OS looks for the inactive processes from the RAM and pish into the swap part of stoarage of device(harddisk)and it is called as swapout process.
(2)when the newly launced application have done their job ,kernel will get back procesess from swap partition to RAM and it called as swapin process.
Memeory Lock:
(1)Scenario::there could be a login prorgam and we dont want kernel to swapout my login process from the RAM then we can apply memeory locks

^^kinds of memory locks we have
A.mlock
(1)it tookes 2 argument(void *addr,size_t nbytes)
(2)ENOMEM:the error return by mlock when trying to apply memory lock more than permitted limit will return error called ENOMEM
(3)EPERMWHen  there is no privileges then eroor ncaleed as EPERM
(4)EAGAIN:if it is failed to apply  a memeory lock to specifed address
(5)MCL_CURRENT:the current process address space is locked


B.int mlockall:

C.munlock:(void *addr,size_t nbytes)

/*
//PROGARM FOR MLOCK//

#include<stdio.h>
#include<unistd.h>
//#include<lclib.h>
main()
{
size_t i;
const int alloc_size=32 * 1024 * 1024;
char* memory=malloc(alloc_size);
mlock(memory,alloc_size);

for(i=0;i<alloc_size;i++)
memory[i]='.';
printf("allocated memeory initiated with =%s\n",memory);
munlock(memory,alloc_size);

}
*/
/*
Sbrk 
(1)it manages end of prorgram data segment
(2)takes int as return value
(3)takes a Value by which creates a new program break point

Brk
(1)BRK funcation tskes desire address to generate a new break point

****************************SBrk and Brk are used to manage memeory data segemnt*****************************\
*//*

#include<stdio.h>
#include<unistd.h>

int main(int argc,char *argv[])
{
	long int page_size = sysconf(_SC_PAGESIZE);
	printf("My page size:%ld\n",page_size);

	void * c1=sbrk(0);
	printf("Program break address:%p\n",c1);
	printf("size of char:%d\n",sizeof(char));
	c1=(void*)((char*)c1 +9);

	printf("c1:%p\n",c1);

	brk(c1);

	void* c2=sbrk(0);
	printf("prorgam break address:%p\n",c2);
}
*/

//*****************************************************************************************************************************//

#include<stdio.h>
#include<unistd.h>
int main()
{	
	const char str1[10]="Linux";
	const char str2[10];

	mymemcopy(str1,str2,10);

	printf("string in str2=%s\n");
	return 0;
}
void mymemcopy(char *src,char *dest,int count)
{
	int i;
	for(i=0;i<count;i++)
	{
	*dest=*src;
	dest++;
	src++;
	}
}



















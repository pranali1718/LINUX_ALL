/*
~MMAP OPEARTIONS~
*Prolbem UK and KS Scenario :if an application making repeatative I/O request a much of CPU times sepnt in submitting I/O opeartion
solution:mmap is a POSIX memory function that maps a goven kernekl file region or a device region or some random kernel memeory into the calling process addrress space.

Mmap syntax and arguments:
1)need to include header file
2)void *mmaap(void *addr,size_t nbytes,int protection_flags,int flag,fd/-1,off_toffset)
Is is recomanded to use 0 as addres arguemnt,here (0)indicstesasking kernel to map at free adress space
3)void *addr:address argument, where in process addresses we have to map 
4)size:no bytes we want to map
5)int protection
		PROT_READ:pages may be read
		PROT_WRITE:pages may be write
		PROT_EXEC:pages may be executed
6)int flags
	a)MAP_LOCKED:applying mlock to SHARED MEMORY region
	b)MAP_SHARED: memory shared between n number of process
	c)MAP_PRIVATE:create a private copy and changes will not  reflects to other processess which are mapping the shared region.
	d)MAP_ANONYMOUS:random memeory doesn't belongs to any file
7)Fd:
a)if not a file=-1
b)
8)off_toffset
*//*

#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
int main()
{
	char *c;
	c=mmap(0,50,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE,-1,0);
	perror("mmap");

	strcpy(c,"linuxkernel");
	printf("%s\n",c);

	munmap(c,50);

	return 0;
}

*//*
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/mman.h>
int main()
{
int fd;
char *c;
struct stat file_info;

fd=open("kernel.txt",O_CREAT|O_RDWR,0777);
write(fd,"linux internl technology",25);

fstat(fd,&file_info);
printf("file size is %d\n",file_info.st_size);

c=mmap(0,file_info.st_size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
perror("mmap");

printf("%s\n");
munmap(c,file_info.st_size);
close(fd);
return 0;
}

*//*
Library 
1)it is a pre compile object files/code.
2)static libraries are one which are statically linked to program exe program executable file at compile time.
3)dynamic library:the libraries are one which are dynamiccaly linked to program executable file at runtime
*/

#include<stdio.h>
#include"calc_mean.h"

int main(int args,char *argv[])
{
	double v1,v2,m1,m2;
	v1=5.2;
	v2=7.9;
	m1=mean(v1,v2);
	m2=sub(v1,v2);
	printf("The mean of %3.3f and %3.2f is %3.2f\n",v1,v2,m1);
	printf("The substration of %3.3f and %3.2f is %3.2f\n",v1,v2,m2);
	return 0;
}

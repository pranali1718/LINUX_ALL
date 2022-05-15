#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
/*
void handleClient(int confd)
{
    int n;
    char buf[200];
    n = read(confd,buf,200);
    buf[n] = '\0';
   
    printf("Data recieved from client = %s\n",buf);
   
    printf("Requested handled by server %d\n", getpid());
    write(confd,"Good Bye",8);
    exit(0);
}
*/



int main()
{
    int sockfd,retval,n;
   
    socklen_t clilen;
   
    struct sockaddr_in cliaddr, servaddr;
   
    //listfd = socket(AF_INET, SOCK_STREAM, 0);  //tcp ....connection
   
	char buf[10000];
	
	sockfd=socket(AF_INET,SOCK_DGRAM,0);

    if(sockfd < 0)
    {
        perror("sock");
        exit(1);
    }
   
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8000);    // TCP protocol HTTP ---port
   
    retval = bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
   
    if(retval < 0)
    {
        perror("bind:");
        exit(2);
    }

	printf("socket bound to port 8000");
	clilen=sizeof(struct sockaddr_in);
   
    while(1)
    {  
		printf(" before recv from\n");
		n=recvfrom(sockfd,buf,10000,0,(struct sockaddr *) &cliaddr, &clilen);
        printf("rec'd %d bytes \n",n);
		buf[n]='\0';
		printf("msg form client is %s \n",buf);
	} 
	close(sockfd);
       
        //printf("CLient connected \n");
}
    
   
  
   

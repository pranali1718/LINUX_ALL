#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>

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




int main()
{
    int listfd,connfd,retval;
   
    socklen_t clilen;
   
    struct sockaddr_in cliaddr, servaddr;
   
    listfd = socket(AF_INET, SOCK_STREAM, 0);  //tcp ....connection
   
    if(listfd < 0)
    {
        perror("sock");
        exit(1);
    }
   
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(8000);    // TCP protocol HTTP ---port
   
    retval = bind(listfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
   
    if(retval < 0)
    {
        perror("bind:");
        exit(2);
    }
   
    listen(listfd, 5);
   
    while(1)
    {  
        char buf[200];
		pid_t p;
        int n;
        clilen = sizeof(cliaddr);
        connfd = accept(listfd, (struct sockaddr *) &cliaddr, &clilen);
		printf("Client connect\n");
        //n = read(connfd,buf,200);
        //buf[n] = '\0';
        //printf(" Data recieved from the client = %s\n",buf);
        //write(connfd, "Good Bye",8);
       	p=fork();
		{
			close(listfd);
			handleClient(connfd);			
		}
	close(connfd);
       
        //printf("CLient connected \n");
    }
    
   
    return 0;
   
} 

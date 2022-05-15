#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>

#define PORT 8000
#define MAXSZ 100

int main()
{
    int sockfd,retval;
   	int newsockfd;

    struct sockaddr_in serveraddress;
	struct sockaddr_in clientaddress;
   
    int n;
	char msg[MAXSZ];
	int clientaddresslength;

	//create socket
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);

//initilasize the socket address

	memset(&serveraddress,0,sizeof(serveraddress));
    serveraddress.sin_family = AF_INET;
    serveraddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serveraddress.sin_port = htons(8000);    // TCP protocol HTTP ---port
   
    bind(sockfd, (struct sockaddr *) &serveraddress, sizeof(serveraddress));

	listen(sockfd,5);

    while(1)
    {  
		printf("\n*************Waiting for new client***********\n");
		clientaddresslength=sizeof(clientaddress);
		newsockfd=accept(sockfd,(struct sockaddr *)&clientaddress,&clientaddresslength);
		
		while(1)
		{
			n=recv(newsockfd,msg,MAXSZ,0);
			if(n==0)
			{
				close(newsockfd);		
				break;
			}
		msg[n]=0;
		send(newsockfd,msg,n,0);
		printf("Receive ans set : %s",msg);
		}	
	} return 0; 
        //printf("CLient connected \n");
}
    
   
  
   

#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<arpa/inet.h>


#define PORT 8000
#define SERVER_IP "127.0.01"
#define MAXSZ 100

int main()
{	
	int sockfd;
	
	struct sockaddr_in serveraddress;

	int n;
	char msg1[MAXSZ];
	char msg2[MAXSZ];
	sockfd = socket(AF_INET,SOCK_STREAM,0);

	memset(&serveraddress,0,sizeof(serveraddress));
	serveraddress.sin_family = AF_INET;
    serveraddress.sin_addr.s_addr = inet_addr(SERVER_IP);
    serveraddress.sin_port = htons(PORT);
	connect(sockfd,(struct sockaddr *)&serveraddress,sizeof(serveraddress));
	
	while(1)
    {  
		printf("\nEnter msg to sedn to server\n");
		fgets(msg1,MAXSZ,stdin);
		if(msg1[0]=='#')		
		break;
		
		n=strlen(msg1)+1;
		send(sockfd,msg1,n,0);
		n=recv(sockfd,msg2,n,0);
		
		printf("Receive msg form server :%s\n",msg1);	
	} return 0; 
	//close(sockfd);
}

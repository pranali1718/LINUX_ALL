#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netpacket/packet.h>
#include<net/ethernet.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void main()
{
	int pack_socket,n;
	struct sockaddr_ll sa;
	socklen_t sl;
	char buf[2000];
	sl = sizeof(struct sockaddr_ll);

	pack_socket = socket(PF_PACKET,SOCK_RAW,htons(ETH_P_ALL));
	if(pack_socket < 0)
	{	
		printf("Failed to open packet \n");
		exit(0);
	}
	printf("Packet socket succesfully opened \n");
	while(1)
	{
		n=recvfrom(pack_socket,buf,2000,0,(struct sockaddr *)&sa,&sl);
		printf("received packet of length %d \n", n);
	}
close(pack_socket);
}

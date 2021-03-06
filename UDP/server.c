#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
int main(char*argv[],int argc )
{
  	int port = 1235;
  	int sockfd;
  	struct sockaddr_in serverAddr;
  	char buffer[1024];
  	socklen_t addr_size;

  	sockfd = socket(PF_INET, SOCK_DGRAM, 0);
  	memset(&serverAddr, '\0', sizeof(serverAddr));

  	serverAddr.sin_family = AF_INET;
  	serverAddr.sin_port = htons(port);
  	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	scanf("%s",buffer);
  	sendto(sockfd, buffer, 1024, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
  	printf("Client: %s", buffer);
  	return 0;
}

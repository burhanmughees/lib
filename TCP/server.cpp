#include <iostream>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <arpa/inet.h>

using namespace std;

int main()
{
	char msg[100]	;
	struct in_addr addr;
	int conn_sock, comm_sock, n;
	struct sockaddr_in server_addr, client_addr;
	conn_sock = socket(AF_INET, SOCK_STREAM, 0);
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = 1234;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	bind(conn_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
	listen(conn_sock, 10);
	comm_sock = accept(conn_sock, (struct sockaddr *)
	&client_addr, (socklen_t *)& client_addr);
	cout << "\n\nConnection Established with Client";
	n=read(comm_sock, msg, 100);
	cout << "\n\nReceived Data From Client: " << msg;
	close(comm_sock);
	close(conn_sock);
	return 0;

}

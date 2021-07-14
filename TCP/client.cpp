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
char msg[100]= "Hello World!"
struct in_addr addr;
int comm_sock, n;
struct sockaddr_in server_addr, client_addr;
comm_sock = socket(AF_INET, SOCK_STREAM, 0);
server_addr.sin_family = AF_INET;
server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
server_addr.sin_port = 1234;
connect(comm_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
write(comm_sock, msg, sizeof(msg));
close(comm_sock);

return 0;
}

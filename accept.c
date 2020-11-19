#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

//int accept(socd, (struct sockaddr*)&client, (socklen_t*)&c)));
int main(int argc, char *argv[]) {

int socd, new_socket, c;
struct sockaddr_in server, client;
char *message;

//CREATE SOCKET
socd = socket(AF_INET, SOCK_STREAM, 0);
if(socd == -1) {
printf("Could not create socket");
}

//PREPARE TEH SOCKADDR_IN STRUCTURE
server.sin_family = AF_INET;
server.sin_addr.s_addr = INADDR_ANY;
server.sin_port = htons(8888);

//BIND
if(bind(socd, (struct sockaddr *)&server, sizeof(server))<0) {
puts("Bind failed");
return 1;
}
puts("Bind done");

//LISTEN
listen(socd, 3);

//ACCEPT AND INCOMING CONNECTION
puts("Waiting for incoming connections...");
c = sizeof(struct sockaddr_in);
while((new_socket = accept(socd, (struct sockaddr *)&client, (socklen_t*)&c)) ) {

if(new_socket < 0) {
perror("Accept failed");
}
}
puts("Acccepted");

close(socd);
return 0;
}

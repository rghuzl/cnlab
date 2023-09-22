#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
    // server side buffer
    char buffer[100];

    // create server socket
    int server_socket;
    server_socket = socket(AF_INET,SOCK_STREAM,0);

    // define addess
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind 
    bind(server_socket,(struct sockaddr*)&server_address,sizeof(server_address));
    listen(server_socket,5);
    
    // accept connection on new socket
    int new_socket;
    new_socket = accept(server_socket,NULL,NULL);

    // send the msg to the client
    send(new_socket,"hi",3,0);
    
    return 0;
}
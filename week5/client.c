#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
    // client buffer
    char buffer[100];

    // client socket 
    int client_socket;
    client_socket = socket(AF_INET,SOCK_STREAM,0);

    // define server address
    struct sockaddr_in server_address; 
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // connect to server
    int status = connect(client_socket,(struct sockaddr*) &server_address,sizeof(server_address));
    if(status == -1)
    {
        printf("ERROR! while connecting to server\n");
        return 0;
    }

    // if connected successfully 
    // send msg to server
    send(client_socket,"Hi",20,0);

    // receive data from server
    recv(client_socket,buffer,sizeof(buffer),0);

    // verify connection
    printf("\nreceived data : %s\n\n",buffer);
}
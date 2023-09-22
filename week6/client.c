#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
    // client buffer
    char buffer[100];

    // client socket
    int client_socket = socket(AF_INET,SOCK_STREAM,0);
    if(client_socket == -1){
        printf("\n\x1B[31merror! socket creation failed\x1B[0m\n");
        exit(EXIT_FAILURE);
    }
    
    // socket created successful
    // define server address
    struct sockaddr_in remote_address;
    remote_address.sin_family = AF_INET;
    remote_address.sin_port = htons(8000);
    remote_address.sin_addr.s_addr = INADDR_ANY;

    // send a connect request 
    int status = connect(client_socket,(struct sockaddr*)&remote_address,sizeof(remote_address));

    if(!status){
        // receive value
        send(client_socket,"hi",10,0);
        recv(client_socket,buffer,sizeof(buffer),0);

        printf("\n%s\n",buffer);

        // close socket
        // close(client_socket);

        
    }
}
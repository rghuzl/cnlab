#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
    // server buffer
    char buffer[100];

    // server socket
    int server_socket = socket(AF_INET,SOCK_STREAM,0);
    if(server_socket == -1){
        printf("\n\x1B[31merror! socket creation failed\x1B[0m\n");
        exit(EXIT_FAILURE);
    }
    
    // socket created successful
    // define server address
    struct sockaddr_in server_address,clientAddress;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    clientAddress.sin_addr.s_addr = INADDR_ANY;
    clientAddress.sin_family = AF_INET;
    clientAddress.sin_port = htons(8000);

    // bind 
    bind(server_socket,(struct sockaddr*)&server_address,sizeof(server_address));

    // listen
    listen(server_socket,5);

    // accept
    int len = sizeof(clientAddress);
    int client_socket = accept(server_socket,(struct sockaddr*)&clientAddress,&len);
    printf("\n%d\n",clientAddress.sin_addr.s_addr);
    recv(client_socket,buffer,sizeof(buffer),0);
    char* msg = (char*)malloc(100*sizeof(char));
    msg = "hey client ";//tostring(clientAddress.sin_addr.s_addr);

    // sizeof msg?
    // client ip address ?

    send(client_socket,msg,20,0);

    close(client_socket);
    close(server_socket);
}
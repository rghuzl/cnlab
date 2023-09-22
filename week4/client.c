#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>

int main()
{
    // client buffer
    char buffer[100];

    // create socket 
    int client_socket;
    client_socket = socket(AF_INET,SOCK_STREAM,0);


    // define address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // connect with server
    int status =  connect(client_socket,(struct sockaddr*)&server_address,sizeof(server_address));
    if(status )
    {
        printf("ERROR! while connecting\n");
        return 0;
    }  
    
    // receive/send data
    recv(client_socket,buffer,sizeof(buffer),0);

    // verify connection
    printf("received data is : %s\n",buffer);

    return 0;
}
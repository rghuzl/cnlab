#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

int main()
{
    // server buffer
    char buffer[100];

    // server socket 
    int server_socket;
    server_socket = socket(AF_INET,SOCK_STREAM,0);

    // define server address
    struct sockaddr_in server_address; 
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8000);
    server_address.sin_addr.s_addr = INADDR_ANY;


    // bind socket and address
    bind(server_socket,(struct sockaddr*) &server_address,sizeof(server_address));
    listen(server_socket,10);

    

    // create a new socket to  accept the connection
    int new_socket;
    new_socket= accept(server_socket,NULL,NULL);


    // recv msg from client
    recv(new_socket,buffer,sizeof(buffer),0);
    
    char *msg = (char*)malloc(100*sizeof(char));

    if(!strcmp(buffer,"Hello Server"))
    {
        // now send the msg to client
        msg= "Hi Client,How are you?";
        send(new_socket,msg,strlen(msg),0);
    }
    else
    {
        msg = "Text other than \'Hello Server\' is sent from you";
        send(new_socket,msg,strlen(msg),0);
    }
    // close the socket 
    close(new_socket);
    close(server_socket);

}
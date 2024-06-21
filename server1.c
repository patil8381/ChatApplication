#include<windows.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int main()
{
WORD ver;
WSADATA wsaData;
int clientSocket;
int serverSocket;
struct sockaddr_in serverSocketInformation;
struct sockaddr_in clientSocketInformation;
char response[5000];
char request[5000];
int successCode;
int len;

ver=MAKEWORD(1,1);
WSAStartup(ver,&wsaData);
serverSocket=socket(AF_INET,SOCK_STREAM,0);
if(serverSocket<0)
{
printf("unable to create socket");
return 0;
}
serverSocketInformation.sin_family=AF_INET;
serverSocketInformation.sin_port=htons(5050);
serverSocketInformation.sin_addr.s_addr=htonl(INADDR_ANY);
successCode=bind(serverSocket,(struct sockaddr *)&serverSocketInformation,sizeof(serverSocketInformation));
if(successCode<0)
{
printf("unable to bind socket\n");
WSACleanup();
return 0;
}
listen(serverSocket,10);
printf("Server is ready to accept connection on port 5050.\n");
len=sizeof(clientSocketInformation);
clientSocket=accept(serverSocket,(struct sockaddr *)&clientSocketInformation,&len);
if(clientSocket<0)
{
printf("unable to accept client connection\n");
closesocket(serverSocket);
WSACleanup();
return 0;
}
printf("send '0' to close the application.\n");
printf("wating for input from client.....\n");
while(true)
{
request[0]='\0';
response[0]='\0';
successCode=recv(clientSocket,request,sizeof(request),0);
if(successCode>0)
{
printf("client : %s\n",request);
}
if(request[0]=='0') 
{
response[0]='0';
send(clientSocket,response,strlen(response)+1,0);
printf("Client closed the application.\n");
break;
}
printf("me : ");
fgets(response,5000,stdin);
response[strlen(response)-1]='\0';
if(response[0]=='0') 
{
response[0]='0';
send(clientSocket,response,strlen(response)+1,0);
printf("Server closed the application.\n");
break;
}
send(clientSocket,response,strlen(response)+1,0);
}
printf("Server Closed.\n");
closesocket(serverSocket);
closesocket(clientSocket);
WSACleanup();
return 0;
}
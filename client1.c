#include<stdio.h>
#include<string.h>
#include<windows.h>
int main()
{
WORD ver;
WSADATA wsaData;
int serverSocket;
int clientSocket;
struct sockaddr_in serverSocketInformation;
char request[5000];
char response[5000];
int successCode;

ver=MAKEWORD(1,1);
WSAStartup(ver,&wsaData);
clientSocket=socket(AF_INET,SOCK_STREAM,0);
serverSocketInformation.sin_family=AF_INET;
serverSocketInformation.sin_port=htons(5050);
serverSocketInformation.sin_addr.s_addr=inet_addr("192.168.1.4");

connect(clientSocket,(struct sockaddr *)&serverSocketInformation,sizeof(serverSocketInformation));
//strcpy(request,"Hello Thinking Machines I have done C++ course");
printf("Connected to server.\n");
printf("send '0' to close the application.\n");
while(1)
{
request[0]='\0';
response[0]='\0';
printf("me : ");
fgets(request,5000,stdin);
request[strlen(request)-1]='\0';
if(request[0]=='0') printf("Client Closed the application.\n");
successCode=send(clientSocket,request,strlen(request)+1,0);
if(successCode<0)
{
printf("cannot sent data\n");
return 0;
}
successCode=recv(clientSocket,response,sizeof(response),0);
if(response[0]=='0')
{
printf("Application closed.\n");
break;
}
if(successCode<0)
{
printf("cannot recv data\n");
return 0;
}
printf("server : %s\n",response);
}
closesocket(clientSocket);
WSACleanup();
return 0;
}
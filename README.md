Hi,
I am shubham patil, 
I have created the chat application where I have creted a socket and bind it to the IP and port number the function to send and recieve data on TCP/IP protocol and 
same on the client side cretad a socket and connecting to the server with specifying ip and neccessary functionalites to send and recieve data.

If you also want to run this chat application on your Desktop/pc  just follow the below steps.
1) git clone https://github.com/patil8381/ChatApplication.git
2) now you have both server and client code.
3) Open client1.c and change IP on line no. 19 at serverSocketInformation.sin_addr.s_addr=inet_addr("192.168.1.4");
4) Now save the changes and compile using below command in command prompt in windows.
5) gcc server1.c -o server1.exe -lws2_32
6) gcc client1.c -o client1.exe -lws2_32
7) Now run the server1.exe and
8) In another command prompt or other laptop change compile and run client1.exe

Now you are all set to chat endless....
you can exit the application by sending 0 from both side.

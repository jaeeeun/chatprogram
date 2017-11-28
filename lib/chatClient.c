#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "../include/chatClient.h"
#define BUFSIZE 1024


void client()
{

   //tcp socket create
   int c_sock;
   c_sock=socket(PF_INET,SOCK_STREAM,0);

   struct sockaddr_in server_addr;
   int recv_len;
   char message[BUFSIZE];
   char name[BUFSIZE];


   /* pid */
   pid_t pid;

   /* server address,port */
   int serverPort;
   char *serverAddr="0.0.0.0";
  
   //printf("server address:");
   //scanf("%s",serverAddr);
   printf("server port:");
   scanf("%d",&serverPort);


   printf("input your name :");
   scanf("%s",name);
   printf("your name is %s \n",name);
   printf("\n");

   memset(&server_addr,0,sizeof(server_addr));
   server_addr.sin_family=AF_INET;
   server_addr.sin_addr.s_addr=inet_addr(serverAddr);
   server_addr.sin_port=htons(serverPort);



   //tcp connect

   if(connect(c_sock,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
   {
      printf("talk client can't connect \n");
     
   }

   printf("┌──────────────────────────────────────────────┐\n");
   printf("│          client connect to server            │ \n");
   printf("│              talk with server                │\n");
   printf("│ if u want to quit connect, plz inptu Q or q  │\n");
   printf("└──────────────────────────────────────────────┘\n");
  
   
  
   pid=fork(); // make child process
 
  
   recv_len=read(c_sock,message,BUFSIZE);
   message[recv_len]=0;

   while(1)
   {
      
      if(pid==0)
      {
         if(recv_len>1)
         {
            recv_len=read(c_sock,message,BUFSIZE);
            if(!strcmp(message,"Q\n")||!strcmp(message,"q\n"))
             { printf("Server exited CHATTING..\n");
             break;
             }
            message[recv_len]=0;
            printf("server : %s",message);
         }
   
      }
      else
      {
          //printf("client : ");
          fgets(message,BUFSIZE,stdin);

          if(!strcmp(message,"Q\n")||!strcmp(message,"q\n"))
          {
             write(c_sock,message,BUFSIZE);
             printf("you exited chatting...\n");
            shutdown(c_sock,SHUT_WR);
          break;} 
          write(c_sock,message,BUFSIZE);
      }
     
     printf("\n");
   }


   close(c_sock);
   
}

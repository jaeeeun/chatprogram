#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "../include/error_handle.h"
#define BUFSIZE 1024
#include <time.h>

void client()
{

   //tcp socket create
   int c_sock, flag = 0;

   struct sockaddr_in server_addr;
   int recv_len;
   char message[BUFSIZE];   

   /* pid */
   pid_t pid;

   /* timer */
   time_t timer;
   struct tm *t;
   timer=time(NULL);
   t=localtime(&timer);

   /* server address,port */
   char serverPort[5];
   char serverAddr[20];
  
   printf("Input Server IP address :");
   scanf("%s",serverAddr);
   printf("Input Server Port Number : ");
   scanf("%s",serverPort);


   c_sock = socket(PF_INET, SOCK_STREAM, 0);
   if(c_sock == -1)
   	error("Client_socket() error");

   memset(&server_addr,0,sizeof(server_addr));
   server_addr.sin_family=AF_INET;
   server_addr.sin_addr.s_addr=inet_addr(serverAddr);
   server_addr.sin_port=htons(atoi(serverPort));



   //tcp connect

   if(connect(c_sock,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
   {
      error("Talk client can't connect");
     
   }

   printf("┌──────────────────────────────────────────────┐\n");
   printf("│         Client Connected to Server           │\n");
   printf("│              Talk With Server                │\n");
   printf("│ If u want to quit connect, Plz input Q or q  │\n");
   printf("└──────────────────────────────────────────────┘\n");
  
   
  
   pid=fork(); // make child process
 
  

   while(1)
   {
      
      if(pid==0)
      {
            recv_len=read(c_sock,message,BUFSIZE);

         if(recv_len>1)
         {
		            
            if(!strcmp(message,"Q\n")||!strcmp(message,"q\n"))
             { 
		printf("====== Server exited Chatting ======\n");
//                printf("if you want quit a chat, input q or Q\n");
//		flag = 1;
             	break;
             }
		
		
		
		message[recv_len] = 0;
		printf("[%d:%d]From Server : %s",t->tm_hour,t->tm_min, message);			
		  
      	}
    }
    else
    {
          //printf("client : ");

          fgets(message, BUFSIZE, stdin);

          if(!strcmp(message,"Q\n")||!strcmp(message,"q\n"))
          {
             write(c_sock, message, BUFSIZE);
             printf("__YOU[Client] Exited Chatting__\n");
             //shutdown(c_sock,SHUT_WR);
//		flag = 1;
             break;
	   }
	 
	
//	if(flag == 0)
          write(c_sock,message,BUFSIZE);
      	  }

	

     
     printf("\n");
   }


   close(c_sock);
   
}

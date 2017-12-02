#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include "../include/error_handle.h"
#define BUFSIZE 1024


void client()
{

   //tcp socket create
   int c_sock, flag = 0;

   struct sockaddr_in server_addr;
   int recv_len;
   char message[BUFSIZE];
   char name[BUFSIZE];
   

   /* pid */
   pid_t pid;

   /* server address,port */
   char serverPort[5];
   char *serverAddr = "0.0.0.0";
  
   //printf("server address:");
   //scanf("%s",serverAddr);
   printf("Input Server Port Number : ");
   scanf("%s",serverPort);

   c_sock = socket(PF_INET, SOCK_STREAM, 0);
   if(c_sock == -1)
   	error("Client_socket() error");


   printf("\nInput your name :");
   scanf("%s", name);
   printf("Your name is %s \n",name);
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
   printf("│          Client Connect To Server            │\n");
   printf("│              Talk With Server                │\n");
   printf("│ If u want to quit connect, Plz input Q or q  │\n");
   printf("└──────────────────────────────────────────────┘\n");
  
   
  
   pid=fork(); // make child process
 
  
  // recv_len=read(c_sock,message,BUFSIZE);
   //message[recv_len]=0;

   while(1)
   {
      
      if(pid==0)
      {
            recv_len=read(c_sock,message,BUFSIZE);

         if(recv_len>1)
         {
		            
            if(!strcmp(message,"Q\n")||!strcmp(message,"q\n"))
             { 
		printf("== Server EXITed Chatting ==\n");
//		flag = 1;
             	break;
             }
		
		
		
		message[recv_len] = 0;
		printf("From Server : %s", message);			
		  
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

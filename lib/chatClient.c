#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <stdlib.h>

#define BUFSIZE 1000
#define PORT 9000
#define IPADDR "0.0.0.0"

char buffer[BUFSIZE];
char sndBuffer[BUFSIZE], rcvBuffer[BUFSIZE];


int main(int argc,char*argv[])
{

   //tcp socket create
   int c_sock;
   c_sock=socket(PF_INET,SOCK_STREAM,0);

   struct sockaddr_in server_addr;
   int len;
   int n;
   char rcvBuffer[BUFSIZE];
   int str_len,recv_len,recv_cnt;
   char messagep[BUFSIZE];

   /* server address,port */
   int serverPort;
   char *serverAddr;
  
   printf("server address:");
   scanf("%s\n",serverAddr);
   printf("server port:");
   scanf("%d\n",&serverPort);

   /*---------------------*/

   // connect the sockect for server
  // if(connect(c_sock,(struct sockaddr*) &server_addr,sizeof(server_addr))==-1)
  // {
    //  printf("cannot connect\n");
    //  close(c_sock);
   //   return -1;
 //  }

   memset(&server_addr,0,sizeof(server_addr));
   //bzero((char*) &server_addr,sizeof(server_addr));
   server_addr.sin_family=AF_INEF;
   server_addr.sin_addr.s_addr=inet_addr(serverAddr);
   server_addr.sin_port=htons(serverPort);


   if(connect(c_sock,(struct sockaddr *)&server_addr,sizeof(server_addr))<0)
   {
      printf("talk client can't connect \n");
      return -1;
   }
   printf("talk client connect to talk server\n");

   while(1)
   {
      fputs("Input message(Q to Quit) :",stdout);
      fgets(message, BUFSIZE, stdin);

      if(!strcmp(message,"q\n")||!strcmp(message,"Q\n"))
         break;
      str_len=write(c_sock,message,strlen(message));
      recv_len=0;
      while(recv_len<str_len)
      {
          recv_cnt = read(c_sock,&message[recv_len],BUFSIZE);
          if(recv_cnt ==-1)
               printf("error");
          recv_len+=recv_cnt;
      }
      
      message[str_len]=0;
      printf("Message from server : %s",message);
   }

   close(c_sock);
   return 0;
}

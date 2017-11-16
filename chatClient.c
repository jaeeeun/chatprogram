#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFSIZE 1000
#define PORT 9000
#define IPADDR "0.0.0.0"

char buffer[BUFSIZE];

int main(int argc,char*argv[])
{

   //tcp socket create
   int c_sock;
   c_sock=socket(PF_INET,SOCK_STREAM,0);

   struct sockaddr_in c_addr;
   int len;
   int n;
   char rcvBuffer[BUFSIZE];
   if(c_sock==-1)
   {
      error("socket() error");
   }


   /* set the server address that connect clinet*/ 
   memset(&c_addr,0,sizeof(c_addr));
   //c_addr.sin_addr.s_addr=inet_ddr(IPADDR);
   c_addr.sin_family=AF_INET;
   c_addr.sin_port=htons(PORT);

   // connect the sockect for server
   if(connect(c_sock,(struct sockaddr*) &c_addr,sizeof(c_addr))==-1)
   {
      printf("cannot connect\n");
      close(c_sock);
      return -1;
   }

   // send and receive
   scanf("%s",buffer);
   buffer[strlen(buffer)]='\0';
   write(c_sock,buffer,strlen(buffer)+1);

   // request the service and processing
   if ((n=read(c_sock,rcvBuffer,sizeof(rcvBuffer)))<0)
   {
      return -1;
   }
   rcvBuffer[n]='\0';
   printf("received Data : %s\n",rcvBuffer);

   close(c_socket);
}

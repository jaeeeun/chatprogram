#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFSIZE 1000
#define PORT 9000
#define IPADDR "0.0.0.0"

char buffer[BUFSIZE];
char sndBuffer[BUFSIZE], rcvBuffer[BUFSIZE];

pid_t pid;

int main(int argc,char*argv[])
{

   //tcp socket create
   int c_sock;
   c_sock=socket(PF_INET,SOCK_STREAM,0);

   struct sockaddr_in server_addr;
   int len;
   int n;
   int n_left,n_recv;
   char rcvBuffer[BUFSIZE];

   /* server address,port */
   int serverPort;
   char *serverAddr;
  
   printf("server address:");
   scanf("%s\n",&serverAddr);
   printf("server port:");
   scanf("%d\n",&serverPort);

   /*---------------------*/



   /* set the server address that connect clinet*/ 
   // memset(&c_addr,0,sizeof(c_addr));
   // c_addr.sin_addr.s_addr=inet_ddr(IPADDR);
   // c_addr.sin_family=AF_INET;
   // c_addr.sin_port=htons(PORT);

   // connect the sockect for server
   if(connect(c_sock,(struct sockaddr*) &c_addr,sizeof(c_addr))==-1)
   {
      printf("cannot connect\n");
      close(c_sock);
      return -1;
   }

   bzero((char*) &server_addr,sizeof(server_addr));
   server_addr.sin_family=AF_INEF;
   server_addr.sin_addr.s_addr=inet_addr(serverAddr);
   server_addr.sin_port=htons(serverPort);


   if(connect(connSOck,(Struct sockaddr *)&server_addr,sizeof(server)addr))<0)
   {
      printf("talk client can't connect \n");
      return -1;
   }
   printf("talk client connect to talk server\n");

   if(pid=fork())<0)
   {
      printf("fork error\n");
      return -1;
   }
   else if(pid>0)
   {
     //keybord
   }
   else if(pid==0)
   {
     //socket
   }
   close(sock);
}

   // send and receive
  // scanf("%s",buffer);
   //buffer[strlen(buffer)]='\0';
   //write(c_sock,buffer,strlen(buffer)+1);

   /*
   while(1){
   if((n=read(0,sndBuffer,BUFSIZE))>0)
   {

     sndBuffer[n]='\0';
     if(!strcmp(sndBuffer,"quit\n")) break;
  
    printf("original data : %s", sndBuffer);
    if((n=write(c_sock,sndBuffer,strlen(sndBuffer)))<0)
    {
     return (-1);
    }


    n_left=n;
    n_recv=0;

    while(n_left >0)
    {
      if((n=read(c_sock,&rcvBuffer[n_recv],n_left))<0)
      {
        return (-1);
      }
      n_left=n_left-n;
      n_recv=n_recv+n;
    }

   rcvBuffer[n_recv]='\0';
   printf("echod data : %s",rcvBuffer);
  }
   // request the service and processing
  // if ((n=read(c_sock,rcvBuffer,sizeof(rcvBuffer)))<0)
  // {
  //    return (-1);
  // }
  // rcvBuffer[n]='\0';
  // printf("received Data : %s\n",rcvBuffer);
}
*/
   close(c_sock);
}

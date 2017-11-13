#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc,char*argv[])
{

   //tcp socket create
   int sock;
   sock=socket(PF_INET,SOCK_STREAM,0);
   if(sock==-1)
   {
      error("socket() error");
   }

   printf("File Discripteor of crated TCP socekt : %d \n",sock);

   close(sock);

}

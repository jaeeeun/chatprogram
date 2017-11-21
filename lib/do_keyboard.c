#include <stdio.h>

do_keyboard(int connSock)
{
   int n;
   char sbuf[BUFSIZ];
  
   while(n=read(0,sbuf,BUFSIZ))>0)
   {
     if(write(connSOck,sbuf,n)!=n)
     {
       printf("Talk server fail in sending\n"); 
     }

     if(strncmp(sbuf,quit,4)==0)
     {
       kill(pid,SIGQUIT);
       break;
     }
   }

}

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>


int main(int argc,char *argv[])
{

  int fd;
  int num_bytes;
  num_bytes=atoi(argv[2]);
 
  if(argc==3)
  {
     int i;
     fd=open(argv[1],O_WRONLY|O_CREAT|O_APPEND,0666);
     if(fd==-1)
     {
        perror("open");
        exit(0);
     }
     for(i=1; i<=num_bytes;i++)
     {
        write(fd,"x",1);
     }
     
 }
  else if (argc==4 && !strcmp(argv[3],"x"))
  {
     int i;
     int num_bytes=atoi(argv[2]);
     fd=open(argv[1],O_WRONLY|O_CREAT,0666);
     if(fd==-1)
     {
        perror("open");
        exit(0);
     }
//     lseek(fd,0,SEEK_END);
     for(i=1;i<=num_bytes;i++)
     {
        lseek(fd,0,SEEK_END);
        write(fd,"x",1);
     }
  }
  close(fd);
  return 0;
}


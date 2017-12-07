#include <stdio.h>
#include "../include/chatServer.h"
#include "../include/chatClient.h"
#include <stdlib.h>

int main()
{

  int n;

   printf("              * welcome to chat *               \n");
   printf("┌──────────────────────────────────────────────┐\n");
   printf("│                                              │\n");
   printf("│             1. make a room                   │\n");
   printf("│             2. entry a room                  │\n");
   printf("│                                              │\n");
   printf("└──────────────────────────────────────────────┘\n");


   scanf("%d",&n);

  while(1)
  {
     if(n==1)
     {
        system("clear");
        server();
	break;
     }
     else if(n==2)
     {
        system("clear");
        client();
	break;
     }
     else
     {
	printf("Input Option [ 1 or 2 ] : " );
	scanf("%d", &n);
	printf("\n");
     }
  }

  return 0;
}

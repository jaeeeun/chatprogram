#include <stdio.h>
#include "../include/chatServer.h"
#include "../include/chatClient.h"

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
        server();
	break;
     }
     else if(n==2)
     {
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

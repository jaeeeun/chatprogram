#include <stdio.h>
#include "../include/chatClient.h"
#include "../include/chatServer.h"

int main()
{
  printf("              * welcome to chat *               \n");
  printf("┌──────────────────────────────────────────────┐\n");  
  printf("│                                              │\n");  
  printf("│             1. made a room                   │\n");  
  printf("│             2. entry a room                  │\n");  
  printf("│                                              │\n");  
  printf("└──────────────────────────────────────────────┘\n");

 
  int n;
  scanf("%d",&n);

  while(1)
  {
     if(n==1)
     {
        chatServer();
     }
     else if(n==2)
     {
        chatClient();
     }
     else
     {
       scanf("%d",&n);
     }

}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include"../include/error_handle.h"
#define BUFSIZE 1024

void server()
{
	int s_sock, c_sock, recv_len, flag = 0;
	char message[BUFSIZE], PORT[5];

        struct sockaddr_in s_addr;
        struct sockaddr_in c_addr;

	socklen_t clnt_addr_size;
	

	pid_t pid;

	printf("Input Server Port Number : ");
	fflush(stdin);
	scanf("%s", PORT);
	printf("waiting for client...\n\n");
	
	s_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(s_sock == -1)
		error("Server_socket() error");

	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_family=AF_INET;
	s_addr.sin_addr.s_addr=htonl(INADDR_ANY);
        s_addr.sin_port=htons(atoi(PORT));


	if(bind(s_sock, (struct sockaddr*) &s_addr, sizeof(s_addr))==-1)
		error("Bind() error");

	if(listen(s_sock, 5)==-1)
		error("Listen() error");

	clnt_addr_size = sizeof(c_addr);

	c_sock = accept(s_sock, (struct sockaddr*)&c_sock, &clnt_addr_size);
        if(c_sock == -1)
                error("Accept() error");

	printf("┌──────────────────────────────────────────────┐\n");
   	printf("│          Server Connect To Client            │\n");
   	printf("│              Talk With Client                │\n");
   	printf("│ If u want to quit connect, Plz input Q or q  │\n");
   	printf("└──────────────────────────────────────────────┘\n");

		
	//write(c_sock, s_message, sizeof(serv_message));
	
	pid = fork();
	
	
	while(1)
	{
		if(pid == 0)
		{
			recv_len = read(c_sock, message, BUFSIZE);
			
	
			if(recv_len > 1)
			{
			
				if(!strcmp(message, "q\n") || !strcmp(message, "Q\n") )
                        	{
                                	printf("== Client EXITed Chatting ==\n");
                                	//flag = 1;
                                	
                                	break;
                        	}
				
				
				message[recv_len] = 0;
				printf("From Client : %s",message);
				
				

			}
		}
		else
		{
			fgets(message, BUFSIZE, stdin);
			
			if(!strcmp(message, "q\n") || !strcmp(message, "Q\n") )
                        {      
                                
                                write(c_sock, message, BUFSIZE);
				printf("__You[Server] Exited Chatting__\n");
				//shutdown(c_sock, SHUT_WR);
				//flag = 1;
                                break;
                        }
			
			//if(flag == 0)
			write(c_sock, message,BUFSIZE);

		}
				
		printf("\n");		
	

	}//pid

			
		close(s_sock);
		close(c_sock);
//		return 0;
	

}



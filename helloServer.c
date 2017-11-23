#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/wait.h>

#define BUFSIZE 1024

void error(char *message)
{
	fputs(message, stderr);
	fputc(' ', stderr);
	exit(1);
}

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock, recv_len,status;
	char message[BUFSIZE], PORT[5];

	char serv_message[] = "Welcom to chatting server!!\n";

        struct sockaddr_in serv_addr;
        struct sockaddr_in clnt_addr;

	socklen_t clnt_addr_size;
	

	pid_t pid;

	printf("Input Server Port Number : ");
	fflush(stdin);
	scanf("%s", PORT);
	
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if(serv_sock == -1)
		error("socket() error\n");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
         serv_addr.sin_port=htons(atoi(PORT));


	if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr))==-1)
		error("bind() error");

	if(listen(serv_sock, 5)==-1)
		error("listen() error");

	clnt_addr_size = sizeof(clnt_addr);

	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_sock, &clnt_addr_size);
        if(clnt_sock == -1)
                error("accept() error\n");
	else
	{
		printf("connected Client\n");
		printf("Chatting ON");
		write(clnt_sock, serv_message, sizeof(serv_message));
		pid = fork();
	}
	
	while(1)
	{
		if(pid == 0)
		{
			recv_len = read(clnt_sock, message, BUFSIZE);
	
			if(recv_len > 1)
			{
				message[recv_len] = 0;
				printf("message form Client : %s",message);
			}


		}
		else
		{
			fgets(message, BUFSIZE, stdin);
			
			write(clnt_sock, message,BUFSIZE);

		}	
		
	}


	close(serv_sock);
	close(clnt_sock);
	return 0;

}



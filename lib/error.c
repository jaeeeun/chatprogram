#include<stdlib.h>
#include<unistd.h>

void error(char *message)
{
	fputs(message, stderr);
	fputc('\n',stderr);
	exit(1);
}

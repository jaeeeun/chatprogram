libfuncs.a : chatServer.o chatClient.o
	ar rv libfuncs.a chatServer.o chatClient.o

chatServer.o : chatServer.c ../include/chatServer.h
	gcc -o chatServer.o -c chatServer.c

chatClient.o : chatClient.c ../include/chatClient.h
	gcc -o chatClient.o -c chatClient.c

clean :
	rm *.o *.a

libfuncs.a : chatServer.o chatClient.o
	ar rv libfuncs.a chatServer.o chatClient.o

chatServer.o : chatServer.c ../include/chatServer.h
	gcc -c chatServer.c

chatClient.o : chatClient.c ../include/chatClient.h
	gcc -c chatClient.c

clean :
	rm *.o *.a


lib: ChatServerLib.o
	ar rc lib.a ChatServerLib.o 

ChatServerLib.o: ChatServerLib.c
	gcc -c ChatServerLib.c

#gcc -c ChatServerLib.h




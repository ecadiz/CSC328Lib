cc = gcc

test: libcs
	$(cc) -o test testStr.c -L. -lcs
	

libcs: ChatServerLib.o
	ar rc libcs.a ChatServerLib.o 

ChatServerLib.o: ChatServerLib.c ChatServerLib.h
	$(cc) -c ChatServerLib.c

clean:
	\rm -f *.o libcs.a test



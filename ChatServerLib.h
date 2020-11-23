/*
/*	Author:		Edwin Cadiz
/*	Major:		Computer Science
/*	Due Date:	November 
/*	Course:		CSC328
/*	Professor:	Dr. Frye
/*	Assignment:	Chat Server Application Library
/*	Filename:	ChatServerLib.h
/*	Purpose:	Library for a client and server
/*	
*/
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>



#define MAXNAME 32
#define MAXMESSAGE 1024
//protocol int+ MAXNAME + : + MAXMESSAGE + 1(null)  
//maxsize = 1 + 32 + 1 + 1024 + 1
#define MAXSIZE (1 + MAXNAME + 1 + MAXMESSAGE + 1)

struct messageInfo{
	int protocol;
	char name[MAXNAME];	//string of only name
	char msg[MAXMESSAGE]; //string of only message
	int msgSize; //size of message -- does not include null kinda like strlen()
	int nameSize; //size of name -- does not inculde null
};

enum Protocol{
	HELLO,
	BYE,
	NICK,	
	READY,
	RETRY,
	CHAT	//full message
};

typedef enum Protocol Proto;

//uses sendto instead of write
int sendMessage(int sockfd, Proto pro, char*name, char* message, int nameSize, int messageSize);
//uses recv instead of read
int receiveMessage(int sockfd, void* buf, int size);

int getInfo(struct messageInfo* msgStruct, char* buffer);

int getProtocol(char* buffer);
int getName();
int getMessage();


//old uses read and write
int readMessage(int sockfd, char *buffer, int size);
int writeMessage(int sockfd, char *buffer, int size);


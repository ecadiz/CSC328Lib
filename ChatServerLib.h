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

//message maxSize = 1023
//name maxSize = 32
struct messageInfo{
	int protocol;
	char name[32];		//string of only name
	char msg[1024]; //string of only message
	int size;	//total size
	int msgSize; //size of message
	int nameSize; //size of name
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

//old uses read and write
static int readMessage(int sockfd, char *buffer, int size);
static int writeMessage(int sockfd, char *buffer, int size);


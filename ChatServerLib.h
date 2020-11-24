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
/*
*	Function name:	sendMessage
*	Description:	send a message with a protocol, message, and name.
*					Message and name will be ignored if protocol doesn't allow it. 
*					
*	Parameters:		int sockfd: file descriptor
*					Proto pro: enum protocol 
*					char* name: name 
*					char* message: message
*					int nameSize: max size of name being sent
*					int messageSize: max size of message being sent
*	Return:			int - 0 on success, -1 on fail
*/
int sendMessage(int sockfd, Proto pro, char*name, char* message, int nameSize, int messageSize);


/*
*	Function name:	receiveMessage
*	Description:	uses recv instead of read
*	Parameters:		int sockfd:
*	Return:			int - 0 on success
*/
int receiveMessage(int sockfd, void* buf, int size);

/*
*	Function name:	getInfo
*	Description:	parses a message from receiveMessage into messageInfo struct
*					
*	Parameters:		struct messageInfo* msgStruct: return info from buffer
*					char* buffer: string with info from receiveMessage 
*	Return:			int - 0 on success
*						 -1 on failure
*/
int getInfo(struct messageInfo* msgStruct, char* buffer);

//old uses read and write
int readMessage(int sockfd, char *buffer, int size);
int writeMessage(int sockfd, char *buffer, int size);


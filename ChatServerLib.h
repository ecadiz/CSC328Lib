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

//message maxSize = 1023
//name maxSize = 32
struct messageInfo{
		char name[32];		//string of only name
		char msg[1024]; //string of only message
		int size;	//total size
		int msgSize; //size of message
		int nameSize; //size of name
};

static int receiveMessage(int sockfd, char *buffer, int size);

static int sendMessage(int sockfd, char *buffer, int size);

int getInfo(struct messageInfo* msgStruct, char* buffer);

int *checkNickName(const char *name);
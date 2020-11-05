/*
/*	Author:		Edwin Cadiz
/*	Major:		Computer Science
/*	Due Date:	November 
/*	Course:		CSC328
/*	Professor:	Dr. Frye
/*	Assignment:	Chat Server Application Library
/*	Filename:	ChatServerLib.c
/*	Purpose:	Library for a client and server
/*  Compile:    make
*/

#include "ChatServerLib.h"

/*
*	Function name:	receiveMessage
*	Description:	read from file descriptor complete message
*	Parameters:		int sockfd, char* buffer, int size
*	Return:			int - bytes read, 0 if complete
*                        -1 on fail
*/
static int receiveMessage(int sockfd, const char *buffer, int size){

    int bytesLeft = size, bytesRead;
    while(bytesLeft > 0){
        //how many bytes are read
        bytesRead = read(sockfd, buffer, size);
        if(bytesRead < 0){
            //error reading
            perror("error reading");
            return -1;
        }else if(bytesRead == 0){
            //No more bytes left to read
            return 0;
        }
        bytesLeft -= bytesRead;
        buffer += bytesRead;
    }
    return size - bytesLeft;

}

/*
*	Function name:	sendMessage
*	Description:	write to file descriptor a complete message
*	Parameters:		int sockfd, char *buffer, int size
*	Return:			int - bytes read, 0 if complete
*                        -1 on fail
*/
static int sendMessage(int sockfd, const char *buffer, int size){
    int bytesLeft = size, bytesWritten;
    while(bytesLeft > 0){
        bytesWritten = write(sockfd, buffer, size);
        if(bytesWritten < 0){
            perrror("error writing");
            return -1;
        }else if(bytesWritten == 0){
            return 0;
        }
        bytesLeft -= bytesWritten;
        buffer += bytesLeft;
    }
    return size - bytesLeft;
}


//chat protocol parsing
//check syntax - form
//check semantics - meaning
//message has a nickname before message
//ex. name: hello message
char *createMessage(const char *name, const char *msg, int nameSize, int msgSize){

   // char str = malloc()
    //return name + ": "+msg;
}


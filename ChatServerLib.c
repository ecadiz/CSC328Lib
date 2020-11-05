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
static int receiveMessage(int sockfd, char *buffer, int size){

    int bytesLeft = size, bytesRead;
    while(bytesLeft > 0){
        //how many bytes are read
        bytesRead = read(sockfd, buffer, size);
        if(bytesRead < 0){
            //error reading
            //perror("error reading");
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
static int sendMessage(int sockfd, char *buffer, int size){
    int bytesLeft = size, bytesWritten;
    while(bytesLeft > 0){
        bytesWritten = write(sockfd, buffer, size);
        if(bytesWritten < 0){
            //perrror("error writing");
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

//name: msg(eof)
//-1 on error
//1 is too long message
//0 on success
int getInfo(struct messageInfo* msgStruct, char* buffer){
	

	int i = 0, err = 0;
	while(*buffer != ':'){
		
		msgStruct->name[i] = (*buffer);
		buffer++;
		i++;
	}
	if(i <= 1){
		//no name who sent this
		//strcpy(msgStruct->name, "unknown");
		msgStruct->name[0]= '\0';
		msgStruct->nameSize = 0;
		err = -1;
	}else{
		msgStruct->name[i]= '\0';
		msgStruct->nameSize = i;
		
	}

	i =0;
	buffer += 2;
	while(*buffer != '\0'){
		msgStruct->msg[i] = (*buffer);
		buffer++;
		i++;
	}
	msgStruct->msg[i] = '\0';;
	msgStruct->msgSize = i;
	msgStruct->size = msgStruct->msgSize + msgStruct->nameSize + 3;
	
	return err;
}

//0 if name is good
//-1 if name bad
int *checkNickName(const char *name){
	

    return 0;
}



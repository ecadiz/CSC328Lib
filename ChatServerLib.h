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


static int receiveMessage(int sockfd, char *buffer, int size);

static int sendMessage(int sockfd, char *buffer, int size);

static int checkMessage();
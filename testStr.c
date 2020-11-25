#include "ChatServerLib.h"
#include <stdio.h> 
#include <string.h>

#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
//testing the library



void printMessageInfo(struct messageInfo* info){
	printf("\nprotocol: %i\n", info->protocol);
	printf("name: %s\n", info->name);
	printf("msg: %s\n", info->msg);
	printf("msgSize: %i\n", info->msgSize);
	printf("nameSize: %i\n", info->nameSize);
}

int main(){
	
	//char str[] = "0Bob: hello here I am";
	//char *str = "sdfsd))34-=?: sfuilsd23:://231";
	//char str[] = "2as: bc ja s bc nm bsnm cbsbc";
	
	//char str[] = "9water: bc ja s bc nm bsnm cbsbc";

	//0, 1,3,4
	
	printf("test1----------------------------------\n");
	
	char str[] = "1k e";
	struct messageInfo info;
	int x = getInfo(&info, str);
	printMessageInfo(&info);
	
	printf("test2----------------------------------");
	//2 = name
	//protocol and name are sent
	char str1[] = "2Adeel  s df h j k";
	x = getInfo(&info, str1);
	printMessageInfo(&info);

	printf("test3----------------------------------");
	//5 = chat
	//protocol, name, and message are sent
	char str2[] = "3riscksasd! risd!";
	x = getInfo(&info, str2);
	printMessageInfo(&info);
	
	
	printf("test4----------------------------------");
	char str3[] = "2 hello";
	x = getInfo(&info, str3);
	printMessageInfo(&info);

	printf("test5----------------------------------");
	//char str4[] = "2Jim";
	
	//x = getInfo(&info, str4);
	//printMessageInfo(&info);
	
	//////////////////////////Other
	
	
	//sendMessage(1, NICK, NULL, NULL, MAXNAME, MAXMESSAGE);
	sendMessage(1, CHAT, NULL, "hello", 10, 10);
	sendMessage(1, CHAT, "name", "hello", 10, 10);
	//sendMessage(1, NICK, NULL, "Hello There", MAXNAME, MAXMESSAGE);

	
	/*int sockfd = open("testfile.txt", O_WRONLY | O_APPEND);
	printf("\nS:%i\n", sockfd);
	if(sockfd < 0){
		return 0;
	}

	printf("MAXSIZE: ");

	//int[1059]
	write(sockfd, "hello", 5);
	//writeMessage(sockfd, "hello", 5);

	//////////////////////////////////////////
	Proto proT;
	char name[] = "Postit";
	char message[] = "here is a message";
	 
	//HELLO BYE READY...
	x = sendMessage(sockfd, READY, NULL, NULL, 0, 0);
	//printf("\nReturned: %i\n", x);
	//	
	x = sendMessage(sockfd, CHAT, name, message, strlen(name), strlen(message));
	printf("\nReturned: %i\n", x);
	x = sendMessage(sockfd, NICK, "asdasdas da  sd  ", "", strlen(name), strlen(message));
	printf("\nReturned: %i\n", x);

	close(sockfd);
	*/
	return 0;

}

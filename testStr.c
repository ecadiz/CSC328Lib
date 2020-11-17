#include "ChatServerLib.h"
#include <stdio.h> 
#include <string.h>

void printMessageInfo(struct messageInfo* info){
	printf("\nprotocol: %i\n", info->protocol);
	printf("name: %s\n", info->name);
	printf("msg: %s\n", info->msg);
	printf("msgSize: %i\n", info->msgSize);
	printf("nameSize: %i\n", info->nameSize);
}

//#NAME
//#NAME: 
//#NAME:message


int main(){
	
	//char str[] = "0Bob: hello here I am";
	//char *str = "sdfsd))34-=?: sfuilsd23:://231";
	//char str[] = "2as: bc ja s bc nm bsnm cbsbc";
	
	//char str[] = "9water: bc ja s bc nm bsnm cbsbc";


	//0, 1,3,4
	printf("test1----------------------------------");
	char str[] = "1";
	struct messageInfo info;
	int x = getInfo(&info, str);
	printMessageInfo(&info);
	
	printf("test2----------------------------------");
	//2 = name
	//protocol and name are sent
	char str1[] = "2Adeel";
	x = getInfo(&info, str1);
	printMessageInfo(&info);

	printf("test3----------------------------------");
	//5 = chat
	//protocol, name, and message are sent
	char str2[] = "5Adeel:message";
	x = getInfo(&info, str2);
	printMessageInfo(&info);
	
	
	printf("test4----------------------------------");
	char str3[] = "5Adeel: fp";
	x = getInfo(&info, str3);
	printMessageInfo(&info);


	//////////////////////////Other
	int sockfd = 1;
	Proto proT;
	char name[] = "Postit";
	char message[] = "here is a message";
	
	//HELLO BYE READY...
	x = sendMessage(sockfd, READY, NULL, NULL, 0, 0);
	printf("Returned: %i\n", x);
	//
	
	x = sendMessage(sockfd, CHAT, name, message, strlen(name), strlen(message));
	printf("Returned: %i\n", x);

	x = sendMessage(sockfd, NICK, name, message, strlen(name), strlen(message));
	printf("Returned: %i\n", x);


	return 0;

}

#include "ChatServerLib.h"
#include <stdio.h> 
#include <string.h>

int main(){
	
	char str[] = "0Bob: hello here I am";
	//char *str = "sdfsd))34-=?: sfuilsd23:://231";
	//char str[] = "2as: bc ja s bc nm bsnm cbsbc";
	
	//char str[] = "9water: bc ja s bc nm bsnm cbsbc";

	struct messageInfo info;
	
	int x = getInfo(&info, str);
	
	printf("protocol: %i\n", info.protocol);
	printf("name: %s\n", info.name);
	printf("msg: %s\n", info.msg);
	printf("sizeof(str): %i\n", sizeof(str));
	printf("size: %i\n", info.size);
	printf("msgSize: %i\n", info.msgSize);
	printf("nameSize: %i\n", info.nameSize);


	//Other
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
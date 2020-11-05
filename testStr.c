#include "ChatServerLib.h"
#include <stdio.h> 
#include <string.h>

int main(){
	
	//char *str = "Bob: hello here I am";
	//char *str = "sdfsd))34-=?: sfuilsd23:://231";
	//char str[] = "as: bc ja s bc nm bsnm cbsbc";
	char str[] = ": bc ja s bc nm bsnm cbsbc";

	struct messageInfo info;
	
	int x = getInfo(&info, str);
	printf("name: %s\n", info.name);
	printf("msg: %s\n", info.msg);
	printf("sizeof(str): %i\n", sizeof(str));
	printf("size: %i\n", info.size);
	printf("msgSize: %i\n", info.msgSize);
	printf("nameSize: %i\n", info.nameSize);

	return 0;

}
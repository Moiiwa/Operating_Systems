#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int main(){
	char string[500];
	printf("Print your command\t");
	scanf("%s",string);
	system(string);
}
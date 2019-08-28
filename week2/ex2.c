#include <stdio.h>
#include <string.h>
int main(){
	printf("Please write anything\n");
	char string[500];
	scanf("%s",string);
	int i;
	for(i=strlen(string)-1;i>=0;i--)
		printf("%c",string[i]);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){
	char string[500];
	printf("Print your command\t");
	fgets(string,500,stdin);
	char filename[]="/bin/bash";
	char *env[]={};
	char *args[]={filename, "-c", string};
	execve(filename, args, env);
	return 0;
}
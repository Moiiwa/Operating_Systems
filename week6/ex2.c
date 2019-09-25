#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 

int main(){
	char *string1="Some text to transfer through pipe";
	char string2[strlen(string1)];
	int fd[2];
	pipe(fd);
	pid_t pid;
	pid=fork();
	if(pid==0){
		read(fd[0],string2,strlen(string1));
		printf("%s\n",string2);
	}
	else{
		write(fd[1],string1,strlen(string1));
	}
	return 0;
}
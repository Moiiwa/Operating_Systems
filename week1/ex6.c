#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <stdlib.h>
#include <sys/wait.h>

int main(){
	char *string1=malloc(5);
	char *string2=malloc(5);
	int fd[2];
	pipe(fd);
	pid_t pid;
	int max=0;
	pid=fork();
	if(pid==0)
		max=getpid();
	fork();
	if(pid==0){
		//read(fd[0],string2,strlen(string1));
		if(getpid()>max){
			string1[0]='0'+((int)getpid()/1000)%10;
			string1[1]='0'+((int)getpid()/100)%10;
			string1[2]='0'+((int)getpid()/10)%10;
			string1[3]='0'+((int)getpid())%10;
			string1[4]='\0';
			write(fd[1],string1,5);
		}
		else{
			sleep(1);
			read(fd[0],string1,5);
			sleep(3);
			kill(atoi(string1),SIGTERM);
			printf("Second child was killed\n");
		}
	}
	else{
		read(fd[0],string2,5);
		write(fd[1],string2,5);
		waitpid(atoi(string2),0,0);
	}
	return 0;
}
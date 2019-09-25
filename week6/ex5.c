#include <stdio.h>
#include <unistd.h>
#include <sys/types.h> 
#include <stdlib.h>
#include <signal.h>

void sig_handler(){
	printf("\nSIGTERM caught\n");
	exit(0);
}

int main(){
	pid_t pid;
	pid=fork();
	pid_t pid1;
	if(pid==0){
		pid1=getpid();
		signal(SIGTERM,sig_handler);
		while(1){
			printf("I am alive\n");
			sleep(1);
		}
	}
	else{
		sleep(10);
		kill(pid1,SIGTERM);
	}
	return 0;
}

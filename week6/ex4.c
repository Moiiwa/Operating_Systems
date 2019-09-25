#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigint_handler(){
	printf("\nInterrupt signal was caught\n");
	exit(0);
}

void sigstop_handler(){
	printf("\nStop signal was caught\n");
	exit(0);
}

void sigusr_handler(){
	printf("\nUser signal was caught\n");
	exit(0);
}

int main(){
	signal(SIGINT,sigint_handler);
	signal(SIGSTOP,sigstop_handler);
	signal(SIGUSR1,sigusr_handler);
	pid_t pid=getpid();
	printf("My pid is: %d\n",pid);
	while(1){
	}
	return 0;
}
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void sig_handler(){
	printf("\nCtr+c was pressed\n");
	exit(0);
}

int main(){
	signal(SIGINT,sig_handler);
	while(1){
	}
	return 0;
}
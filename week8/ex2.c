#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(){
	int i;
	void* ptr;
	for(i=0;i<10;i++){
		ptr=malloc(10*1024*1024);
		memset(ptr,0,10*1024*1024);
		sleep(1);
	}
}
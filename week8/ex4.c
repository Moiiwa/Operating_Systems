#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
	int i;
	struct rusage usage;
	void* ptr;
	for(i=0;i<10;i++){
		ptr=malloc(10*1024*1024);
		memset(ptr,0,10*1024*1024);
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld\n",usage.ru_maxrss);
		sleep(1);
	}
}
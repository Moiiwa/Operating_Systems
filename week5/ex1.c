#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* print_thread(void *num){
	long number=(long)num;
	printf("New thread: It's a thread with number %ld\n", number+1);
	printf("New thread: Thread %ld is closed\n\n", number+1);
	pthread_exit(NULL);
}

int main(){
	printf("Write number of threads: ");
	char num[20];
	scanf("%s", num);
	printf("\n");
	int n=atoi(num);
	long i;
	int status;
	for (i=0;i<n;i++){
		pthread_t thread;
		status = pthread_create(&thread, NULL, print_thread, (void *)i);
		printf("Main thread: Thread %ld is created\n",i+1);
		status = pthread_join(thread,NULL);
	}
	return 0;
}
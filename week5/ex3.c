#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>
struct stack{
	int size;
	int filled;
	int a[];
};
int producer_asleep=0;

int consumer_asleep=0;

void put_consumer_asleep(){
	consumer_asleep=1;
}

void wake_up_consumer(){
	//we've got a city to burn
	consumer_asleep=0;
}

void put_producer_asleep(){
	producer_asleep=1;
}

void wake_up_producer(){
	//we've got a city to burn
	producer_asleep=0;
}

void* producer_actions(void * stack){
	long long i=0;
	struct stack* buffer=(struct stack*) stack;
	while (1){
		
		if(buffer->filled==buffer->size)
			put_producer_asleep();
		if (i%7==0&&producer_asleep==0){
			buffer->a[buffer->filled]=1;
			++buffer->filled;
			if (i%20==0)
				printf("%d\n",buffer->filled);
			if (buffer->filled>0)
				wake_up_consumer();
		}
		
		++i;
		if(producer_asleep==1&&consumer_asleep==1)
			break;
	}
	pthread_exit(NULL);
}

void* consumer_actions(void * stack){
	long long i=0;
	struct stack* buffer=(struct stack*) stack;
	while (1){
		if(buffer->filled==0)
			put_consumer_asleep();
		if (i%8==0&&consumer_asleep==0){
			buffer->a[buffer->filled]=0;
			--buffer->filled;
			if (buffer->filled<buffer->size)
				wake_up_producer();
		}
		++i;
		if(producer_asleep==1&&consumer_asleep==1)
			break;
	}
	pthread_exit(NULL);
}

int main(){
	printf("write size of stack\t");
	char str[15];
	scanf("%s",str);
	int size=atoi(str);
	struct stack *buffer;
	int i;
	clock_t start,stop;
	start=clock();
	buffer = malloc(sizeof(int)*(2+size));
	buffer->size=size;
	buffer->filled=0;
	for (i=0;i<size;i++){
		buffer->a[i]=0;
	}
	pthread_t consumer;
	pthread_t producer;
	int status_c=pthread_create(&consumer,NULL,consumer_actions,(void*)buffer);
	int status_p=pthread_create(&producer,NULL,producer_actions,(void*)buffer);
	status_c=pthread_join(consumer,NULL);
	status_p=pthread_join(producer,NULL);
	stop=clock();
	printf("Program worked for %ld clocks till fatal race condition occured\n",((stop-start)));
	return 0;
}
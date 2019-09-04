#include <stdio.h>
#include <stdlib.h>
struct node{
	int value;
	struct node* next;
	struct node* prev;
};

struct list{
	int len;
	struct node *head;
	struct node *tail;
};

struct list sll;

void print_list(){
	int i;
	struct node *current;
	
	if (sll.len>0){
		current=sll.head;
		for(i=0;i<sll.len;i++){
			printf("%d ", current->value);
			current=current->next;
		}
		printf("\n");
	}
}

void insert_node(int val){
	struct node* nod;
	nod=malloc(sizeof(struct node));
	nod->value=val;
	nod->next=NULL;
	nod->prev=NULL;
	if(sll.len!=0){
		sll.tail->next=nod;
		nod->prev=sll.tail;
		sll.tail=nod;
	}
	else{
		sll.head=nod;
		sll.tail=nod;
	}
	//printf("%d ",sll.head->value);
	++sll.len;
}

void delete_node(int val){
	struct node *current=sll.head;
	struct node *buf=malloc(sizeof(struct node));
	if (current->value==val){
		sll.head=current->next;
		free(current);
		sll.head->prev=NULL;
		--sll.len;
	}
	else
	while (current->next!=NULL){
		if(current->next->value==val){
			buf=current->next;
			current->next=buf->next;
			buf->next->prev=current;
			free(buf);
			--sll.len;
			break;
		}
		current=current->next;
	}
}

int main(){
	sll.len=0;
	sll.head=NULL;
	sll.tail=NULL;
	sll.head=malloc(sizeof(struct node));
	sll.tail=malloc(sizeof(struct node));
	insert_node(5);
	insert_node(2);
	insert_node(5);
	insert_node(11);
	insert_node(4);
	print_list();
	delete_node(5);
	delete_node(11);
	print_list();
	return 0;
}
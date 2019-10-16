#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct pageframe{
	int val;
	int age[8];
};


char string[50000];
char number[5];
int page_fault_counter;

struct pageframe **pf_array;
int frames_num;


void create_page_frames(int n){
	int i,j;
	pf_array=malloc(sizeof(struct pageframe)*n);
	for(i=0;i<n;i++){
		struct pageframe *frame=malloc(sizeof(struct pageframe));
		frame->val=-1;
		for(j=0;j<8;j++)
			frame->age[j]=0;
		pf_array[i]=frame;
	}
}

int space_exist(){
	int i;
	for(i=0;i<frames_num;i++){
		if(pf_array[i]->val==-1)
			return i;
	}
	return -1;
}

int age_in_decimal(int ar[8]){
	int val;
	val=0;
	int i;
	for(i=0;i<8;i++){
		val+=(int)(pow(2,7-i))*ar[i];
	}
	return val;
}

int present(int num){
	int i;
	for(i=0;i<frames_num;i++){
	if(num==pf_array[i]->val)
		return i;
	}
	return -1;
}

void clean_age(int a[8]){
	int i;
	for(i=0;i<8;i++)
		a[i]=0;
}

void next_step(){
	int i,j;
	for(i=0;i<frames_num;i++){
		for(j=6;j>=0;j--){
		pf_array[i]->age[j+1]=pf_array[i]->age[j];
		}
		pf_array[i]->age[0]=0;
	}
	
}

int main(){
	FILE *f;
	int iterator=0;
	int numb;
	int buffer;
	int i,j;
	int go=0;
	int min_age,ma_owner;
	printf("Write number of page frames you need: ");
	scanf("%s",number);
	frames_num=atoi(number);
	number[0]='\0';
	create_page_frames(frames_num);
	f=fopen("input.txt","r");
	fgets(string,50000,f);
	page_fault_counter=0;
	for(i=0;i<strlen(string);i++){
		if(string[i]!=' '&&string[i]!='\0'){
			number[iterator]=string[i];
			++iterator;
		}
		else{
			++go;
			number[iterator]='\0';
			numb = atoi(number);
			iterator=0;
			buffer=space_exist();
			if(buffer!=-1){
				pf_array[buffer]->val=numb;
				pf_array[buffer]->age[0]=1;
				//printf("%d\n",numb);
				numb=0;
				++page_fault_counter;
			}
			else{
				if(present(numb)!=-1){
					next_step();
					//printf("%d\n",numb);
					pf_array[present(numb)]->age[0]=1;
					continue;
					
				}
				min_age=age_in_decimal(pf_array[0]->age);
				ma_owner=0;
				for(j=0;j<frames_num;j++){
					if (age_in_decimal(pf_array[j]->age)<min_age){
						min_age=age_in_decimal(pf_array[j]->age);
						ma_owner=j;
					}
				}
				//printf("%d\n",numb);
				pf_array[ma_owner]->val=numb;
				++page_fault_counter;
				clean_age(pf_array[ma_owner]->age);
				next_step();
				pf_array[ma_owner]->age[0]=1;
				numb=0;
			}
		}
		
	}
	float fl=(float)(go-page_fault_counter)/(float)page_fault_counter;
	printf("Hit/Miss ratio is %.2f",fl);
	return 0;
	
}
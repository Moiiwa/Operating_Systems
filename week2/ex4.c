#include <stdio.h>
void swap(int *a,int *b){
	int x=*b;
	*b=*a;
	*a=x;
}
int main(){
	printf("Write two integers\n");
	char string[25];
	int num1,num2;
	scanf("%s",string);
	num1=atoi(string);
	scanf("%s",string);
	num2=atoi(string);
	swap(&num1,&num2);
	printf("%d %d",num1, num2);
	return 0;
}
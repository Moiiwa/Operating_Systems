#include <stdio.h>
int n,i,j;
void triangle(){
	for(i=1;i<=n;i++){
		for(j=0;j<n-i;j++)
			printf(" ");
		for(j=0;j<(2*i-1);j++)
			printf("*");
		printf("\n");
	}
}
void right_triangle(){
	for(i=1;i<=n;i++){
		for(j=0;j<(2*i-1);j++)
			printf("*");
		printf("\n");
	}
}
void strange_triangle(){
	for(i=1;i<=n;i++){
	if (n%2==0)
		if(i<=n/2){
			for(j=0;j<i;j++)
				printf("*");
			printf("\n");
		}
		else{
			for(j=0;j<n-i+1;j++)
				printf("*");
			printf("\n");
		}
	else
		if(i<=n/2+1){
			for(j=0;j<i;j++)
				printf("*");
			printf("\n");
		}
		else{
			for(j=0;j<n-i+1;j++)
				printf("*");
			printf("\n");
		}
	}
}
void rectangle(){
	for(i=1;i<n;i++){
		for(j=0;j<n;j++)
			printf("*");
		printf("\n");
	}
}
int main(int argc,char *argv[]){
	n=atoi(argv[1]);
	printf("Choose figure:\n t - triangle\n rt - right triangle\n");
	printf("rec - rectrangle\n st - strange triangle\n");
	char string[3];
	scanf("%s",string);
	if(strcmp(string,"t")==0)
		triangle();
	else
		if(strcmp(string,"rt")==0)
			right_triangle();
		else
			if(strcmp(string,"rec")==0)
				rectangle();
			else
				if(strcmp(string,"st")==0)
					strange_triangle();
				else
					printf("There is no such figure");
	return 0;
}
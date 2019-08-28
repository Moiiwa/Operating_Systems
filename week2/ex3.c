#include <stdio.h>
int main(int argc,char *argv[]){
	int i,j;
	int n=atoi(argv[1]);
	
	for(i=1;i<=n;i++){
		for(j=0;j<n-i;j++)
			printf(" ");
		for(j=0;j<(2*i-1);j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
int n;

void bubble_sort(int *a){
	int i,j,buffer;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				buffer=a[j];
				a[j]=a[j+1];
				a[j+1]=buffer;
			}
		}
}

int main(){
	char str[500];
	int *a=malloc(n*sizeof(int));
	int i,buf;
	printf("Write size of an array\n");
	scanf("%s",str);
	n=atoi(str);
	printf("Write elements of an array\n");
	for(i=0;i<n;i++){
		scanf("%s",str);
		buf=atoi(str);
		a[i]=buf;
	}
	bubble_sort(a);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	free(a);
	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,i;
	int *a;
	n=7;
	a=malloc(7*sizeof(int));
	for(i=0;i<n;i++)
		a[i]=i;
	for (int i = 0; i < n; ++i)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	free(a);
}
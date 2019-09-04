#include <stdio.h>
#include <stdlib.h>
int n;

void quick_sort(int *a,int lb, int rb){
	int pivot=(rb+lb)/2;
	int lo_b,hi_b,buf;
	lo_b=lb;
	hi_b=rb;
		while(lo_b<=hi_b){
			while(a[lo_b]<a[pivot])
				++lo_b;
			while(a[hi_b]>a[pivot])
				--hi_b;
			if(a[lo_b]>a[hi_b]){
				buf=a[lo_b];
				a[lo_b]=a[hi_b];
				a[hi_b]=buf;
			}
			++lo_b;
			--hi_b;
			if (lb<hi_b)
				quick_sort(a,lb,hi_b);
			if(lo_b<rb)
				quick_sort(a,lo_b,rb);
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
	quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
	free(a);
	return 0;
}
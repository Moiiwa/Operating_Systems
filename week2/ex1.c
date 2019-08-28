#include <limits.h>
#include <float.h>
#include <stdio.h>
int main(){
	int intvar;
	float floatvar;
	double doublevar;
	intvar = INT_MAX;
	floatvar = FLT_MAX;
	doublevar = DBL_MAX;
	printf("Size of int = %d, value is %d\n",sizeof(intvar),intvar);
	printf("Size of float = %d, value is %f\n",sizeof(floatvar),floatvar);
	printf("Size of double = %d, value is %f\n",sizeof(doublevar),doublevar);
	return 0;
}
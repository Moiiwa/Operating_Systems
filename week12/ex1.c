#include <stdio.h>

int main(){
	FILE *f,*f1;
	f=fopen("/dev/urandom","r");
	char str[20];
	fgets(str,20,f);
	f1=fopen("ex1.txt","w");
	fprintf(f1, "%s\n",str);
	fclose(f);
	fclose(f1);
	return 0;
}
#include <stdio.h>
#include <unistd.h>

int main(){
	char buf[6];
	setvbuf(stdout,buf,_IOLBF,6);
	int i;
	printf("%c",'h');
	sleep(1);
	printf("%c",'e');
	sleep(1);
	printf("%c",'l');
	sleep(1);
	printf("%c",'l');
	sleep(1);
	printf("%c",'o');
	sleep(5);
	buf;
	printf("%s\n",buf);
	return 0;
}
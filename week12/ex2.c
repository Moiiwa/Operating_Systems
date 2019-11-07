#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char**argv){
	int fd=fileno(stdin);
	int output;
	if(argc==1)
		return 0;
	if(argc==2){
		output = open(argv[1],O_RDWR|O_CREAT|O_TRUNC,S_IWRITE | S_IREAD);
	}
	if(argc==3 && strcmp(argv[1],"-a")==0)
		output = open(argv[2], O_RDWR | O_APPEND | O_CREAT,S_IWRITE | S_IREAD);
	char byte;
	int status = read(fd, &byte, 1);
	while(status !=0){
		write(output,&byte,1);
		status = read (fd, &byte, 1);
	}
	return 0;
}
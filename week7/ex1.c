#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
  char *string1="Some text to transfer through pipe";
  char string2[strlen(string1)];
  int fd[2];
  pipe(fd);
  write(fd[1],string1,strlen(string1));
  read(fd[0],string2,strlen(string1));
  printf("%s\n",string2);
  return 0;
}
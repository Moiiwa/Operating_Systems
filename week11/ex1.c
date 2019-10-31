#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <memory.h>


int main(){
  char *str = "This is a nice day";
  size_t size = strlen(str)+1;
  FILE *fp = fopen("ex1.txt", "w");
    ftruncate(fileno(fp), size - 1);
    fclose(fp);
  int fd = open("ex1.txt", O_RDWR);
  char *new_addr;
  new_addr=mmap(NULL,size, PROT_READ | PROT_WRITE,MAP_SHARED,fd,0);
  
  for(int i=0;i<size;i++){
    new_addr[i]=str[i];
  }
  return 0;
}

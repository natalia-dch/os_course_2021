#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
  int     fd;
  size_t size;
  char message[30];
  char name[]="c.fifo";

  (void)umask(0);
  
  mknod(name,S_IFIFO|0666,0);
  fd = open(name,O_RDONLY);
  size = read(fd,message,30);
  printf("%s\n",message);
  close(fd);
  return 0;
}

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
  char message[] ="It's a message from task2_1.c";
  char name[]="c.fifo";
  (void)umask(0);
  
  int n =  mknod(name,S_IFIFO|0666,0);
  fd = open(name,O_WRONLY);
  size = write(fd,message,30);
  n = close(fd);
  return 0;
}

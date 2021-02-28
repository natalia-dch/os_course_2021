#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <limits.h>
int main()
{
  printf("Pipe buffer size:%d",PIPE_BUF);
  return 0;
}

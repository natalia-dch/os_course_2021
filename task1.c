#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
  int     fd;
  size_t  size;
  char    string[14];
  (void)umask(0);
 
  if ((fd = open("myfile", O_RDONLY, 0666)) < 0) {
    printf("Can\'t open file\n");
    exit(-1);
  }
  //
  // Try to write 14 bytes from our array to the file,
  // i.e. the entire string "Hello, world!" along with the end-of-line sign.
  //
  read(fd, string, 14);

  if (close(fd) < 0) {
    printf("Can\'t close file\n");
  }
  printf(string);
  return 0;
}

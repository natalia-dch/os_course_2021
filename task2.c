#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  int     fd[2],fd2[2], result;

  size_t size;
  char  res1[15];
  char res2[15];
  char parStr[] ="Parent message";
  char childStr[] = "Child message ";
  pipe(fd);
  pipe(fd2);

  result = fork();

  if (result < 0) {
    printf("Can\'t fork child\n");
    exit(-1);
  } else if (result > 0) {

   /* Parent process */

    close(fd[0]);
    close(fd2[1]);
    write(fd[1], "Parent Message", 15);
    read(fd2[0], res1, 14);
    close(fd[1]);
    close(fd2[0]);

    printf("Parent exit, got message:%s\n",res1);

  } else {

    /* Child process */

    close(fd[1]);
    close(fd2[0]);

    read(fd[0], res2, 15);
    write(fd2[1],"Child Message",14);

    printf("Child exit, got message:%s\n", res2);

    close(fd[0]);
    close(fd2[1]);
  }

  return 0;
}

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>


int main(void)
{
  char buffer1 [50];
  char buffer2 [50];
  char *name ="a0.txt";
  int n = 0;
  int c1;
  int fd;
  if((fd = open(name,O_CREAT | O_WRONLY,0666)) == -1){
	  printf("cannot create file");}
	  
  while(n<100){
	c1 = sprintf(buffer1,"a%d.txt",n);
	close(fd);
	n++; 
	c1 = sprintf(buffer2,"a%d.txt",n);
    fd = symlink(buffer1,buffer2);
    if((fd = open(buffer2,O_WRONLY,0666)) == -1){
		n--;
		printf("Не могу открыть %s. Глубина рекурсии: %d",buffer2,n);
		close(fd);
		return 0;
		}
	  }


  return 0;
}

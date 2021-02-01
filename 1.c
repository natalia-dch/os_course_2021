#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int args,char **argv){
printf("PPID=%d\nPID=%d\n",getppid(),getpid());
return 0;

}


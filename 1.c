#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(int args,char **argv){
printf("UID=%d\nGID=%d\n",getuid(),getgid());
return 0;

}


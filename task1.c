#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
for(int i=0;i<argc;i++){
printf("%s\n",argv[i]);
}
int i=0;
while(envp[i]!=0){
printf("%s\n",envp[i]);
i++;
}
return 0;
}

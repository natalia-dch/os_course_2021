#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]){
pid_t  pid = fork();
if (pid == -1)
	printf("Error happened");
else if (pid == 0) 
        execle("/bin/ls","'bin/ls",0, envp);
else
	printf("It's a parent. PID = %d",getpid());
return 0;
}

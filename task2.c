#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
pid_t  pid = fork();
if (pid == -1)
	printf("Error happened");
else if (pid == 0) 
        printf("It's a kid. PID = %d",getpid());
else
	printf("It's a parent. PID = %d",getpid());
return 0;
}

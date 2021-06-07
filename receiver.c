#include <signal.h>
#include <stdio.h>
pid_t pid;
char num = 0;
char bit = 1;
int counter = 0;

void my_handler(int nsig) {
  if(nsig==SIGUSR1){ //0
//do nothing
		}
  if(nsig==SIGUSR2){ //1
  		num = num | bit<<counter;
  		}
  counter++;
  if(counter==8){
    printf("Number is:%d\n",num);
    exit(0);
    }
  //send that you got the signal
  kill(pid,SIGUSR2);
       
}

int main(void) {
  printf("Receiver pid:%d\n",getpid());
  printf("Write sender pid:");
  scanf("%d",&pid);

  (void)signal(SIGUSR1, my_handler);
  (void)signal(SIGUSR2, my_handler);


  while(1);
  return 0;
}

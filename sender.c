#include <signal.h>
#include <stdio.h>
pid_t pid;
char num;
int counter = 0;

void my_handler(int nsig) {
  if(nsig==SIGUSR2){
	  counter++;
	  int bit = (num >> counter) & 1;
	  if(bit==0){
	        kill(pid,SIGUSR1);}
	  else{
	        kill(pid,SIGUSR2);}
	 if(counter==7){
	      exit(0);}
	  }
	  
        
}

int main(void) {
  printf("Sender pid:%d\n",getpid());
  printf("Write receiver pid:");
  scanf("%d",&pid);
  printf("Write a number from -127 to 127:");
  scanf("%d",&num);  
  //send 1st number
  	  (void)signal(SIGUSR2, my_handler);
  	  int bit = (num >> counter) & 1;
	  if(bit==0){
	        kill(pid,SIGUSR1);}
	  else{
	        kill(pid,SIGUSR2);}


  while(1);
  return 0;
}

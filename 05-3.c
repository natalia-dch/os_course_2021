#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/sem.h>



//СХЕМА

//parent             
//while(N>0){
//write
//A(s,1) //разблок
//D(s,2) //waiting for child to write
//read
//N--;
//}

//child            
//while(N>0){
//D(s,1) //waiting for parent to write
//read
//write
//A(s,2) //разблок
//N--;
//}

int main()
{
  int     fd[2], result;
  size_t size;
  char  resstring[5];
  int N;
  scanf("%d",&N);

  if (pipe(fd) < 0) {
    printf("Can\'t open pipe\n");
    exit(-1);
  }

  result = fork();

  if (result < 0) {
    printf("Can\'t fork child\n");
    exit(-1);
  } else if (result > 0) {

   /* Parent process */
   //create semaphore
  int    semid;        
  char   pathname[]="05-3.c";                               
  key_t  key2;          
  struct sembuf mybuf; 
  key2 = ftok(pathname,0);
  semid = semget(key2, 1, 0666 | IPC_CREAT);
  
  

  while(N>0){
     //parent writes
    size = write(fd[1], "ping", 5);
    //разблок
    mybuf.sem_num = 0;
    mybuf.sem_op  = 1;
    mybuf.sem_flg = 0;
    semop(semid, &mybuf, 1);
    
    //блок
    mybuf.sem_num = 0;
    mybuf.sem_op  = -2;
    mybuf.sem_flg = 0;
    semop(semid, &mybuf, 1);

    //parent reads
    size = read(fd[0], resstring, 5);

    printf("parent got a message:%s\n", resstring);	  
	   
    N--;	  
	  }

    //close pipes
    close(fd[0]);
    close(fd[1]);

  } else {

    /* Child process */
  //create semaphore
  int    semid;        
  char   pathname[]="05-3.c";                               
  key_t  key2;          
  struct sembuf mybuf; 
  key2 = ftok(pathname,0);
  semid = semget(key2, 1, 0666 | IPC_CREAT);
    
while(N>0){
	//блок
    mybuf.sem_num = 0;
    mybuf.sem_op  = -1;
    mybuf.sem_flg = 0;
    semop(semid, &mybuf, 1);
    //child reads
    size = read(fd[0], resstring, 5);
    printf("child got a message:%s\n", resstring);
    
    //child writes
    size = write(fd[1], "pong", 5);

    
    //разблок
    mybuf.sem_num = 0;
    mybuf.sem_op  = 2;
    mybuf.sem_flg = 0;
    semop(semid, &mybuf, 1);
    
    N--;
}
    
    //close pipe
    close(fd[1]);
    close(fd[0]);
  }

  return 0;
}

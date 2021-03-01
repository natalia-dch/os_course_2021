#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
  char     *message;    // Pointer to shared memory
  int     shmid;     // IPC descriptor for the shared memory
  int     new = 1;   // Initialization flag for the elements of the array
  char    pathname[] = "task1_1.c"; // The file name used to generate the key.
                                 // A file with this name must exist in the current directory.
  key_t   key;       // IPC key
  key = ftok(pathname,0);
  shmid = shmget(key, 3*sizeof(char), 0666|IPC_CREAT|IPC_EXCL);
  shmid = shmget(key, 3*sizeof(char), 0);
  new = 0;
  message = (char  *)shmat(shmid, NULL, 0); 
  message[0]='H';
  message[1]='E';
  message[2]='Y'; 
  return 0;
}

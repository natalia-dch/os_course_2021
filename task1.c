#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int a = 0;  // The variable a is global static for the entire program,
            // so it will be shared by both threads of execution.

/**
  Below follows the text of the function
  that will be associated with the 2nd thread.

  Parameter dummy is used only for type compatibility.
  For the same reason, the function returns void *.
**/
void *mythread(void *dummy)
{
  pthread_t mythid;
  //
  // Note that mythid variable is a dynamic local variable of mythread () function,
  // that is, it is pushed on the stack and, therefore, is not shared by the threads.
  //
  mythid = pthread_self();

  a = a+1;
  printf("Thread %u, Calculation result = %d\n", mythid, a);
  return NULL;
}

int main()
{
  pthread_t th1,th2, mythid;
  int       result1,result2;
  
  result1  = pthread_create (&th1, (pthread_attr_t *)NULL, mythread, NULL);
  printf("first thread created,id = %u\n",th1);
  result2 = pthread_create (&th2, (pthread_attr_t *)NULL, mythread, NULL);
  printf("second thread created, id = %u\n", th2);

  mythid = pthread_self();

  a = a+1;

  printf("Main thread %u, Calculation result = %d\n", mythid, a);
  
  pthread_join(th1, (void **)NULL);
  pthread_join(th2, (void **)NULL);
  return 0;
}

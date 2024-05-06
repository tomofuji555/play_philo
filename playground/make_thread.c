#include <pthread.h>
#include <stdio.h>
#include <sys/_pthread/_pthread_t.h>
#include <stdlib.h>

#define NUM 10

void  *func (void *arg)
{
  int *num = (int *)arg;

  int i = 0;
  while (i <= NUM)
  {
    *num = *num + i;
    i++;
  }
  return (NULL);
}

int main (void)
{
  pthread_t *thread;
  int *num = malloc(sizeof(int));

  *num = 0;
  pthread_create (thread, NULL, func, num);
  pthread_join(*thread, NULL);
  printf ("%d\n", *num);

  free (num);
  return (0);
}

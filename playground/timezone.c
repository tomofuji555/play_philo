#include <sys/_types/_timeval.h>
#include <sys/time.h>
#include <stdio.h>
#include <time.h>

int main (void)
{
  struct timeval  *tv;

  int time = gettimeofday(tv, NULL);
  if (time == 0)
  {
    printf ("%ld\n", tv->tv_sec);
  }
  else
    printf ("error");
  return (0);
}

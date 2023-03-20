#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int f(void);
int g(void);



int
main(int argc,
     char**argv,
     char**envp)
{ int flag_err = 0;
  int i, count;
  for (i=50,count=0; i>7;i-=3, count++)
      ;
  printf("%d\n", count);
  for (i=3,count=0; i<24; i+=4,count++)
      ;
  printf("%d\n", count);
  return flag_err;
}


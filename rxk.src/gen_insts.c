#include <stdio.h>

int main(int argc, char *argv[])
{
  int i;
  
  if (argc<1)
    return 1;
  for (i=0; i<=0xff; i++)
    {
      if ((i&0xf)==0)
	printf("\n");
      printf("virtual int instruction_%s_%02x(t_mem code) { return resNOT_DONE; }\n"
	     ,argv[1],i
	     );	     
    }
}

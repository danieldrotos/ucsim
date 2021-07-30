#include <stdio.h>

int main(int rgc, char *argv[])
{
  int i;
  if (!argv[1] || !*argv[1])
    return 1;
  for (i=0; i<=0xff; i++)
    {
      if ((i & 0xf) == 0)
	printf("\n");
      printf("int instruction_wrapper_%s_%02x(class cl_uc *uc, t_mem code) { return ((class cl_rxk *)uc)->instruction_%s_%02x(code); }\n",
	     argv[1], i, argv[1], i);
    }
  printf("\n\n"
"void fill_%s_wrappers(instruction_wrapper_fn itab[])\n"
"{\n"
"  int i;\n"
"  for (i=0; i<256; i++)\n"
"    {\n"
"      itab[i]= instruction_wrapper_%s_none;\n"
"    }\n"
	 ,argv[1],argv[1]
	 );
  for (i=0; i<=0xff; i++)
    {
      if ((i&0xf)==0)
	printf("\n");
      printf("  itab[0x%02x]= instruction_wrapper_%s_%02x;\n", i, argv[1], i);
    }
  printf("\n}\n\n");
}

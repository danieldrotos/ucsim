volatile int x;

void
main(void)
{
  int i;

  for (i= 0; i<100; i++)
    x= i+123;
  for (;;)
    ;
}

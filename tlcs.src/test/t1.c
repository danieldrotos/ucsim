volatile unsigned char x;

void t(const char *x)
{
}

void
main(void)
{
  unsigned char i;

  for (i= 0; i<10; i++)
    x= i;
  for (;;)
    ;
}

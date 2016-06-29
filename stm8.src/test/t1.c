volatile int x;

void isr_tx(void) __interrupt(20)
{
}

void
main(void)
{
  int i;

  for (i= 0; i<100; i++)
    x= i+123;
  for (;;)
    ;
}

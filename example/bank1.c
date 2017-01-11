#pragma codeseg BANK1

int
b1(int x) __banked
{
  return x+1;
}

#pragma codeseg BANK2

int
b2(int x) __banked
{
  return x+3;
}

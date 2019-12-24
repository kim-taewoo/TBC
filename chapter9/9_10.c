#include <stdio.h>

int fibonacci(int num)
{
  if (num==1||num==2)
  {
    return 1;
  }
  return fibonacci(num-1) + fibonacci(num-2);
}

int main()
{
  for (int cnt = 1; cnt < 13; ++cnt)
  {
    printf("%d ", fibonacci(cnt));
  }
  return 0;
}
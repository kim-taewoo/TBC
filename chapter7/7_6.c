#include <stdio.h>
#include <stdbool.h>

int main()
{
  unsigned num;
  bool isPrime; // flag 

  scanf("%u", &num);

  isPrime = true;

  for (unsigned div = 2; (div * div) <= num ; div++)
  {
    if (num % div == 0)
    {
      isPrime = false;
      if (num == div*div)
        printf("%u is divisible by %u\n", num, div);
      else
        printf("%u is divisible by %u and %u\n", num, div, num/div);
    }
    
  }
  

  if (isPrime)
    printf("%u is a prime number.\n", num);
  else
      printf("%u is not a prime number.", num);

  return 0;
}
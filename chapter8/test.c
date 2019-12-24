#include <stdio.h>

int main()
{
  int i = 0;
  printf("%i\n", &i);

  scanf("%d", i);
  printf("%i\n", &i);

  scanf("%d", &i);
  printf("%i\n", &i);

  return 0;
}
#include <stdio.h>
#include <string.h>

int main()
{
  char str[20] = "Hello\0 world!";
  printf("%s %zu %zu\n", str, sizeof(str), strlen(str));

  return 0;
}
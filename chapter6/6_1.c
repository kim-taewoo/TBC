// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
  int num, sum = 0;
  printf("Enter an integer (q to quit) : ");

  int status;
  status = scanf("%d", &num);
  while (status)
  {
    sum += num;
    printf("Enter next integer (q to quit) : ");
    status = scanf("%d", &num);
  }

  // while (scanf("%d", &num)) // 이렇게 코드를 짜면 status 없이 훨씬 깔끔해진다.
  // {
  //   sum += num;
  //   printf("Enter next integer (q to quit) : ");
  // }

  printf("Sum = %d\n", sum);
  return 0;
}
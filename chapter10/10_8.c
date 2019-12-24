#include <stdio.h>

double average(double* start, double* end)
{
  int count = end - start; // 포인터끼리의 뺄셈 연산
  double avg = 0.0;
  while (start < end)
  {
    avg += *start++; // 먼저 avg 에 더하고 start 증가
    // count++; 2개의 포인터를 이용함으로써 필요없어진 코드
  }
  avg /= (double)count;
  return avg;
}

int main()
{
  double arr1[5] = {10,13,12,7,8};
  printf("Arr = %f\n", average(arr1,arr1+5)); // 포인터에 상수 덧셈연산
  return 0;
}
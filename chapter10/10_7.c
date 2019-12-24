#include <stdio.h>

void printArray(double arr1[], int n) 
{
  printf("%p\n", arr1);
  for (size_t i = 0; i < n; i++)
  {
    printf("%f ", arr1[i]);
  }
  printf("\n");
}

int main()
{
  double arr[] = {1.0,2.0,3.0};
  printf("%p\n", arr);
  printArray(arr, 3);

  return 0;
}
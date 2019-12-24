#include <stdio.h>

int main()
{
  // 1차원 배열 2개를 포인터 배열 한 개로 다루는 사례
  // int arr0[3] = {1, 2, 3};
  // int arr1[3] = {4, 5, 6};
  
  // int* parr[2] = {arr0, arr1};
  // for (size_t j = 0; j < 2; j++)
  // {
  //   for (size_t i = 0; i < 3; i++)
  //   {
  //     // 아래 인자 모두 같은 내용
  //     printf("%d ( == %d, %d ) ", parr[j][i], *(parr[j] + i), (*(parr+j))[i] );
  //   }
  //   printf("\n");
  // }
  // printf("\n");

  // 2차원 배열을 포인터 배열로 다루는 사례
  int arr[2][3] = {{1,2,3}, {4,5,6}};
  int *parr[2] = {arr[0][1]};

  for (size_t j = 0; j < 2; j++)
  {
    for (size_t i = 0; i < 3; i++)
    {
      // 아래 인자 모두 같은 내용. 마지막 걸 많이 사용하게 될 것임.
      printf("%d ( == %d, %d, %d ) ", arr[j][i], parr[j][i], *(parr[j] + i), (*(parr + j) + i));
    }
    printf("\n");
  }
  printf("\n");

  return 0;
}
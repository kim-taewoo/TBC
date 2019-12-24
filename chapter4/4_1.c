#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> // SetConsoleOutputCP()

int main()
{
  const UINT default_cp = GetConsoleOutputCP();
  printf("%u\n", default_cp);
  SetConsoleOutputCP(CP_UTF8);
  char fruit_name[40];
  printf("가장 좋아하는 과일은?\n");
  scanf("%s", fruit_name);
  printf("%s를 좋아하는군요!", fruit_name);

  return 0;
}
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

const char stop ='.';

int main()
{
  char c;
  int n_chars = 0;
  int n_lines = 0;
  int n_words = 0;
  bool word_flag = false;
  bool line_flag = false;

  printf("Enter text : \n");

  while ((c=getchar()) != stop)
  {
    if (!isspace(c))
      n_chars++;
    if (!isspace(c) && !line_flag) // 공백 이외에 뭔가 새로운 입력이 시작됐을 때 n_lines++
    {
      n_lines++;
      line_flag = true;
    }
    if (!isspace(c) && !word_flag)
    {
      n_words++;
      word_flag = true;
    }
    if(isspace(c))
    {
      word_flag = false;
    }

    if(c=='\n') // 새로운 줄로 넘어왔을 경우 다시 line_flag = false
      line_flag = false;
  }

  printf("Characters = %d, words = %d, Lines = %d\n", n_chars, n_words, n_lines);

  return 0;
}
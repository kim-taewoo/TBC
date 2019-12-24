#include <stdio.h>

int main()
{
  char ch;

  // ch = getchar();
  // putchar(ch);

  // while (ch != '\n')
  // 아래와 같이 씀으로써 중복 코드를 확 줄일 수 있다.
  // 대입연산자의 우선순위가 낮아 괄호로 싸주어야 함에 유의
  while ((ch = getchar()) != '\n')
  {
    // 아스키 코드를 적극 활용하지만
    // 아스키 코드 테이블을 외울 필요 없이 사용하는 케이스
    // 대문자는 소문자로, 소문자는 대문자로
    if (ch >= 'a' &&  ch <= 'z')
    {
      ch -= 'a' - 'A'; // 물론 대문자 아스키 코드가 더 작기에 빼야한다는 건 알아야겠지
    }
    else if (ch >= 'A' && ch <='Z')
    {
      ch += 'a' - 'A';
    }

    // if (ch=='f')
    // {
    //   ch = 'X';
    // }
    
    putchar(ch);
    // ch = getchar();
  }

  putchar(ch); // '\n' 출력을 위한 putchar()

  return 0;
}
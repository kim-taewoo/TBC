# CHAPTER 8

## 8.1 입출력 버퍼
효율적인 작업을 위해 한꺼번에 입력을 받거나 출력하는 데 쓰이는 것. 운영체제가 관리한다.

이론대로라면 getchar() 과 putchar() 을 while 문과 함께 쓸 때, 어떤 글자를 입력받자마자 putchar 이 실행되어 바로바로 처리가 되어야 한다. 하지만 실제로 해보면 abc 순서대로 입력받으면 aabbcc 가 아닌 abcabc 가 콘솔에 표시된다. 즉 입력받자마자 어떤 처리를 하는 게 아니라 입력받을 걸 순서대로 버퍼로 옮겨놨다가 입력이 끝난 후 버퍼 안에 담긴 내용을 한꺼번에 처리한다. 

> 버퍼를 사용하지 않는 입출력 콘솔을 경험하고 싶다면 `#include <conio.h>` 하고 `getchar()` 대신 `_getch()`나 `_getche()` 로 입력받아보자. getche의 e는 echo 다. getch() 는 echo 없이 그냥 입력받은 그대로 출력하고 끝난다.

```c
#include <stdio.h>
#include <conio.h>
int main()
{
  char c;
  while((c = _getche()) != '.') // echo
    putchar(c);
  return 0;
}
```

보통 버퍼를 비우는 타이밍은 
1. 버퍼가 꽉 차거나
1. 엔터를 눌렀을 때다.

## 8.2 파일의 끝
아스키 코드에 음수는 없다. 대신 어떤 파일의 끝을 EOF(-1) 로 표현한다. 코드를 짤 때 EOF 라고 표기할 수 있다. 콘솔 안에서 입력할 때는 `ctrl + z` 키를 누르면 EOF 를 입력할 수 있다. `^Z` 로 보이기도 한다.

## 8.3 입출력 방향 재지정(redirection)
실행파일의 결과를 콘솔 대신 txt 파일 등에 출력하도록 리디렉션할 수 있다.

`lecture3.exe > output.txt`

**>** 대신에 **>>** 을 쓰면 파일을 덮어쓰지 않고 추가가 된다.

## 8.5 숫자와 문자를 섞어서 입력받기
`scanf()` 는 본인이 받을 수 있는 것까지만 입력받고 예정에 없던(자신이 받을 수 없는) 값을 만나면 입력받는 것을 중단하고 남은 입력은 버퍼에 남겨둔다. 이 때문에 예상치 못한 빈줄이 많이 생기거나 이해하기 힘들 게 작동할 때가 있다. 즉 내가 원하는 대로 작동하는 입출력 코드를 짜기 어렵다. 그래서 `getchar()` 을 함께 사용하는 게 좋다. scanf() 의 뒤에 `while(getchar()!='\n') continue;` 처럼 scanf() 로 인해 버퍼에 남은 것을 비워주는 코드를 추가해놓는 습관을 들이는 것이 좋다. 종료 조건을 getchar() 로 설정하고, 여러 자료형의 변수를 원하는 포맷으로 받을 때만 scanf() 를 쓰는 방식을 잘 기억해두자.

## 8.6 입력 확인하기

## 8.7 입력 스트림과 숫자
기본적으로 콘솔을 통해 입력받는 것은 모두 문자열이지만(물론 더 내부적으론 바이너리겠지), scanf() 등을 통해 원하는 자료형으로 변환하여 사용할 수 있다.

## 8.9 텍스트 파일 읽기
`#include <stdlib.h>` 를 하면 exit() 코드를 통해 파일 실행을 중지시킬 수 있다. `exit(1);` 에서 1 은 필수가 아니고, 메인함수의 return 이  0 이었든, 그저 임의의 유언 같은 것이다. 원하는 숫자로 바꿔도 무방하다.

 파일 변수는 포인터로 하며, fopen() 으로 열고 fclose() 로 닫아줘야 한다.

 ```c
 int c;
 FILE * file = NULL;
 char file_name[] = "my_file.txt";

 file = fopen(file_name, "r");
 if (file == NULL)
 {
   printf("Failed to open\n");
   exit(1);
 }

 while ((c=getc(file)) != EOF) //  getc()는 파일*도 받을 수 있어서 씀.
 {
   putchar(c);
 }
 fclose(file);
 ```
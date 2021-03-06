# CHAPTER 11

> "언덕을 넘어가는 순간, 속력을 얻기 시작할 것이다."  _찰스 슐츠

## 11.1 문자열을 정의하는 방법들
**문자열도 배열이다.**

`puts("문자열입니다.")` 라는 puts 문자열 출력함수는 \0 까지 자동으로 출력해주며, 마지막에 \n 도 알아서 추가해주는 편리한 출력함수다. `putchar('a')` 라는 한 글자 출력함수도 있다.

배열은 읽기/쓰기가 모두 가능한 메모리를 사용해 원소의 수정이 자유롭지만, 문자열은 읽기 전용 메모리를 사용하기 때문에 const 의 여부와 관계없이 원소를 수정할 수 없다.

미리 정의해놓은 넉넉한 배열의 길이보다 짧은 문자열을 초기화하면, warning 이 뜨기도 한다. 크게 신경쓰지 말자.

`char greetings[50] = "Hello" "How are" "you today";` 같이 여러 조각으로 나뉜 문자열도 합쳐서 초기화된다.

배열에 한 글자씩 초기화를 할 경우 마지막에 '/0' 을 수동으로 써줘야 한다. 물론 요즘은 컴파일러가 해주긴 한다.

## 11.2 메모리 레이아웃과 문자열
1. `char arr[] = "Hello world";`   
1. `char* str = "Hell world";`  
위 두 코드는 위에 것은 배열에 복사해 넣지만, 아래 것은 포인터로 문자열의 시작점을 읽어온다는 점에서 차이가 있다. 즉 2 번은 한번 초기화 한 것을 수정할 수 없는 읽기전용 메모리다. 그래서 **포인터로 문자열을 받을 때는 아예 처음부터 const 로 변수를 만드는 것을 추천한다.**

2번째 방식처럼 문자열을 가리키는 포인터를 사용했을 때 읽기 전용 메모리에 저장되는 것은 컴파일러와 연관이 있다. 컴파일러는 최대한 프로그램 용량을 줄이기 위해서 같은 문자열이 여러곳에서 쓰이면, 문자열은 한 곳에만 저장하고 그 문자열을 가져다 쓰도록 컴파일한다. 즉, 1번째 방식처럼 복사해서 사용하지 않고 2번째 방식처럼 포인터로 가리키고 있는데, 한 곳이 아니라 여러곳에서 그 문자열을 가리키고 있는 경우 어떤 한 곳에서 수정할 수 있다면 그것을 가리키고 있는 다른 모든 곳에서 보는 문자열도 다같이 바뀌는 문제가 발생한다.

## 11.4 문자열을 입력받는 다양한 방법들
`scanf()`를 이용할 때, 문자열을 위한 배열은 애초에 포인터의 성격을 가지기 때문에 굳이 & 를 붙여줄 필요가 없다.  
`scanf("%s", name);`  
`gets()` 를 쓰면, 한 단어가 아닌 한 줄을 읽어오며, 뒤의 `\n` 을 제거하고 `\0` 을 추가해준다. `puts()` 가 마지막에 `\n` 을 붙여주는 것과 상반됨. c++11 부터는 `gets_s(words, sizeof(words));` 를 써서 끝나는 부분을 미리 알 수 있는 함수를 쓴다.

기존에 정의했던 길이보다 긴 문자열을 받으면 `gets()` 를 이용했을 때 런타임 에러가 뜬다. 이 때는 `fgets(words, STRLEN, stdin)` 와 `fputs(words, stdout)` 라는 본래는 파일 입출력에 이용하는 함수를 응용하면 에러없이 콘솔입출력이 가능하다. `fgets()` 는 `gets()` 와 달리 `\n` 을 제거해주지 않고 그대로 가져온다.

최근에는 `scanf()` 대신 `scanf_s()` 를 이용해서 받아오고자 하는 입력의 길이를 제한함으로써 런타임 에러를 없애곤 한다. 

```c
char str1[6], str2[6];
// int count = scanf("%6s %6s", str1, str2); // run-time error
int count = scanf_s("%5s %5s", str1, 6, str2, 6);
printf("%s|%5s \n", str1, str2);
```

## 11.6 다양한 문자열 함수들
매개변수로 문자열 배열의 시작부, 즉 배열의 시작포인터를 받을 때는 주로 `char* str` 같이 `char*` 으로 받아준다.
```c
// 문자열의 길이를 원하는 길이까지 잘라주는 함수.
void fit_str(char* str, unsigned int size)
{
  if (strlen(str) > size)
  {
    str[size] = '\0';
  }
}
```

`strcat(str1, str2)` 은 두 개의 문자열을 합쳐주고, `strncat(str1, str2, 2)` 은 두 개의 문자열을 합쳐주되, 설정한 개수만큼만 뒤 문자열을 잘라서 합쳐준다.

`strcmp(str1, str2)` 는 두 문자열을 비교해주는데, 반환값이 특이하다. **같으면 0, 앞의 것이 뒤의 것보다 아스키 코드가 작으면 -1, 앞의 것이 뒤의 것보다 아스키 코드가 크면 1 을 반환한다.**

`strncmp(str1, str2, n)` 은 n 개의 문자열까지만 비교해서 결과를 반환한다.

`strcpy(destination, source)` 는 문자열 복사함수이며 `strncpy(destination, source, n)` 을 이용해서 원하는 개수만큼만 복사도 가능하다. 다만 n 개 복사후 자동으로 `\0` 을 추가해주지 않는다는 걸 주의하자.

그밖에 다양한 문자열 출력 함수가 있다. 
```c
printf("%s\n", strchr("Hello, World", 'W')); // World 출력. 해당 글자로 시작하는 부분부터 출력
printf("%s\n", strpbrk("Hello, World", 'abcde')); // ello, World 출력. 주어진 문자열 중에 어떤 글자로 시작하는 부분부터 출력. 없으면 (null) 출력
printf("%s\n", strrchr("Hello, World", 'l')); // ld 출력. 해당 글자로 시작하는 마지막 부분 출력
printf("%s\n", strstr("Hello, World", 'Wor')); // World 출력. 해당 문자열로 시작하는 부분부터 출력
```
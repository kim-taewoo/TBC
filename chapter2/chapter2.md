# CHAPTER 2

>"달을 향해 쏴라. 맞추지 못하더라도 별들 사이에 머물게 될 것이다." _ Norman Vincent Peale

## 2.5 변수 선언

1. 변수 '정의'(definition) 라고 불리는 특별한 선언(declaration)
1. 선언된 변수 내에 값 할당(assignment)

::: tip '초기화'란?
선언과 동시에 대입연산자(=)를 통해 값을 할당하는 것
:::

## 2.6 printf() <small>*print formatted*</small>
문자열 출력시 줄바꿈을 하고 싶은 경우 **\n** (escape sequence) 을 사용한다. 

printf() 함수 안에 하드코딩된 문자열 외 숫자나 변수를 넣어 출력하고 싶다면 **%i**(integer), **%d**(decimal) 등을 활용한다.

`printf("%i + %i = %i", x, y, z`)

**/a** 를 출력하면 오디오 소리가 난다.

## 2.7 주석 다는 방법
주석 자체는 /* */ 로 블록 주석을 하거나 // 로 줄 주석을 달 수 있는데, 꼭 필요한 데만 달고, 주석 없이도 이해될 수 있도록 변수 자체의 이름을 잘 짓는 게 좋다.

## 2.8 키워드와 예약어
cppreference.com  의 C keywords 에서 문법적으로 사용하는 키워드와 예약어를 볼 수 있다.

전처리기든 키워드든 예약어든, 굳이 덮어씌우는 짓을 하지 말자.

## 2.9 함수 만들기
함수의 body 를 포함한 함수의 정의 부분이 맨 밑에 있더라고, 함수의 prototype 가 문서 맨 위에 선언되어 있다면 어디서든 그 함수를 사용 가능하다.

## 2.10 디버거 사용법
코드에서 검사를 원하는 부분의 시작점에 breakpoint 를 찍은 후, 디버거를 실행시켜 프로그램 진행의 상태(state) 를 살펴볼 수 있다. Visual Studio 에서는 **F11** 으로 한 칸씩 코드를 진행시킬 수 있다.

## 2.11 문법 오류와 문맥 오류
문법 오류는 IDE 가 잘 잡아준다.
오히려 문맥 오류를 발생시키지 않도록 프로그래머의 주의가 필요하다.

## 2.12 읽기 좋은 코드를 만드는 요령
협업하는 사람과 코딩 스타일을 잘 맞추는 것이 중요하다. 

좋은 코드를 보며 코딩 스타일을 배우는 것도 좋다. (ex 리눅스 코드)
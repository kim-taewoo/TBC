# CHAPTER 6
> "성공의 두 가지 요구조건은, 첫째는 올바른 때에 올바른 장소에 있는 것이고 둘째는 성공과 관련된 일을 하는 것이다."  __Ray Kroc

## 6.1 while 반복 루프에서 scanf() 의 반환값 사용하기
`scanf()` 는 받아오기로 지정한 형식지정자와 형식이 맞지 않는 입력값을 받으면 에러를 발생시킨다. 그래서 반환값을 사용하지 않으면 잘못 입력한 순간 프로그램 전체가 먹통이 된다. 따라서 반환값을 받아 제대로 입력받지 못하면 0 이라는 점을 이용해야 프로그램 전체가 망가지는 것을 막을 수 있다. 앞서 배웠듯이 `scanf()` 의 반환값은 입력받은 변수의 개수이다.

::: tip 알아두자
`cin.ignore() // 버퍼 버리기`, `cin.clear() // 에러 삭제` 를 이용하는 방법도 알아두자.
:::

## 6.4 관계 연산자
실수끼리의 비교는 완벽히 일치하는 지 찾기보다는 적당히 비슷한가를 보는 경우가 많다. 이 경우 `<math.h>` 라이브러리에서 `fabs()  // abs() for floating point numbers` 를 이용해 절대값 차이가 얼마 이하인지를 비교한다.

## 6.8 for 루프 소개
**구조**\
for(initialize; test; update)\
{\
&ensp; statement\
}
```c
for (int i = 0; i <=10; i++)
  printf("%d", i);
```
## 6.10 다양한 대입 연산자들 (그리고 어셈블리 코드 확인법)

## 콤마 연산자
for 문에서, 여러 변수를 initialize(같은 자료형이여야 함) 하기 위해서나 여러 update 를 하기 위해서 쓰는 콤마(,) 를 콤마 연산자라고 한다. 

::: warning 주의
흔히 함수를 호출할 때 인자를 여러 개 넣기 위해 쓰는 콤마는 그냥 seperator로, 콤마 연산자는 아니다.
:::

보통 세미콜론(;) 을 sequence point 라고, 어떤 statement 의 끝점으로서 앞선 코드를 완결짓는 느낌으로 작동하는데, 콤마도 마찬가지로 sequence point 다. 즉 `i++, j = i;` 같은 코드가 있으면, `i++` 가 이뤄진 상태로 j 에 대입된다.

콤마 연산자가 포함된 괄호가 있을 때, 콤마 연산자는 콤마 오른쪽 값을 값으로써 반환한다. 
```c
  int my_money = (123,456);
  printf("%d", my_money); // 456 이 출력됨.
```

## 제논의 역설 시뮬레이션 예제
> 아킬레우스가 거북이를 따라잡을 수 없다는 제논의 역설을 시뮬레이션 해보자.

::: tip Tip
곱하기가 나누기보다 빠르다. 
`/ 2` 보다 `* 0.5` 를 쓰자.
:::

## 6.13 탈출조건 루프 do while
**무조건 한 번은 실행시켜야 하는 코드** 를 작성할 때, 일반적인 while 문을 썼을 때는 while 문 전과 while 문 안에 중복되는 코드를 작성하는 일이 생길 수 있다. 이 경우 do - while 문을 쓰면 좋다. (for 문으로 해결되는 경우도 있다.)

```c
int secret_code = 337;
int guess = 0;
// 아래와 같은 중복 코드 발생
// printf("Enter secret code : ");
// scanf("%d", &guess);
// while (guess != secret_code) 
// {
//   printf("Enter secret code : ");
//   scnaf("%d", &guess);
// }

do
{
  printf("Enter secret code : 
  ");
  scanf("%d", &guess);
}
while (guess != secret_code);
printf("Good!");
```

## 6.14 어떤 루프를 사용할까?
1. 진입조건 vs 탈출조건
    * 진입조건이면 while, for
    * 탈출조건이면 do-while

## 6.16 배열과 런타임 에러
인덱스 범위를 벗어난 out of bound 에러는 컴파일 때는 에러가 발생하지 않고 런타임 에러가 난다.

for 루프 하나에 여러 개의 처리할 것을 넣는 것보다 두 개의 for 문으로 쪼개는 게 성능 측면에서 나을 때가 있다.
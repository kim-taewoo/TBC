# CHAPTER 3

>"우리는 과거를 알지만 제어할 수는 없다. 우리는 미래를 제어할 수는 있지만 알 수는 없다."  _Claude Shannon

## 3.1 데이터와 자료형 <small>Data and Data Types</small>

- 자료형은 사실 정수형/실수형 두 개만 있다고 생각해도 된다. 
- 얼마나 큰 수를, 혹은 얼마나 작은 수를 사용할 예정이냐에 따라 세부적으로 나뉠 뿐이다.
- 컴퓨터 내부적으로 문자도 정수형으로 저장된다. 

## 3.2 변수와 상수

| 자료형 | 변수 | 리터럴 상수 |
|---|:---:|---|
|int|angel|1004;|

앞에 한정자, 제한자(Qualifier)를 덧붙여 쓸 수 있으며, 변수를 **기호적 상수**(Symbolic constant) 라고 하기도 한다. (예: `const`)

| 한정자, 제한자 | 자료형 | 기호적 상수 | 리터럴 상수 |
|:---|---|:---:|---|
|const|int|angel|1004;|

## 3.3 scanf()
콘솔로 부터 사용자의 입력을 받아 변수에 저장할 때 사용한다. `scanf()` 를 통해 받아온 값을 `&`(ampersand) 를 붙인 변수에 저장한다. (그냥 and 라고 읽는 사람도 있지만 정식명식은 엠펄샌드)

```c
int i = 0;
scanf("%d", &i);
```

::: warning
Visual Studio 에서 `scanf()` 를 쓰면 제대로 컴파일 되지 않는다. 어쩔 수 없이 `#define _CRT_SECURE_NO_WARNINGS` 라는 전처리기를 입력해주거나 VS 설정에 이 전처리 옵션을 따로 지정해 주어야 한다. (옵션 설정시 Release 모드와 Debug 모드 구분 필수)
:::

왜 **&** 를 붙여야 하는가? 

call by reference 개념 공부하자.

## 3.4 간단한 입출력 프로그램 만들기
```c
int i = 0, j = 0;
printf("Input two integers\n");
scanf("%d%d", &i, &j); // 띄어쓰기 없어도 됨에 유의
printf("Your numbers are &d &d\n, i, j);
```

- 터미널에 입력을 할 때, **띄어쓰기나 줄바꿈**으로 입력 값이 구분된다. 

::: tip TODO
`printf()` 와 `scanf()` 에 들어갈 수 있는 모든 형식 지정자 format specifier (예 : %d) 를 찾아보도록 하자.
:::

::: tip
C++ 등 다른 언어에서는 굳이 형식 지정자를 사용하지 않아도 출력할 수 있는 방법이 있다. (iostream)
:::

::: tip
형식지정자(format specififer) 대신 conversion specifier 을 공식명칭으로 쓰기도 한다.
:::

## 3.5 정수와 실수

### 정수 (Integers)
* 음의 정수, 0, 양의 정수
* 내부적으로 2진수 사용
### 실수 (Real numbers)
* 내부적으로 **부동소수점 _(floating point)_** 표현법 사용
* 3.14 = 3.14E0 = 3.14e0 = 0.314E1 = 31.4E-1  (E 는 지수*Exponent* 의 E)
* 내부적으로 2진수 사용

| 부호 | 지수 | 분수 | 결과 |
|:---|---|:---:|---|
|+|-1|0.3141592|0.03141592|
|+|2|0.3141592|31.41592|

## 3.6 정수의 오버플로우
`include <limits.h>`\
`signed int i_max = INT_MAX;` 같이 사용하면 자료형 마다의 최대값 혹은 최소값을 알아낼 수 있다. 각 자료형마다의 범위를 벗어나면 오버플로우가 발생한다.

## 3.10 문자형
*char* 의 형식지정자는 %c 인데, %hhi 를 쓰면 해당 *char* 의 아스키코드를 출력할 수 있다.

## 3.11 부동소수점형
significant figure : 유효숫자
exponent : 지수
유효숫자 * 10^지수

# CHAPTER 14 구조체

> "저는 걷는 게 느린 사람입니다. 그러나 절대로 되돌아가지는 않습니다."  _에이브러햄 링컨

## 14.1 구조체가 필요한 이유

자료형이 서로 다르지만 함께 사용하면 편리한 데이터 오브젝트끼리 모으는 것이 목적. 

마치 새로운 변수형인 것처럼 사용하는 게 가능하다. (structure variables)

dot(.) 연산자를 이용해 structure variable 의 멤버에 접근할 수 있다.

```c
struct patient
{
  char name[MAX_NAME];
  float height;
  float weight;
  int age;
};

struct Patient p1, p2, p3;
```

## 14.2 구조체의 기본적인 사용법

구조체를 정의할 때 그 이름은 식별자라고 하기 보다 꼬리표(tag) 라고 한다. C++ 의 클래스와 달리 구조체의 태그는 굳이 대문자로 사용하자는 코딩 컨벤션이 없다.

구조체를 선언하는 단계에서는 메모리가 할당되지 않고, 구조체 변수가 선언되어야 그 때 메모리가 할당된다.

dot(.) 이 member access operator 로써 활용된다.

배열을 초기화하는 것과 비슷하게 uniform initialization 을 할 수 있다. 

```c
struct patient
{
  char name[MAX_NAME];
  float height;
  float weight;
  int age;
};

struct patient patient1 = {
  "Joshua Kim",
  180.0f,
  80.0f,
  25
};
```

Designated initializers 방식으로 초기화하면, 순서와 관계없이 초기화도 가능하다.

```c
struct patient patient1 = {
  .height = 180.0f,
  .age = 25
  .name = "Joshua Kim",
  .weight = 80.0f,
};
```

구조체 변수에 대한 포인터도 선언이 가능하다. 다만 이 경우 멤버 접근 연산자가 dot(.) 이 아닌 arrow(->) 가 된다. de-referencing 해서 . 을 사용해도 되고.

tag 없이 구조체를 정의하고 곧바로 구조체 변수를 만들어 쓸 때도 있다.

```c
struct {
  char farm[MAX];
  float price;
} apple, apple2;
```

`typedef` 와 함께 쓰는 경우가 많다. 구조체 자체를 새로운 자료형인 것처럼 쓰는 것이다. 구조체의 tag를 생략하고 본래 tag 로 쓰려고 했던 이름을 typedef 를 이용한 구조체 변수로 선언해서 자료형인 것처럼 쓰는 사례가 많다.

```c
typedef struct person person;
person p4;

typedef struct {
  char name[MAX];
  char hobby[MAX];
} friend;  // 아예 이런식으로 꼬리표(tag)를 뒤에 붙인 것처럼 사용.

friend f4;
```

## 14.3 구조체의 메모리 할당

1 바이트짜리 `char` 자료형이 구조체의 멤버로 있을 때, 그 구조체의 변수의 메모리 크기를 출력해보면 `char` 이 4바이트를 차지하고 있다. 이렇게 컴파일러가 빈공간을 채워주는 걸 구조체 멤버의 정렬을 위해 **padding** 이 있다고 말한다. cpu 와 메모리 간 데이터 전송의 효율을 위한 것으로, x86 에서는 데이터 전송단위인 1 word 가 4바이트, x64 에선 8바이트다.

## 14.6 구조체와 포인터

구조체의 포인터 변수가 멤버에 접근하려면 dot(.) 이 아닌 arrow(->) 로 접근해야 한다. 

같은 구조체 변수끼리는, 대입연산자를 통해 값을 복사해올 수 있다.

`struct my_data d2 = d1;`
위 경우, d1 구조체 변수에 있는 멤버 값들이 d2 에 복사된다. 정적 배열일 때도 복사되어 새로운 메모리 주소를 가지게 되지만, <u>**동적 할당 배열일 때는 같은 주소를 공유한다.**</u>

## 14.7 구조체를 함수로 전달하는 방법

함수에 구조체 변수를 그냥 넘기면 복사되어 넘어간다. 복사를 하는 과정에서 메모리 낭비와 성능 낭비가 발생하므로, 포인터로 넘겨주는 게 좋다.

## 14.8 구조체와 함수 연습 문제

`s_gets()` 대신 `scanf("%[^\n]%*c", ptr_nc->first)` 를 써서 성능을 높일 수 있다. `%[^\n]` 은 줄바꿈이 나올 때까지 문자열을 받으라는 뜻이며, `%*c` 는 c를 하나 무시하라는 것으로, 이 문맥상으로는 줄바꿈기호(\n) 을 하나 무시하게 된다. 즉 사용자가 입력한 문자열을 줄바꿈 기호를 무시하고 입력받게 된다.

```c
// s_gets(ptr_nc->first, NLEN);
flag = scanf("%[^\n]%*c", ptr_nc->first);
```

## 14.10 복합 리터럴

마치 익명함수처럼, 구조체를 좀더 간편하게 이용하는 방법.

구조체 변수를 맨 처음 `{}` 를 이용해 초기화 한 이후에는 같은 방식으로 내용을 바꿔서 재 초기화 할 수는 없다. 그런데 구조체 멤버 하나하나를 수정하는 게 너무 귀찮다면, 복합 리터럴을 이용해서 값을 재대입할 수 있다. **복합** 리터럴인 이유는 구조체가 다양한 자료형의 모음이기 때문이다. 

```c
/// 이미 위에서 book_to_read 라는 book 구조체의 변수가 초기화 된 상황.
book_to_read = (struct book){"Alice in wonderland", "Lewis", 20.3f};
```

복합 리터럴은 신기하게도 L-value 이다. 그래서 구조체 포인터를 매개변수로 받는 함수에 넘겨줄 수 있다.

```c
area = rect_area_ptr(&(struct rectangle) {.height = 3.0, .width =2.0});
```

## 신축성있는 배열 멤버

구조체 멤버중 배열이 있을 때, `values[]` 같이 몇 칸의 배열인지 정적으로 선언해놓지 않고, 구조체 변수를 포인터 변수로 초기화 할 때 필요한 길이만큼 동적 할당을 해서 쓰면 신축성 있는 배열 멤버라고 한다. 이 때 이 배열의 메모리 크기가 구조체 변수의 메모리 크기에 합산되지 않는다. 그렇지만 동적 할당된 메모리 주소가 다른 구조체 멤버의 메모리 주소와 연속되게 배정받기 때문에 위치가 예측가능하다는 장점이 있다.

## 14.12 익명 구조체

nested structure member 를 이름 없이 정의해놓으면 익명 구조체 멤버라고 한다. 이 경우, 오히려 그 이름에 접근해야 하는 단계가 생략되어 접근이 간편해진다. 

```c
struct names
{
  char first[20];
  char last[20];
};

// struct person
// {
//   int id;
//   struct names name; // nested
// } // 이렇게 다른 struct 를 가져다 쓰는 대신

struct person
{
  int id;
  struct { char first[20];
  char last[20]; } // 직접 입력 anonymous structure
};

struct person ted = {123, {"Bill", "Gates"}};

puts(ted.first); // 이렇게 바로 접근 가능.
```

## 14.14 구조체 파일 입출력 연습문제

_제대로 공부 안 함.. 꽤 종합적인 공부가 필요._
구조체를 파일에 저장하거나 불러오는 방법

## 14.15 공용체의 원리

'조합' 이라고 번역되며, 구조체와 겉보기에 유사한 문법을 쓴다. 

멤버들이 각각 메모리를 차지하는 구조체와 달리 공용체는 서로 다른 자료형을 가진 데이터들이 **같은 메모리 공간을 공유**한다. 

공용체의 멤버중 가장 큰 자료형의 메모리 크기가 배정이 되며, 모든 멤버의 시작 주소가 동일하다.

## 14.16 공용체와 구조체를 함께 사용하기

어떤 구조체의 멤버를 공용체로 두어, 상황에 따라 다른 nested 구조체 멤버를 불러오는 방법을 쓴다.

```c
union data {
  struct personal_owner po;
  struct company_owner co;
}

struct car_data {
  char model[15];
  int status; // 0 이면 개인, 1이면 법인
  union data ownerinfo;
}
```

물론 이렇게 구조체와 공용체를 일일이 따로 선언해놓기 보다는 익명 구조체와 익명 공용체를 이용해서 접근성을 높이는 경우가 많다. (아래 내용 참고)

## 14.17 익명 공용체

익명 구조체와 익명 공용체를 잘 활용하면 유연한 구조체를 만들어 사용할 수 있다. 아래 예시를 보면, 어떤 구조체를 사용하든지 상관없이, 같은 for 문으로 출력 가능하다는 것을 알 수 있다.

```c
struct Vector2D {
  union {
    struct {double x, y;};
    struct {double i, j;};
    struct {double arr[2];};
  };
};

typedef struct Vector2D vec2;

vec2 v = { 3.14, 2.99 };
printf("%.2f %.2f\n", v.x, v.y);
printf("%.2f %.2f\n", v.i, v.j);
printf("%.2f %.2f\n", v.arr[0], v.arr[1]);

// 어떤 구조체를 이용하든 간에 아래 for 문으로 공통되게 출력 가능.
for (int d = 0; d < 2; d++)
{
  printf("%.2f ", v.arr[d]);
}
```

## 14.18 열거형 EnumeratedTypes

0 부터 나열된 정수 숫자에 이름을 붙여주는 것처럼 작동한다. 마치 매크로로 `#define red = 0` 인 것처럼 배정하는 것이다. red 와 0 을 동일시 하는 것이지 `"red"` 같은 문자열을 배정하는 게 아니라는 점에 주의하자. 즉 `printf(red);` 를 한다고 `"red"` 가 출력되지는 않는다. 단순히 나열하지 않고 직접적인 정수를 선언해주면, 그것을 기점으로 그 정수에 1을 더한 정수가 대입된다.

```c
enum spectrum { red, orange, yellow, green = 10, blue, violet}; // red 가 0, green 부터는 10, 11.. 이 됨

enum spectrum color;
color = blue;
if (color == yellow)
{
  printf("Yellow");
}
```

## 14.21 함수 포인터의 원리

함수 자체가 배열과 같이 함수가 저장된 주소를 가리키고 있기 때문에 굳이 **&** 를 붙이지 않아도 된다. 

함수 포인터를 만들 때는 반환 자료형과, 매개변수들의 자료형을 써야 한다. 같은 맥락에서, 함수 포인터로 함수를 실행시킬 때 굳이 de-referencing 해주지 않아도 된다.

```c
int f2(char i)
{
  return i+1;
}

int (*pf2)(char) = f2; // &f2 도 가능

int a = (*pf2)('A'); // pf2('A'); 도 가능.
```

함수 자체는 문자열과 마찬가지로 프로그램 코드 영역, 즉 주소가 가장 낮은 Read-only 영역에 저장되지만, 함수포인터 변수는 스택에 저장된다.

## 14.22 함수 포인터의 사용 방법

함수 포인터는 어떤 함수의 **매개변수로 함수를 넘겨주고 싶을 때** 주로 쓰인다. 즉 그 함수 내에서 어떤 함수를 사용할 지 갈아 끼울 수 있는 것이다. 

## 14.24 복잡한 선언을 해석하는 요령

1. \* 보다 () 과 [] 의 우선순위가 높다.
1. 안쪽에서 바깥쪽으로 읽자.

#include <iostream>

// 함수에 기본값을 줄 수 있다. 인자 값이 넘어오지 않는 경우 기본값으로 초기화 된다.
// 선언과 정의가 분리 된 경우, 선언부에 써주도록 한다. (함수의 문서화)

int GetNum();           // 기존 함수의 사용과 모호함이 생기는 방식으로 선언 할 수 없다.
int GetNum(int a = 10); // 기본값으로 인해 GetNum() 과 같은 방식으로 사용이 가능하다.

// 인자의 타입이 다르거나
int GetNum(float a);

int GetNum(int a, int b, int c = 12); // 인자의 기본값은 뒤에부터 선언이 되어야 하며,
int GetNum(int a, int b = 11, int c = 12);
// int GetNum(int a, int b = 11, int c); // 중간 인자부터 선언 할 수 없다.

// 같은 이름으로 사용 할 수 있다

// 하지만 반환값의 타입은 조건에 해당 하지 않는다
// double GetNum(int a);

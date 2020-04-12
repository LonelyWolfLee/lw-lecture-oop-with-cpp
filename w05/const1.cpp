#include <iostream>

class Example
{
private:
  int num1;

public:
  int num2;
  Example(int n1, int n2) : num1(n1), num2(n2) {}
  void Function1()
  {
    num1++;
  };
  void Function2() const
  {
    std::cout << num2 << std::endl;
  };
};

int main(int argc, char const *argv[])
{
  const Example ex(1, 2);

  // 변수의 값을 직접 변경 할 수 없다.
  // ex.num2 = 100;

  // 일반 함수 호출은 안된다.
  // 변수의 값 변경이 가능한 함수이기 떄문이다.
  // ex.Function1();

  // const 객체는 const 함수만 호출이 가능하다.
  ex.Function2();
  return 0;
}

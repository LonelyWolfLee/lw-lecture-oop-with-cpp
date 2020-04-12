#include <iostream>
using namespace std;
class Example
{
private:
  static int num1;
  int num2;

public:
  Example() : num2(0) {}
  static void ShowNum1()
  {
    // static 함수는 static 변수에 접근 할 수 있다.
    cout << "Num1 = " << num1 << endl;
  }
  // static void ShowNum2()4
  // {
  //   // static 함수는 특정 객체에 귀속되지 않는다.
  //   // 그렇기 때문에 객체의 속성인 num2 에는 접근 할 수 없다.
  //   cout << "Num2 = " << num2 << endl;
  // }
};
int Example::num1 = 0;

int main(int argc, char const *argv[])
{
  Example ex;

  Example::ShowNum1();
  ex.ShowNum1(); // 가능하지만 나쁜 사용 예

  return 0;
}

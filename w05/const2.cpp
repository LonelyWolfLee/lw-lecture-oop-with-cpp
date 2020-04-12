#include <iostream>

using namespace std;

class Example
{
public:
  void Function()
  {
    cout << "일반 함수 입니다." << endl;
  };
  void Function() const
  {
    cout << "상수 함수 입니다." << endl;
  };
};

int main(int argc, char const *argv[])
{
  Example ex1;
  const Example ex2;
  ex1.Function();
  ex2.Function();
  return 0;
}

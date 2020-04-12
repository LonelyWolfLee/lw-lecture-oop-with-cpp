#include <iostream>

class Example
{
private:
  mutable int num1;
  int num2;

public:
  Example() : num1(0), num2(0) {}
  void Modify() const
  {
    num1++; // mutable 변수여서 const 함수에서 변경 가능
    // num2++; // const 함수여서 불가능
  }
};

int main(int argc, char const *argv[])
{
  Example ex;
  ex.Modify();
  return 0;
}

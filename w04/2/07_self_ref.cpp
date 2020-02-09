#include <iostream>

using namespace std;

class IntNumber
{
private:
  int num;

public:
  IntNumber(int num) : num(num) {}
  IntNumber &Plus(int num)
  {
    cout << this->num << " + " << num << endl;
    this->num += num;
    return *this;
  }
  IntNumber &Minus(int num)
  {
    cout << this->num << " - " << num << endl;
    this->num -= num;
    return *this;
  }
  void Answer()
  {
    cout << "Ans = " << num << endl;
  }
};

int main(int argc, char const *argv[])
{
  IntNumber number(100);
  number.Plus(20).Minus(60).Answer();
  return 0;
}

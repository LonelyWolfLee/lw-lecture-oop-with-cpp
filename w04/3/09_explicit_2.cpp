#include <iostream>
using namespace std;

class Sample
{
private:
  int num1, num2;

public:
  explicit Sample(int num1, int num2 = 10)
      : num1(num1), num2(num2) {}
  void Show() { cout << num1 << ", " << num2 << endl; }
};

int main(int argc, char const *argv[])
{
  Sample s1(10, 20); // s1 = {10, 20} 안됨
  s1.Show();
  Sample s2(5); // s2 = 5 안됨
  s2.Show();
  return 0;
}

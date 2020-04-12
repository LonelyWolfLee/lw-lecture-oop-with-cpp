#include <iostream>

using namespace std;

class Person1
{
private:
  int num;

  // 선언 위치는 관계 없다.
  // 그래서 private 에도 가능
  friend class Person2;

public:
  Person1(int n) : num(n) {}
};

class Person2
{
public:
  void ShowInfo(const Person1 &p)
  {
    // Person2 는 Person1의 friend 이므로
    // private 정보에 접근이 가능하다.
    cout << "Num = " << p.num << endl;
  }
};

int main(int argc, char const *argv[])
{
  Person1 p1(100);
  Person2 p2;
  p2.ShowInfo(p1);
  return 0;
}

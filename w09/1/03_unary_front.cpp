#include <iostream>

using namespace std;

class Point
{
private:
  int x, y;

public:
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  void Show() const
  {
    cout << "[" << x << ", " << y << "]" << endl;
  }

  // 멤버 함수로 ++ 정의
  Point &operator++()
  {
    ++x;
    ++y;
    return *this;
  }
  friend Point &operator--(Point &p);
};

// 전역 함수로 -- 정의
Point &operator--(Point &p)
{
  --p.x;
  --p.y;
  return p;
}

int main(int argc, char const *argv[])
{
  Point p(1, 2);
  ++p; // p.operator++()
  p.Show();
  --p; // operator--(p)
  p.Show();
  return 0;
}

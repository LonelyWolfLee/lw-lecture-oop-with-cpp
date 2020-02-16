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
  const Point operator++(int)
  {
    const Point p(x, y);
    x++;
    y++;
    return p;
  }
  friend const Point operator--(Point &p, int);
};

// 전역 함수로 -- 정의
const Point operator--(Point &p, int)
{
  const Point newP(p.x, p.y);
  p.x--;
  p.y--;
  return newP;
}

int main(int argc, char const *argv[])
{
  Point p(1, 2);
  (p++).Show(); // p.operator++(int)
  p.Show();
  (p--).Show(); // operator--(p, int)
  p.Show();
  return 0;
}

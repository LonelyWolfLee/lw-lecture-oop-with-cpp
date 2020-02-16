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

  // Member Function
  Point operator+(const Point &p)
  {
    Point newPoint(x + p.x, y + p.y);
    return newPoint;
  }
};

int main(int argc, char const *argv[])
{
  Point p1(1, 2), p2(3, 4);
  (p1 + p2).Show(); // p1.operator+(p2)
  return 0;
}

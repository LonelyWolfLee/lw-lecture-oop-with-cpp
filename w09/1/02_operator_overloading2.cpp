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
  friend Point operator+(const Point &p1, const Point &p2);
};

// Global Fuinction
Point operator+(const Point &p1, const Point &p2)
{
  Point newPoint(p1.x + p2.x, p1.y + p2.y);
  return newPoint;
}

int main(int argc, char const *argv[])
{
  Point p1(1, 2), p2(3, 4);
  (p1 + p2).Show(); // operator+(p1, p2)
  return 0;
}

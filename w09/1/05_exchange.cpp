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

  Point operator*(int times)
  {
    Point newPoint(x * times, y * times);
    return newPoint;
  }
};

Point operator*(int times, Point &p)
{
  return p * times;
}

int main(int argc, char const *argv[])
{
  Point p(1, 2);
  (p * 3).Show();
  (3 * p).Show();
  return 0;
}

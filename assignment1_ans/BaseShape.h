#ifndef __BASE_SHAPE_H__
#define __BASE_SHAPE_H__
#include "Canvas.h"

// 점
class Point
{
private:
  int x, y;

public:
  Point(int xx = 0, int yy = 0) : x(xx), y(yy) {}
  int getX() const { return x; }
  int getY() const { return y; }
  void move(int dx, int dy)
  {
    x += dx;
    y += dy;
  }
};

// 도형
class Shape
{
protected:
  Point p; // 형태의 기준 위치
public:
  Shape(int x = 0, int y = 0) : p(x, y) {}
  virtual void draw(Canvas &canvas, string val = "O")
  {
    canvas.draw(p.getX(), p.getY(), val);
  }
  virtual void move(int dx, int dy)
  {
    p.move(dx, dy);
  }
};

// 선을 그리기 위해 사용 할 함수
inline int Abs(int x) { return x > 0 ? x : -x; }
inline int Max(int x, int y) { return x > y ? x : y; }
inline int Round(double x) { return (int)(x + 0.5); }

#endif
#include <iostream>

/*
class Point
{
public:
  int x;
  int y;
};

class Ractangle
{
public:
  Point upLeft;
  Point lowRight;
};

이와 같이 했을 경우 문제점

- Point의 각 좌표가 0~100 사이의 값을 가져야 하는 경우
- Ractangle 위 좌상단 우하단의 위치가 뒤바뀌거나 꼬이는 경우

경고 또는 처리가 필요한데 일일이 제어 하는수 밖에 없다.
*/

using namespace std;

class Point
{
private:
  int x;
  int y;

public:
  bool InitMembers(int xpos, int ypos);
  int GetX() const;
  int GetY() const;
  bool SetX(int xpos);
  bool SetY(int ypos);
};

bool Point::InitMembers(int xpos, int ypos)
{
  if (!SetX(xpos) || !SetY(ypos))
  {
    cout << "벗어난 범위의 값 전달" << endl;
    return false;
  }
  return true;
}
int Point::GetX() const { return x; }
int Point::GetY() const { return y; }
bool Point::SetX(int xpos)
{
  if (0 > xpos || xpos > 100)
  {
    cout << "벗어난 범위의 값 전달" << endl;
    return false;
  }
  x = xpos;
  return true;
}
bool Point::SetY(int ypos)
{
  if (0 > ypos || ypos > 100)
  {
    cout << "벗어난 범위의 값 전달" << endl;
    return false;
  }
  y = ypos;
  return true;
}

class Rectangle
{
private:
  Point upLeft;
  Point lowRight;

public:
  bool InitMembers(const Point &ul, const Point &lr);
  void ShowRecInfo() const;
};

bool Rectangle::InitMembers(const Point &ul, const Point &lr)
{
  if (ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
  {
    cout << "잘못된 위치정보 전달" << endl;
    return false;
  }

  upLeft = ul;
  lowRight = lr;
  return true;
}

void Rectangle::ShowRecInfo() const
{
  cout << "좌 상단: " << '[' << upLeft.GetX() << ", ";
  cout << upLeft.GetY() << ']' << endl;
  cout << "우 하단: " << '[' << lowRight.GetX() << ", ";
  cout << lowRight.GetY() << ']' << endl
       << endl;
}

int main(void)
{
  Point pos1;
  if (!pos1.InitMembers(-2, 4))
    cout << "초기화 실패" << endl;
  if (!pos1.InitMembers(2, 4))
    cout << "초기화 실패" << endl;

  Point pos2;
  if (!pos2.InitMembers(5, 9))
    cout << "초기화 실패" << endl;

  Rectangle rec;
  if (rec.InitMembers(pos2, pos1))
    cout << "직사각형 초기화 실패" << endl;

  if (rec.InitMembers(pos1, pos2))
    cout << "직사각형 초기화 실패" << endl;

  rec.ShowRecInfo();
  return 0;
}
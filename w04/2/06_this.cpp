
class Point
{
private:
  int x;
  int y;

public:
  // 초기화를 위해서
  // 변수 이름을 또 생각해야 해?
  Point(int xpos, int ypos)
  {
    x = xpos;
    y = ypos;
  }
};

class Point
{
private:
  int x;
  int y;

public:
  // 편안 ~ 보기도 좋고 쓰기도 좋다.
  Point(int x, int y)
  {
    this->x = x;
    this->y = y;
  }
};

class Point
{
private:
  int x;
  int y;

public:
  // 사실 그냥 이러면 됨 ㅎㅎ
  Point(int x, int y) : x(x), y(y) {}
};

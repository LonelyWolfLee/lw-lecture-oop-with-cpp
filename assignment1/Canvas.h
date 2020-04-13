#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <iostream>
#include <cstring>
#define MAX_LINES 100

using namespace std;

class Canvas
{
private:
  string line[MAX_LINES];
  int xMax, yMax; // 맵의 크기
public:
  Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny)
  {
    for (int y = 0; y < yMax; y++)
    {
      line[y] = string(xMax, ' ');
    }
  }

  // x, y의 지점에 val 에 해당하는 값을 그린다.
  void draw(int x, int y, string val)
  {
    if (x >= 0 && y >= 0 && x < xMax && y < yMax)
    {
      line[y].replace(x, 1, val);
    }
  }

  // 전체 Canvas를 주어진 val 로 채운다.
  void clear(string val = " ")
  {
    for (int y = 0; y < yMax; y++)
    {
      for (int x = 0; x < xMax; x++)
      {
        draw(x, y, val);
      }
    }
  }

  // Canvas에 저장된 이미지를 출력한다.
  void print(const char *title = "<My Canvas>")
  {
    system("cls");
    cout << title << endl;
    for (int y = 0; y < yMax; y++)
    {
      cout << line[y] << endl;
    }
    cout << endl;
  }
};

#endif
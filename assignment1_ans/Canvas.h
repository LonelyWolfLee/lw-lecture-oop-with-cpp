#ifndef __CANVAS_H__
#define __CANVAS_H__

#include <iostream>
#include <cstring>
#include <string>
#define MAX_LINES 100

using namespace std;

#ifdef _WIN32
const char *COMMAND = "cls";
#else
const char *COMMAND = "clear";
#endif

class Canvas
{
private:
  string line[MAX_LINES];
  int xMax, yMax; // 맵의 크기
  const char *title;
  void clearScreen()
  {
  }

public:
  Canvas(int nx = 72, int ny = 24, const char *title = "<My Canvas>")
      : xMax(nx), yMax(ny), title(title)
  {
    for (int y = 0; y < yMax; y++)
    {
      line[y] = string(xMax, '.');
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
  void clear(string val = ".")
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
  void print()
  {
    system(COMMAND);

    cout << title << endl;
    for (int y = 0; y < yMax; y++)
    {
      cout << line[y] << endl;
    }
    cout << endl;
  }

  bool operator==(const Canvas &canvas)
  {
    if (canvas.xMax != this->xMax || canvas.yMax != this->yMax)
    {
      return false;
    }
    for (int y = 0; y < yMax; y++)
    {
      for (int x = 0; x < xMax; x++)
      {
        if (canvas.line[y][x] != this->line[y][x])
        {
          cout << canvas.line[y][x] << " != " << this->line[y][x] << endl;
          return false;
        }
      }
    }
    return true;
  }

  bool operator!=(const Canvas &canvas)
  {
    if (canvas.xMax != this->xMax || canvas.yMax != this->yMax)
    {
      return true;
    }
    for (int y = 0; y < yMax; y++)
    {
      for (int x = 0; x < xMax; x++)
      {
        if (canvas.line[y][x] != this->line[y][x])
        {
          cout << canvas.line[y][x] << " != " << this->line[y][x] << endl;
          return true;
        }
      }
    }
    return false;
  }
};

#endif
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
  void draw(int x, int y, string val)
  {
    if (x >= 0 && y >= 0 && x < xMax && y < yMax)
    {
      line[y].replace(x, 1, val);
    }
  }
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
#include "AnswerShapes.h"
#include <cstdio>

#define MAX_SIZE 200

using namespace Answer;

int main(int argc, char const *argv[])
{
  /**
   * Main.cpp : 과제 1-2 를 수행하기 위해 이 아래에 로직을 구현하시오
   * 
   * 동적으로 키보드의 입력을 받아서 해당하는 도형을 Canvas에 추가해서 그리거나 프로그램을 종료하는 프로그램
   * 
   * [입력 방식]
   * Line : l x1 y1 x2 y2<엔터>       ==> 예) l 10 10 20 20<엔터>
   * Rect : r x y width height<엔터>  ==> 예) r 10 20 40 20<엔터>
   * VLine : v x y length<엔터>       ==> 예) v 10 20 5<엔터>
   * HLine : h x y length<엔터>       ==> 예) v 10 20 5<엔터>
   * Square : s x y length<엔터>      ==> 예) s 10 20 5<엔터>
   * 종료 : q<엔터>
   * 
   * [참고]
   * 입력 및 입력 값 확인을 위해서 아래의 함수들을 적절히 조합하여 사용하면 유용하다.
   * 
   * gets : https://modoocode.com/45
   * char* gets(char* str); // 엔터를 입력 받을 때 까지 문자열을 입력 받음
   * 
   * sscanf : https://modoocode.com/67
   * int sscanf(const char* str, const char* format, ...); // 데이터를 특정 포멧으로 입력 받고 그 갯수를 반환
   * 
   **/
  Canvas myCanvas(32, 10, "  < My Graphic Editor >");
  Shape *list[100];
  int nShape = 0;

  while (true)
  {
    myCanvas.print();
    char str[MAX_SIZE], type;
    int v[4];
    printf("Input ==> ");
    fgets(str, MAX_SIZE, stdin);
    int ret = sscanf(str, "%c%d%d%d%d", &type, v, v + 1, v + 2, v + 3);

    if (type == 'l' && ret == 5)
      list[nShape++] = new Line(v[0], v[1], v[2], v[3]);
    else if (type == 'r' && ret == 5)
      list[nShape++] = new Rect(v[0], v[1], v[2], v[3]);
    else if (type == 'v' && ret == 4)
      list[nShape++] = new VLine(v[0], v[1], v[2]);
    else if (type == 'h' && ret == 4)
      list[nShape++] = new HLine(v[0], v[1], v[2]);
    else if (type == 's' && ret == 4)
      list[nShape++] = new Square(v[0], v[1], v[2]);
    else if (type == 'q')
      break;

    myCanvas.clear(".");
    for (int i = 0; i < nShape; i++)
      list[i]->draw(myCanvas);
  }
  for (int i = 0; i < nShape; i++)
    delete list[i];
  return 0;
}

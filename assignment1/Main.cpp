#include "MyShapes.h"

int main(int argc, char const *argv[])
{
  // 이 부분은 Canvas의 사용법을 알려주기 위한 예제이다.
  // 실제로 과제 수행시에는 삭제를 하도록 한다.
  Canvas canvas(48, 16);

  canvas.draw(28, 5, "O");
  canvas.draw(29, 5, "O");
  canvas.draw(30, 5, "O");
  canvas.draw(31, 5, "O");
  canvas.draw(31, 6, "O");
  canvas.draw(31, 7, "O");
  canvas.draw(32, 7, "O");
  canvas.draw(33, 7, "O");

  canvas.draw(11, 11, "*");
  canvas.draw(12, 11, "*");
  canvas.draw(13, 11, "*");
  canvas.draw(14, 11, "*");
  canvas.draw(11, 12, "*");
  canvas.draw(14, 12, "*");
  canvas.draw(11, 13, "*");
  canvas.draw(12, 13, "*");
  canvas.draw(13, 13, "*");
  canvas.draw(14, 13, "*");

  canvas.print();
  // 예제 코드 끝

  /**
   * Main.cpp : 과제 1-2 를 수행하기 위해 이 아래에 로직을 구현한다.
   * 
   * 동적으로 키보드의 입력을 받아서 해당하는 Canvas에 도형을 추가해서 그리거나 프로그램을 종료하는 프로그램을 구현한다.
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
  return 0;
}

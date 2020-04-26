#include "BaseShape.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
  cout << "- Move Test" << endl;
  Canvas canvas(20, 10);
  Shape shape1(0, 0), shape2(19, 9);

  canvas.draw(1, 1, "0");
  for (int i = 0; i < 10; i++)
  {
    canvas.clear();
    shape1.draw(canvas, "A");
    shape2.draw(canvas, "B");

    shape1.move(2, 1);
    shape2.move(-2, -1);
    canvas.print();
    sleep(1);
  }

  return 0;
}

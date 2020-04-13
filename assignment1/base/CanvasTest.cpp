#include "Canvas.h"

int main(int argc, char const *argv[])
{
  Canvas canvas(64, 16);
  canvas.clear(".");
  canvas.draw(18, 10, "O");
  canvas.draw(19, 10, "O");
  canvas.draw(20, 10, "O");
  canvas.draw(21, 10, "O");
  canvas.draw(21, 11, "O");
  canvas.draw(21, 12, "O");
  canvas.draw(22, 12, "O");
  canvas.draw(23, 12, "O");
  canvas.print();
  return 0;
}

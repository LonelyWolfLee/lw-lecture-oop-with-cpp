#include <stdio.h>

void CallCounter()
{
  static int count = 0;
  printf("함수가 %d 번 호출 되었습니다.\n", ++count);
}

int main(int argc, char const *argv[])
{
  for (int i = 0; i < 5; i++)
  {
    CallCounter();
  }

  return 0;
}

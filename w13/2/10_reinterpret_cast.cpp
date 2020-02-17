#include <stdio.h>

int main(int argc, char const *argv[])
{
  int num = 0x01020304;
  char *ptr = reinterpret_cast<char *>(&num);
  for (int i = 0; i < sizeof(num); i++)
  {
    printf("%d\n", static_cast<int>(*(ptr + i)));
  }
  return 0;
}

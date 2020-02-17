#include <stdio.h>

int main(int argc, char const *argv[])
{
  const char str[] = "hello world";
  const char *c1 = str;

  // c1[0] = 'a';   // 당연히 안됨
  // char *c2 = c1; // 상수형이 아니어서 이건 안됨

  char *c2 = const_cast<char *>(c1); // 이건 됨
  char *c3 = (char *)c1;             // 사실 이거도 됨

  c2[0] = 'a';
  c3[1] = 'a';

  printf("%s\n", str);
  printf("%s\n", c1);
  printf("%s\n", c2);
  printf("%s\n", c3);

  return 0;
}

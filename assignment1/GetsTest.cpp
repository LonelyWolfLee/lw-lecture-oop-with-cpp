#include <cstdio>

#define MAX_SIZE 10

int main(int argc, char const *argv[])
{
  char str[MAX_SIZE];

  // warning 이 생길 수 있음. 최근엔 추천하지 않는 방법 하지만 error는 아니므로 사용 가능합니다.
  gets(str);
  printf("string = %s\n", str);

  // 걱정이 되시는 분들은 이렇게 쓰시면 됩니다.
  fgets(str, MAX_SIZE, stdin);
  printf("string = %s\n", str);

  return 0;
}

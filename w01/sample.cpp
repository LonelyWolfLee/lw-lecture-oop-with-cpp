// #include <stdio.h>
#include <iostream>
// stdout, stdin

// Function Overloading 함수 오버로딩
// default value
// int GetNum(int a) {
//   return a + 10;
// }
int LandMoney(int money, int interest_rate, int bonus = 1000);
double GetNum(float a, int b);

int main(int argc, char const *argv[])
{
  int x = 10000, y = 7;
  float f;

  // LandMoney(2000);
  std::cout << LandMoney(x, y) << std::endl;
  // // scanf("%d %d",&x, &y);
  // std::cin >> x >> y;
  // // ㅇㅣ름을 위한 문자열
  // char name[20];
  // // printf("Hello\n");
  // std::cout << "Hello" << std::endl;
  // // scanf("%s", name);
  // std::cin >> name;
  // // printf("Hello %s\n", name);
  // std::cout << "Hello " << name << std::endl;
  return 0;
}

int LandMoney(int money, int interest_rate, int bonus) {
  return money + interest_rate + bonus;
}

double GetNum(float a, int b) {
  return a + b;
}
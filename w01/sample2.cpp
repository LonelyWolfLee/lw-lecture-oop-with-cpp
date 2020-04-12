#include <iostream>

#define SUM(x, y) \
  x+=2;           \
  x = ((x)+(y))

template <typename T>
inline T Sum(T x, T y) {
  x += 2;
  return x + y;
}

int main(int argc, char const *argv[])
{
  double d = 2.3;
  SUM(d, 3.1);
  std::cout << d << std::endl;
  // int n = 2.3;
  std::cout << Sum<double>(d, 3.1) << std::endl;
  std::cout << Sum<int>(10, 18) << std::endl;
  return 0;
}

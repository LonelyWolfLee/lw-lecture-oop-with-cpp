#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int& sum(int &n) {
  n++;
  return n;
}

int main(int argc, char const *argv[])
{
  int a = 10;
  
  const int& b = sum(a);
  // b += 9; // 상수는 변경 할 수 없음
  cout << a << endl;
  a++;
  cout << b << endl;

  return 0;
}

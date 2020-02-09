#include <iostream>

class Sample
{
private:
  int num;

public:
  Sample();
  Sample(int n);
  void ShowState();
};

using namespace std;

// 생성자도 함수다!
// 생성자에서 변수 초기화 가능
Sample::Sample()
{
  cout << "생성자 Sample() 호출" << endl;
  num = 10;
}

// 인자를 받을 수 있음.
// 함수 overloading 가능
Sample::Sample(int n)
{
  cout << "생성자 Sample(int n) 호출" << endl;
  num = n;
}

// 인자의 default 값을 지정 할 수 있음
// Sample::Sample(int n = 10)
// {
//   num = n;
// }

void Sample::ShowState()
{
  cout << "num = " << num << endl;
}

int main(int argc, char const *argv[])
{
  Sample sample1;    // Sample() 호출
  Sample sample2(5); // Sample(5) 호출

  return 0;
}

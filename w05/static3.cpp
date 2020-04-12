#include <iostream>

using namespace std;

class Example
{
public:
  static int id;

public:
  Example()
  {
    cout << "ID = " << ++id << endl;
  }
};
int Example::id = 0;

int main(int argc, char const *argv[])
{
  Example ex1, ex2;
  cout << "Current ID = " << Example::id << endl;
  cout << "ID = " << ex1.id << endl; // 나쁜 예
  cout << "ID = " << ex2.id << endl; // 나쁜 예
  return 0;
}

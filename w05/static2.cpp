#include <iostream>

using namespace std;

class Example
{
private:
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
  Example ex1, ex2, ex3;
  return 0;
}

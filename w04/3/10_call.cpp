#include <iostream>

using namespace std;
class Sample
{
private:
  int num;

public:
  Sample(int num) : num(num)
  {
    cout << "constructed with " << num << endl;
  }
  ~Sample()
  {
    cout << "destructed with " << num << endl;
  }
};

Sample fun()
{
  return Sample(30);
}

int main(int argc, char const *argv[])
{
  Sample a = Sample(10);
  a = Sample(20);
  const Sample &b = fun();
  cout << "end" << endl;
  return 0;
}

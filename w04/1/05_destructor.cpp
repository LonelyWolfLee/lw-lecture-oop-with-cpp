#include <iostream>

using namespace std;

class Sample
{
private:
  char *name;

public:
  Sample(int nameSize)
  {
    cout << "메모리 할당" << endl;
    name = new char[nameSize];
  }
  ~Sample()
  {
    cout << "메모리 해제" << endl;
    delete name;
  }
};

int main(int argc, char const *argv[])
{
  Sample sample(10);
  return 0;
}

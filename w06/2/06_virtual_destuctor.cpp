#include <iostream>

using namespace std;

class Parent
{
public:
  Parent()
  {
    cout << "I am Parent" << endl;
  }

  virtual ~Parent()
  {
    cout << "I am ~Parent" << endl;
  }
};

class Child : public Parent
{
private:
  char *name;

public:
  Child()
  {
    cout << "I am Child" << endl;
    name = new char[20];
  }
  virtual ~Child()
  {
    cout << "I am ~Child" << endl;
    delete[] name;
  }
};

int main(int argc, char const *argv[])
{
  Parent *p = new Child();
  delete p;
  return 0;
}

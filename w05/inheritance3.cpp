#include <iostream>

using namespace std;

class Parents
{
private: // 자신만 사용 가능
  int privateNum;

protected: // 자신과 자식(유도 클래스)만 사용 가능
  int protectedNum;

public: // 모든 외부에서 접근 가능
  int publicNum;
  Parents() : privateNum(10),
              protectedNum(20),
              publicNum(30) {}
};

class Child1 : public Parents
{
public:
  void ShowInfo()
  {
    cout << "Child1 : " << protectedNum << endl;
    cout << "Child1 : " << publicNum << endl;
  }
};

class Child2 : protected Parents
{
public:
  void ShowInfo()
  {
    cout << "Child2 : " << protectedNum << endl;
    cout << "Child2 : " << publicNum << endl;
  }
};

class Child3 : private Parents
{
public:
  void ShowInfo()
  {
    cout << "Child3 : " << protectedNum << endl;
    cout << "Child3 : " << publicNum << endl;
  }
};

class Child1Child : public Child1
{
public:
  void ShowInfo()
  {
    cout << "Child1Child : "
         << protectedNum << endl;
    cout << "Child1Child : "
         << publicNum << endl;
  }
};

class Child2Child : public Child2
{
public:
  void ShowInfo()
  {
    cout << "Child2Child : "
         << protectedNum << endl;
    cout << "Child2Child : "
         << publicNum << endl;
  }
};

class Child3Child : public Child3
{
public:
  void ShowInfo()
  {
  }
};

int main(int argc, char const *argv[])
{
  Child1 child1;
  Child2 child2;
  Child3 child3;
  child1.ShowInfo();
  child2.ShowInfo();
  child3.ShowInfo();
  cout << "Main : " << child1.publicNum << endl;

  Child1Child child1child;
  Child2Child child2child;
  Child3Child child3child;
  child1child.ShowInfo();
  child2child.ShowInfo();
  child3child.ShowInfo();
  cout << "Main : " << child1child.publicNum << endl;

  return 0;
}

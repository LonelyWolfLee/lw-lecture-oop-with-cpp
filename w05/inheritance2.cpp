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
  Parents(int pvt, int ptd, int pbc)
      : privateNum(pvt), protectedNum(ptd), publicNum(pbc) {}
  void ShowParentsInfo()
  {
    cout << "Parents : " << privateNum << endl;
    cout << "Parents : " << protectedNum << endl;
    cout << "Parents : " << publicNum << endl;
  }
};

class Child : public Parents
{
public:
  Child(int pvt, int ptd, int pbc) : Parents(pvt, ptd, pbc) {}
  void ShowChildInfo()
  {
    // cout << "Child : " << privateNum << endl; // 접근 불가
    cout << "Child : " << protectedNum << endl; // 상속에 의해 접근 가능
    cout << "Child : " << publicNum << endl;    // 접근 가능
  }
};

int main(int argc, char const *argv[])
{
  Parents parents(10, 20, 30);
  Child child(40, 50, 60);
  parents.ShowParentsInfo();
  child.ShowChildInfo();
  // cout << "Main : " << parents.protectedNum << endl; // 접근 불가
  cout << "Main : " << parents.publicNum << endl; // 접근 가능
  // cout << "Main : " << child.protectedNum << endl; // 접근 불가
  cout << "Main : " << child.publicNum << endl; // 접근 가능
  return 0;
}

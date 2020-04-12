#include <iostream>

using namespace std;

class Example
{
public:
  // const static 도 const 변수이므로
  // 선언과 함께 바로 초기화를 할 수 있다.
  const static int OFFICE_CODE = 1;
  const static int PARENT_CODE = 2;
  const static int TEACHER_CODE = 3;
};

int main(int argc, char const *argv[])
{
  // 객체를 생성하지 않아도 관련 변수를 사용 할 수 있다.
  cout << "Office Code = " << Example::OFFICE_CODE << endl;
  cout << "Parent Code = " << Example::PARENT_CODE << endl;
  cout << "Teacher Code = " << Example::TEACHER_CODE << endl;
  return 0;
}

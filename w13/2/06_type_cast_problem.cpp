#include <iostream>

using namespace std;

class Student
{
private:
  const char *name;

public:
  Student(const char *name) : name(name) {}
  void ShowStudent()
  {
    cout << "My name is " << name << endl;
  }
};

class UnivStudent : public Student
{
private:
  const char *major;

public:
  UnivStudent(const char *name, const char *major) : Student(name), major(major) {}
  void ShowMajor()
  {
    ShowStudent();
    cout << "My major is " << major << endl;
  }
};

int main(int argc, char const *argv[])
{
  // UnivStudent가 Student의 유도 클래스이므로 원래 되는 것.
  Student *pstud1 = new UnivStudent("YongHwan", "Engineering");
  // 원래 모습이 UnivStudent 이었으므로 캐스팅 자체는 문제 없음
  UnivStudent *puniv1 = (UnivStudent *)pstud1;
  puniv1->ShowMajor();

  cout << endl;

  Student *pstud2 = new Student("YongHwan");
  // Student 를 UnivStudent로 캐스팅 하는 것은 잘못된 변환
  // 하지만 컴파일 에러도 안나고 실제 동작도 한다...
  UnivStudent *puniv2 = (UnivStudent *)pstud2;
  puniv2->ShowMajor();
  return 0;
}

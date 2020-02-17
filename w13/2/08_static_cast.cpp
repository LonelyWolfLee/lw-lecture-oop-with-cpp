#include <iostream>
#include <stdio.h>

using namespace std;

class Student
{
private:
  const char *name;

public:
  Student(const char *name) : name(name) {}
  // virtual ~Student() {}
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
  // virtual ~UnivStudent() {}
  void ShowMajor()
  {
    ShowStudent();
    cout << "My major is " << major << endl;
  }
};

int main(int argc, char const *argv[])
{
  // Student *pstud1 = new UnivStudent("YongHwan", "Engineering");
  // UnivStudent *puniv1 = static_cast<UnivStudent *>(pstud1);
  // puniv1->ShowMajor();

  // Student *pstud2 = new Student("YongHwan");
  // UnivStudent *puniv2 = static_cast<UnivStudent *>(pstud2);
  // puniv2->ShowMajor();

  // UnivStudent *puniv3 = new UnivStudent("YongHwan", "Engineering");
  // Student *pstud3 = static_cast<Student *>(puniv3);
  // pstud3->ShowStudent();

  // int n = 10;
  // int *pn = &n;

  // // C언어 스타일 형 변환은 이게 됨
  // char *pc1 = (char *)pn;

  // // static_cast 에서는 이런 무리한 변환은 안됨
  // char *pc2 = static_cast<char *>(pn);

  // const int num = 20;
  // int *ptr = (int *)&num;
  // *ptr = 30;
  // printf("%p %p \n", &num, ptr);
  // printf("%d %d \n", num, *ptr);

  // static_cast는 절대 안됨. 컴파일 에러
  const int num = 20;
  int *ptr = static_cast<int *>(&num);

  return 0;
}

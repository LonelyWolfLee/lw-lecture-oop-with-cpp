#include <iostream>

class Person
{
};

class Student : public Person
{
};

class HighschoolStudent : public Student
{
};

class UniversityStudent : public Student
{
};

int main(int argc, char const *argv[])
{
  Student st;
  HighschoolStudent hs;
  UniversityStudent us;

  Person *pp;
  Student *ps;

  // 포인터 변수
  pp = &st;
  pp = &hs;
  pp = &us;
  ps = &hs;
  ps = &us;

  // 참조자
  Person &rp = hs;
  Student &rs = us;

  // 일반 변수로도 컴파일 에러 없이 가능은 한데,
  // 함수 사용에 대한 여러가지 룰이 깨지기 때문에
  // C++에서는 절대로 사용하지 말 것
  Student wrongStudent;
  Person wrongPerson = wrongStudent;

  return 0;
}

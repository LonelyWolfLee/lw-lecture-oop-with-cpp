#include <iostream>

using namespace std;

class Person
{
private:
  const char *name;

public:
  Person() : name("YongHwan") {}

  void SayName() const
  {
    cout << "My name is " << name << endl;
  }
};

class Student : public Person
{
public:
  int Age()
  {
    return 15;
  }
  void WhoAreYou()
  {
    SayName();
    cout << "I am " << Age() << " years old." << endl;
  }
};

class HighschoolStudent : public Student
{
public:
  // 함수 오버로딩!
  // Student의 Age를 재사용 하기 위해 Student::Age() 호출
  int Age()
  {
    return Student::Age() + 3;
  }
  // 오버라이딩 한 자신의 Age를 사용하기 위해 오버라이딩
  // WhoAreYou 를 오버라이딩 하지 않으면 Student의 함수가 호출됨
  void WhoAreYou()
  {
    SayName();
    cout << "I am " << Age() << " years old." << endl;
  }
};

class UniversityStudent : public Student
{
public:
  // 함수 오버로딩!
  // Student의 Age를 재사용 하기 위해 Student::Age() 호출
  int Age()
  {
    return Student::Age() + 5;
  }
  // WhoAreYou 를 오버라이딩 하지 않으면 Student의 함수가 호출됨
  // void WhoAreYou()
  // {
  //   SayName();
  //   cout << "I am" << Age() << "years old." << endl;
  // }
};

int main(int argc, char const *argv[])
{
  HighschoolStudent hs;
  UniversityStudent us;

  Student *s1 = &hs;
  Student &s2 = us;

  cout << "I am " << s1->Age() << " years old." << endl;
  cout << "I am " << s2.Age() << " years old." << endl;

  return 0;
}

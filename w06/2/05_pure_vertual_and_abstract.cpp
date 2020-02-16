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

// pure virtual function이 있으므로
// abstract class 이다
class Student : public Person
{
public:
  virtual int Age() const
  {
    return 15;
  }
  // Student로 사용할 일이 없는 경우
  // 필요한 함수를 pure virtual로 선언 할 수 있음
  virtual void WhoAreYou() const = 0;
};

class HighschoolStudent : public Student
{
public:
  virtual int Age() const
  {
    return Student::Age() + 3;
  }
  // 반드시 재정의 해야함
  // 재정의가 없으면 pure virtual로 인식함
  virtual void WhoAreYou() const
  {
    SayName();
    cout << "I am " << Age() << " years old." << endl;
  }
};

class UniversityStudent : public Student
{
public:
  virtual int Age() const
  {
    return Student::Age() + 5;
  }
  // 반드시 재정의 해야함
  // 재정의가 없으면 pure virtual로 인식함
  virtual void WhoAreYou() const
  {
    SayName();
    cout << "I am" << Age() << "years old." << endl;
  }
};

int main(int argc, char const *argv[])
{
  // Student st; // 추상클래스여서 객체 생성 불가능

  HighschoolStudent hs;
  UniversityStudent us;

  hs.WhoAreYou();
  us.WhoAreYou();

  return 0;
}

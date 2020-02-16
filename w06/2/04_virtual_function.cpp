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
  virtual int Age() const
  {
    return 15;
  }
  void WhoAreYou() const
  {
    SayName();
    cout << "I am " << Age() << " years old." << endl;
  }
};

class HighschoolStudent : public Student
{
public:
  virtual int Age() const
  {
    return Student::Age() + 3;
  }
  void WhoAreYou() const
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
  void WhoAreYou() const
  {
    SayName();
    cout << "I am" << Age() << "years old." << endl;
  }
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

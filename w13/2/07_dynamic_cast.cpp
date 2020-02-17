#include <iostream>

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
  Student *pstud1 = new UnivStudent("YongHwan", "Engineering");
  UnivStudent *puniv1 = dynamic_cast<UnivStudent *>(pstud1);
  puniv1->ShowMajor();

  Student *pstud2 = new Student("YongHwan");
  UnivStudent *puniv2 = dynamic_cast<UnivStudent *>(pstud2);
  puniv2->ShowMajor();

  UnivStudent *puniv3 = new UnivStudent("YongHwan", "Engineering");
  Student *pstud3 = dynamic_cast<Student *>(puniv3);
  pstud3->ShowStudent();
  return 0;
}

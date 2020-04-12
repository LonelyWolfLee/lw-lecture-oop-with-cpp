#include <iostream>
#include <cstring>

using namespace std;

class Animal
{
private:
  char name[20];
  int life;

public:
  char sound[20];
  Animal(const char *name, int life) : life(life)
  {
    strcpy(this->name, name);
  }
  void ShowInfo()
  {
    cout << "Name = " << name << endl;
    cout << "Life = " << life << endl;
  }

  void MakeSound()
  {
    cout << name << " said "
         << "'" << sound << "'" << endl;
  }
};

class Cat : public Animal
{
public:
  Cat(const char *name, int life)
      : Animal(name, life)
  {
    strcpy(this->sound, "Meow");
  }
};

class Dog : public Animal
{
public:
  Dog(const char *name, int life)
      : Animal(name, life)
  {
    strcpy(this->sound, "Woof woof");
  }
};

int main(int argc, char const *argv[])
{
  Animal animal("Animal", 10);
  Cat cat("Kitty", 15);
  Dog dog("Happy", 12);

  animal.ShowInfo();
  animal.MakeSound();
  cout << "----------------------" << endl;
  cat.ShowInfo();
  cat.MakeSound();
  cout << "----------------------" << endl;
  dog.ShowInfo();
  dog.MakeSound();

  return 0;
}
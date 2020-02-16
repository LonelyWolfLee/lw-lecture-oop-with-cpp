#include <iostream>

using namespace std;

class IntArrayClass
{
private:
  int *arr;
  int arrLen;

  IntArrayClass(const IntArrayClass &arrRef) {}
  IntArrayClass &operator=(const IntArrayClass &arrRef) {}

public:
  IntArrayClass(int len) : arrLen(len)
  {
    arr = new int[len];
  }

  int &operator[](int index)
  {
    if (index < 0 || index >= arrLen)
    {
      cout << "Out of bound" << endl;
      exit(1);
    }
    return arr[index];
  }

  int operator[](int index) const
  {
    if (index < 0 || index >= arrLen)
    {
      cout << "Out of bound" << endl;
      exit(1);
    }
    return arr[index];
  }

  ~IntArrayClass()
  {
    delete[] arr;
  }
};

int main(int argc, char const *argv[])
{
  IntArrayClass cls(5);
  for (int i = 0; i < 5; ++i)
  {
    cls[i] = (i + 1) * 11;
  }
  for (int i = 0; i < 6; ++i)
  {
    cout << cls[i] << endl;
  }
  return 0;
}

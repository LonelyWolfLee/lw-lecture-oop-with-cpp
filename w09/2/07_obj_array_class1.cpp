#include <iostream>

using namespace std;

class Sample
{
};

class SampleArrayClass
{
private:
  Sample *arr;
  int arrLen;

  SampleArrayClass(const SampleArrayClass &arrRef) {}
  SampleArrayClass &operator=(const SampleArrayClass &arrRef) {}

public:
  SampleArrayClass(int len) : arrLen(len)
  {
    arr = new Sample[len];
  }

  Sample &operator[](int index)
  {
    if (index < 0 || index >= arrLen)
    {
      cout << "Out of bound" << endl;
      exit(1);
    }
    return arr[index];
  }

  Sample operator[](int index) const
  {
    if (index < 0 || index >= arrLen)
    {
      cout << "Out of bound" << endl;
      exit(1);
    }
    return arr[index];
  }

  ~SampleArrayClass()
  {
    delete[] arr;
  }
};

int main(int argc, char const *argv[])
{
  SampleArrayClass cls(2);

  cls[0] = Sample();
  cls[1] = Sample();

  return 0;
}

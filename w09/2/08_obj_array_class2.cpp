#include <iostream>

using namespace std;

class Sample
{
};

typedef Sample *SAMPLE_PTR;

class SampleArrayClass
{
private:
  SAMPLE_PTR *arr;
  int arrLen;

  SampleArrayClass(const SampleArrayClass &arrRef) {}
  SampleArrayClass &operator=(const SampleArrayClass &arrRef) {}

public:
  SampleArrayClass(int len) : arrLen(len)
  {
    arr = new SAMPLE_PTR[len];
  }

  SAMPLE_PTR &operator[](int index)
  {
    if (index < 0 || index >= arrLen)
    {
      cout << "Out of bound" << endl;
      exit(1);
    }
    return arr[index];
  }

  SAMPLE_PTR operator[](int index) const
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

  cls[0] = new Sample();
  cls[1] = new Sample();

  delete cls[0];
  delete cls[1];

  return 0;
}

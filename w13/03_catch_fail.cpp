#include <iostream>

using namespace std;

double devide()
{
  double num1, num2;

  while (true)
  {
    try
    {
      cout << "Insert 2 numbers : ";
      cin >> num1 >> num2;
      if (num2 == 0)
        throw num2;

      break;
    }
    catch (const int divisor)
    {
      cout << "num2 cannot be " << divisor << ". Insert 2 numbers again" << endl;
    }
  }
  return num1 / num2;
}

int main(int argc, char const *argv[])
{
  double result = devide();
  cout << "Result = " << result << endl;
  return 0;
}

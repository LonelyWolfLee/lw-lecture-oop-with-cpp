#include <iostream>

using namespace std;

double devide()
{
  double num1, num2;

  while (true)
  {
    cout << "Insert 2 numbers : ";
    cin >> num1 >> num2;
    if (num2 == 0)
    {
      cout << "num2 cannot be 0. Insert 2 numbers again" << endl;
      continue;
    }

    break;
  }

  return num1 / num2;
}

int main(int argc, char const *argv[])
{
  double result = devide();
  cout << "Result = " << result << endl;
  return 0;
}

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "a_comp.cpp"
#include "b_comp.cpp"

using namespace std;
using namespace AComp;
// using namespace BComp;

namespace MyNameSpace {
  int age = 20;
}

namespace BCar = BComp::Car;

int main(int argc, char const *argv[])
{
  bool isOk = true;
  std::cout << "Hi " << MyNameSpace::age <<  std::endl;
  cout << "Very important number is " << GetImportantNum() <<  endl;
  return 0;
}

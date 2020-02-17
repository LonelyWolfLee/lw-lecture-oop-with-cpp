#include <iostream>

using namespace std;

void recordCard()
{
  char suit;
  int pips;

  cout << "Insert SUIT and PIPS for your card : ";
  cin >> suit >> pips;

  if (!(suit == 'S' || suit == 'H' || suit == 'C' || suit == 'D'))
  {
    throw suit;
  }
  if (pips < 1 || pips > 13)
  {
    throw pips;
  }

  cout << "Card recorded" << endl;
  cout << "Result = " << suit << " " << pips << endl;
}

int main(int argc, char const *argv[])
{
  try
  {
    recordCard();
  }
  catch (...)
  {
    cout << "Something wring" << endl;
    exit(1);
  }

  return 0;
}

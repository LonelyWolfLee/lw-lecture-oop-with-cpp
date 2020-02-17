#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
  char suit;
  int pips;

  try
  {
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
  }
  catch (const char s)
  {
    cout << "Invalid SUIT = " << s << endl;
    exit(1);
  }
  catch (const int p)
  {
    cout << "Invalid PIPS = " << p << endl;
    exit(1);
  }

  cout << "Result = " << suit << " " << pips << endl;
  return 0;
}

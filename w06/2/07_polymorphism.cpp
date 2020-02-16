#include <iostream>

using namespace std;

class Player
{
public:
  virtual void play() const = 0;
};

class APlayer : public Player
{
public:
  virtual void play() const
  {
    cout << "Play A" << endl;
  }
};

class BPlayer : public Player
{
public:
  virtual void play() const
  {
    cout << "Play B" << endl;
  }
};

class CPlayer : public Player
{
public:
  virtual void play() const
  {
    cout << "Play C" << endl;
  }
};

int main(int argc, char const *argv[])
{
  Player *player[3];
  player[0] = new APlayer();
  player[1] = new BPlayer();
  player[2] = new CPlayer();

  for (int i = 0; i < 3; i++)
  {
    player[i]->play();
  }

  return 0;
}

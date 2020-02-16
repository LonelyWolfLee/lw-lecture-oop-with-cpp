#include <iostream>

using namespace std;

class Player
{
public:
  virtual void play() const = 0;
  virtual ~Player()
  {
  }
};

class APlayer : public Player
{
public:
  virtual void play() const
  {
    cout << "Play A" << endl;
  }
  virtual ~APlayer()
  {
    cout << "Destroy A" << endl;
  }
};

class BPlayer : public Player
{
public:
  virtual void play() const
  {
    cout << "Play B" << endl;
  }
  virtual ~BPlayer()
  {
    cout << "Destroy B" << endl;
  }
};

class CPlayer : public Player
{
public:
  virtual void play() const
  {
    cout << "Play C" << endl;
  }
  virtual ~CPlayer()
  {
    cout << "Destroy C" << endl;
  }
};

int main(int argc, char const *argv[])
{
  Player *players[3];
  players[0] = new APlayer();
  players[1] = new BPlayer();
  players[2] = new CPlayer();

  for (int i = 0; i < 3; i++)
  {
    players[i]->play();
  }

  for (int i = 0; i < 3; i++)
  {
    delete players[i];
  }

  return 0;
}

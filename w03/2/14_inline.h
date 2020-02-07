#ifndef __CAR_H__
#define __CAR_H__

using namespace std;

namespace CAR_CONST
{
enum
{
  ID_LEN = 20,
  MAX_SPEED = 200,
  FUEL_STEP = 2,
  ACCEL_STEP = 10,
  BREAK_STEP = 10
};
}

class Car
{
private:
  char gamer_id[CAR_CONST::ID_LEN];
  int fuel_gauge;
  int current_speed;

public:
  void init_members(const char *id, int fuel);
  void show_car_state();
  void accel();
  void push_break();
};

inline void Car::init_members(const char *id, int fuel)
{
  strcpy(gamer_id, id);
  fuel_gauge = fuel;
  current_speed = 0;
}

inline void Car::show_car_state()
{
  cout << "게이머 ID: " << gamer_id << endl;
  cout << "현재 연료: " << fuel_gauge << endl;
  cout << "현재 속도: " << current_speed << endl;
}

#endif

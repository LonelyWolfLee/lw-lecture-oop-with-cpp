#include <iostream>

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
  char gamer_id[CAR_CONST::ID_LEN];
  int fuel_gauge;
  int current_speed;

  void show_car_state();
  void accel();
  void push_break();
};

void Car::show_car_state()
{
  cout << "게이머 ID: " << gamer_id << endl;
  cout << "현재 연료: " << fuel_gauge << endl;
  cout << "현재 속도: " << current_speed << endl;
}

void Car::accel()
{
  if (fuel_gauge <= 0)
    return;
  else
    fuel_gauge -= CAR_CONST::FUEL_STEP;

  if (current_speed + CAR_CONST::ACCEL_STEP >= CAR_CONST::MAX_SPEED)
  {
    current_speed = CAR_CONST::MAX_SPEED;
    return;
  }
  current_speed += CAR_CONST::ACCEL_STEP;
}

void Car::push_break()
{
  if (current_speed < CAR_CONST::BREAK_STEP)
  {
    current_speed = 0;
    return;
  }
  current_speed -= CAR_CONST::BREAK_STEP;
}

int main()
{
  Car car1 = {"no 1", 100, 0};
  car1.accel();
  car1.accel();
  car1.show_car_state();
  car1.push_break();
  car1.show_car_state();

  return 0;
}

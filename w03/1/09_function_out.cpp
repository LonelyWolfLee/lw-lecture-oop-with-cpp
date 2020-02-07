#include <iostream>

using namespace std;

struct Car
{
  enum
  {
    ID_LEN = 20,
    MAX_SPEED = 200,
    FUEL_STEP = 2,
    ACCEL_STEP = 10,
    BREAK_STEP = 10
  };
  char gamer_id[ID_LEN];
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
    fuel_gauge -= FUEL_STEP;

  if (current_speed + ACCEL_STEP >= MAX_SPEED)
  {
    current_speed = MAX_SPEED;
    return;
  }
  current_speed += ACCEL_STEP;
}

void Car::push_break()
{
  if (current_speed < BREAK_STEP)
  {
    current_speed = 0;
    return;
  }
  current_speed -= BREAK_STEP;
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

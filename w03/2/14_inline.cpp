#include <iostream>
#include <cstring>
#include "14_inline.h"

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
  Car car1;
  car1.init_members("no 1", 100);
  car1.accel();
  car1.accel();
  car1.show_car_state();
  car1.push_break();
  car1.show_car_state();

  return 0;
}

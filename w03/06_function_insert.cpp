#include <iostream>

using namespace std;

struct Car
{
  char gamer_id[20];
  int fuel_gauge;
  int current_speed;

  void show_car_state()
  {
    cout << "게이머 ID: " << gamer_id << endl;
    cout << "현재 연료: " << fuel_gauge << endl;
    cout << "현재 속도: " << current_speed << endl;
  }

  void accel()
  {
    if (fuel_gauge <= 0)
      return;
    else
      fuel_gauge -= 2;

    if (current_speed + 10 >= 200)
    {
      current_speed = 200;
      return;
    }
    current_speed += 10;
  }
  void push_break()
  {
    if (current_speed < 10)
    {
      current_speed = 0;
      return;
    }
    current_speed -= 10;
  }
};

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

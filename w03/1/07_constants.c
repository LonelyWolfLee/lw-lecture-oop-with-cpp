#include <stdio.h>

#define ID_LEN 20
#define MAX_SPEED 200
#define FUEL_STEP 2
#define ACCEL_STEP 10
#define BREAK_STEP 10

struct Car
{
  char gamer_id[ID_LEN];
  int fuel_gauge;
  int current_speed;

  void (*show_car_state)(const struct Car *);
  void (*accel)(struct Car *);
  void (*push_break)(struct Car *);
};
typedef struct Car Car;

void show_car_state(const Car *car)
{
  printf("게이머 ID: %s\n", car->gamer_id);
  printf("현재 연료: %d\n", car->fuel_gauge);
  printf("현재 속도: %d\n", car->current_speed);
}

void accel(Car *car)
{
  if (car->fuel_gauge <= 0)
    return;
  else
    car->fuel_gauge -= FUEL_STEP;

  if (car->current_speed + ACCEL_STEP >= MAX_SPEED)
  {
    car->current_speed = MAX_SPEED;
    return;
  }

  car->current_speed += ACCEL_STEP;
}
void push_break(Car *car)
{
  if (car->current_speed < BREAK_STEP)
  {
    car->current_speed = 0;
    return;
  }

  car->current_speed -= BREAK_STEP;
}

int main()
{
  Car car1 = {
      "no 1", 100, 0,
      show_car_state,
      accel,
      push_break};
  car1.accel(&car1);
  car1.accel(&car1);
  car1.show_car_state(&car1);
  car1.push_break(&car1);
  car1.show_car_state(&car1);

  return 0;
}

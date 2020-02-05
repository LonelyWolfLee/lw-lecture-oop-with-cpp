#include <stdio.h>

struct Car {
  char gamer_id[20];
  int fuel_gauge;
  int current_speed;
};
typedef struct Car Car;

void show_car_state(const Car* car) {
  printf("게이머 ID: %s\n", car->gamer_id);
  printf("현재 연료: %d\n", car->fuel_gauge);
  printf("현재 속도: %d\n", car->current_speed);
}

void accel(Car* car) {
  if(car->fuel_gauge <= 0)
    return;
  else
    car->fuel_gauge -= 2;

  if(car->current_speed + 10 >= 200) {
    car->current_speed = 200;
    return;
  }

  car->current_speed += 10;
}
void push_break(Car* car) {
  if(car->current_speed < 10) {
    car->current_speed = 0;
    return;
  }

  car->current_speed -= 10;
}

int main() {
  // struct Car car1 = {"no 1", 100, 0};
  Car car1 = {"no 1", 100, 0};
  accel(&car1);
	accel(&car1);
	show_car_state(&car1);
	push_break(&car1);
	show_car_state(&car1);

  return 0;
}


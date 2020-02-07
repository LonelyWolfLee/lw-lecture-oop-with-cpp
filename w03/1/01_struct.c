#include <stdio.h>

struct Car
{
  char gamer_id[20];
  int fuel_gauge;
  int current_speed;
};
typedef struct Car Car;

int main()
{
  // struct Car car1 = {"no 1", 100, 0};
  Car car1 = {"no 1", 100, 0};

  return 0;
}

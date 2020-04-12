#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
  int *a, *b;
  // a = (int*) malloc(sizeof(int) * 10);
  // b = (int*)malloc(sizeof(int));
  b = new int;
  a = new int[10];


  // free(a);
  // free(b);
  delete b;
  delete[] a;

  return 0;
}



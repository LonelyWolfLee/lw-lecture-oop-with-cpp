#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(int argc, char const *argv[])
{
    int *a, *b;

    // a = (int*) malloc(sizeof(int));
    // b = (int*)malloc(sizeof(int) * 10);
    a = new int;
    b = new int[10];

    // free(a);
    // free(b);
    delete a;
    delete[] b;

    return 0;
}

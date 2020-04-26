#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x, y;
    char name[20];

    scanf("%d %d", &x, &y);
    printf("%d %d\n", x, y);

    printf("Hello\n");

    scanf("%s", name);
    printf("Hello %s\n", name);

    return 0;
}

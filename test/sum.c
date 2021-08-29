#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[])
{
    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    int sum = x + y;
    printf("%i + %i = %i\n", x, y, sum);
}
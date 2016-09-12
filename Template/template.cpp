#include <iostream>
#include <stdio.h>
#define INPUT "%d"

using namespace std;

int main()
{
    int n = 0;
    while (scanf(INPUT, &n) != EOF)
    {
        printf("Detected: %d\n", n);
    }
    return 0;
}
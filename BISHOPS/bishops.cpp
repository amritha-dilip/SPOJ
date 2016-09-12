#include <iostream>
#include <stdio.h>
#define ULL unsigned long long int

using namespace std;

ULL bishops(ULL n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else if (n % 2 == 0)
    {
        ULL k = n / 2;
        return k * (k + 1);
    }
    else
    {
        ULL k = (n + 1) / 2;
        return k * k;
    }
}

int main()
{
    ULL n = 0;
    while (scanf("%llu", &n) != EOF)
    {
        printf("%llu\n", bishops(n));
    }
    return 0;
}
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main()
{
    int n, i, j, k;
    cin >>n;
    long long cnt = 0;
    for (i = 1; i < n; i++)
    {
        for (j = i + 1; j < n; j ++)
        {
            k = sqrt(0.0 + i * i + j * j);
            if (k <= 0.0 + n && k * k == i * i + j * j){ cnt++; /*printf("%d %d %d\n", i, j, k);*/}
        }
    }
    printf("%I64d\n", cnt);
    return 0;
}

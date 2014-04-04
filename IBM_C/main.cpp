#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 20
int n = 6, a[100] = {3,5,7,9,11,13};

void init()
{
    int i, j, k;
    if (1)
    {
        n = 5;
        for (int i = 0; i < n; i++)
        {
            a[i] = i + 1;
        }
    }
}

int option[100];
#define YUZHI (long long)2500

void found()
{
    char s[4] = {' ', '+', '-'};
    int i;
    for (i = 0; i < n - 1; i++)
    {
        //cout << a[i] << s[option[i + 1]];
        printf("%d%c", a[i], s[option[i + 1]]);
    }
    printf("%d;\n", a[n - 1]);
    //cout << a[n - 1] << ";";
}

void dfs(long long leftt, long long rightt, int op, int step, int usedS, int con)
{
    if (step == n)
    {
        if (op == 1 && leftt + rightt == 0)
            found();
        if (op == 2 && leftt == rightt)
            found();
        return;
    }
    if (usedS > (n + 1) / 2) return;
    if (con > 5) return;
    if (leftt > YUZHI || rightt > YUZHI) return;

    long long fac = (a[step] >= 10) ? 100 : 10;
    if (a[step] >= 100) fac = 1000;
    if (a[step] >= 1000) fac = 10000;
    if (a[step] >= 10000) fac = 100000;

    option[step] = 0;
    if (op == 1) dfs (leftt, fac * rightt + a[step], op, step + 1, usedS + 1, con + 1);
    else         dfs (leftt, fac * rightt + a[step], op, step + 1, usedS + 1, con + 1);

    option[step] = 1;
    if (op == 1) dfs (leftt + rightt, a[step], 1, step + 1, usedS, 0);
    else         dfs (leftt - rightt, a[step], 1, step + 1, usedS, 0);

    option[step] = 2;
    if (op == 1) dfs (leftt + rightt, a[step], 2, step + 1, usedS, 0);
    else         dfs (leftt - rightt, a[step], 2, step + 1, usedS, 0);
}

int main()
{
    freopen("3.txt", "w", stdout);
    init();
    dfs(0, a[0], 1, 1, 0, 0);
    return 0;
}

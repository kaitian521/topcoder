#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <string.h>
#include <set>
using namespace std;

int up = 0;
bool dp[1000];

bool check(int x)
{
    char s[100];
    sprintf(s, "%d", x);
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
    {
        if (s[i] != s[len - i - 1]) return 0;
    }
    return 1;
}
void init()
{
    int i;
    for (i = 1; i <= 1000; i++)
    {
        int tt = (int)sqrt(i);
        if (check(i) && check(tt) && tt * tt == i)
        {
            dp[i] = 1;
        }
    }
}
int main()
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int T;
    cin >> T;
    int n, m, id = 1, i;
    init();
    while(T--)
    {
        cin >>n >>m;
        int cnt  = 0;
        for (i = n; i <= m; i++)
        {
            if (dp[i]) cnt ++;
        }
        printf("Case #%d: %d\n", id++, cnt);
    }
    return 0;
}

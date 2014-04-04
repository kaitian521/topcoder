#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <list>
using namespace std;
#define LINE 10000
#define N 1000
bool dp[N][N];
int strong[N][N];
int top[N];
int share[N][N];
int a[N], b[N], c[N];
int n;
struct node
{
    int x, y;
    node(){x = 0; y = 0;}
    node(int xx, int yy) {x = xx; y = yy;}
};
list<node>l;
void init()
{
    freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int i, j, k;
    n = 0;
    while(scanf("%d,%d,%d;", &i, &j, &k) != EOF)
    {
        //cout << i << "\t" <<j << "\t" << k << endl;
        if (i > n) n = i;
        if (j > n) n = j;
        share[i][j] = k;
    }
}
int last[N];
int stack[LINE];
bool solve[LINE];
int cnt = 0;
int loop = 0;
void f()
{
    int i, j, k;
    bool flag = true;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (k = 1; k <= n; k++)
            {
                if (share[i][j] > 50 && share[j][k] > 50) share[i][k] = 100;
            }
        }
    }
    while (flag)
    {
        loop += 1;
        flag = 0;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (i == j)continue;
                if (dp[i][j]) continue;
                if (share[i][j] > 50)
                {
                    dp[i][j] = 1;
                    flag = 1;
                    cnt ++;
                    strong[i][top[i]++] = j;
                    continue;
                }
                int count = 0;
                for (k = 0; k < top[i]; k ++)
                {
                    if (strong[i][k] == i || strong[i][k] == j) continue;
                    count += share[strong[i][k]][j];
                    if (count > 50) break;
                }
                count += share[i][j];
                if (count > 50)
                {
                    dp[i][j] = 1;
                    cnt ++;
                    flag = true;
                    strong[i][top[i]++] = j;
                }
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j) continue;
            if (!dp[i][j]) continue;
            //cout <<i <<"\t"<<j << endl;
            //printf("%d,%d;", i, j);
        }
    }
    cout << loop << endl;
}

int main()
{
    init();
    f();
    return 0;
}

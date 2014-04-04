#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#define MOD (long long)1000000007L
#define LL long long
using namespace std;

vector<int>vv;
int n;
bool intersect(int state, int x, int y)
{
    if (x == y) return false;
    if (x > y) {swap(x, y);}
    bool flag1 = false, flag2 = false;
    for (int i = 0; i < n; i++)
    {
        if (0x1 & state >> i)
        {
            if (i + 1 == x || i + 1 == y) continue;
            if (i + 1 > x && i + 1 < y) flag1 = true;
            else flag2 = true;
        }
    }
    return flag1 && flag2;
}
long long dp[(1 << 18) + 10][18];
long long dfs(int state, int p)
{
    if (dp[state][p] != -1) return dp[state][p];
    if (state == (1 << n) - 1)
    {
        if (intersect(state, p, vv[0])) return 1;
        return 0;
    }
    dp[state][p] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (state & (1 << (i - 1))) continue;
        if (intersect(state, p, i))
        {
            dp[state][p] += dfs(state | (1 << (i - 1)), i);
        }
    }
    return dp[state][p];
}
class PolygonTraversal2
{
public:
    long long count(int _n,vector<int>points)
    {
        memset(dp, -1, sizeof(dp));
        int i;
        int state = 0;
        n = _n;
        for (i = 0; i < points.size(); i++)
        {
            state |= (1 << (points[i] - 1));
        }
        return dfs(state, points[points.size() - 1]);
    }
};
int n;
bool intersect(int state, int x, int y)
{
    if (x == y) return false;
    if (x > y) {swap(x, y);}
    bool flag1 = false, flag2 = false;
    for (int i = 0; i < n; i++)
    {
        if (0x1 & state >> i)
        {
            if (i + 1 == x || i + 1 == y) continue;
            if (i + 1 > x && i + 1 < y) flag1 = true;
            else flag2 = true;
        }
    }
    return flag1 && flag2;
}
long long dp[(1 << 18) + 10][18];
long long dfs(int state, int p)
{
    if (dp[state][p] != -1) return dp[state][p];
    if (state == (1 << n) - 1)
    {
        if (intersect(state, p, vv[0])) return 1;
        return 0;
    }
    dp[state][p] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (state & (1 << (i - 1))) continue;
        if (intersect(state, p, i))
        {
            dp[state][p] += dfs(state | (1 << (i - 1)), i);
        }
    }
    return dp[state][p];
}
class PolygonTraversal2
{
public:
    long long count(int _n,vector<int>points)
    {
        memset(dp, -1, sizeof(dp));
        int i;
        int state = 0;
        n = _n;
        vv = points;
        for (i = 0; i < points.size(); i++)
        {
            state |= (1 << (points[i] - 1));
        }
        return dfs(state, points[points.size() - 1]);
    }
};
int main()
{
    int a[] = {1,7,18};
    vector<int>vvv(a, a + 3);
    PolygonTraversal2 P;
    printf("%lld\n", P.count(18, vvv));
    return 0;
}

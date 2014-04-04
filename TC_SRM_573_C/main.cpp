#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <math.h>
#define MOD (long long)1000000007L
using namespace std;
#define N 500
#define CHANGE 60
int mm[N][N];
int m = 0;
long long ans = 0;
bool visit[N][N];
long long dp[200][200][100] = {-1};
vector<int>x, y;
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
struct node
{
    int px, py, step;
    node(){px = 0; py = 0;step = 0;}
    node(int _px, int _py){px = _px; py = _py; step = 0;}
    node(int _px, int _py, int _step){px = _px; py = _py; step = _step;}
};
node tt;
int n;
class WolfPackDivTwo
{
public:
    long long f(int px, int py, int _m)
    {
        if (dp[px+CHANGE][py+CHANGE][_m] != -1) return dp[px+CHANGE][py+CHANGE][_m];
        long long res = 0;
        if (_m == 0)
        {
            dp[px+CHANGE][py+CHANGE][_m] = 1;
            return 1;
        }
        for (int i = 0; i < 4; i ++)
        {
            int xxxx = px + dir[i][0];
            int yyyy = py + dir[i][1];
            if (abs(xxxx) + abs(yyyy) <= (_m - 1) )
            {
                res = res + f(xxxx, yyyy, _m - 1);
                res %= MOD;
            }
        }
        return (dp[px + CHANGE][py + CHANGE][_m] = res);
    }
    bool in(int xx, int yy)
    {
        return visit[xx + CHANGE][yy + CHANGE];
    }
    void sett(int xx, int yy)
    {
        visit[xx + CHANGE][yy + CHANGE] = 1;
    }
    void init()
    {
        int i, j, k;
        for(i = 0; i < n; i++)
        {
            queue<node>q;
            memset (visit, 0, sizeof(visit));
            q.push(node(x[i], y[i]));
            sett(x[i], y[i]);
            while(!q.empty())
            {
                tt = q.front(), q.pop();
                if (tt.step >= m) continue;
                for(j = 0; j < 4; j++)
                {
                    int xxx = tt.px + dir[j][0];
                    int yyy = tt.py + dir[j][1];
                    if (in(xxx, yyy)) continue;
                    sett(xxx, yyy);
                    q.push(node(xxx, yyy, tt.step + 1));
                }
            }
            for (j = 0; j < 400; j++)
            {
                for (k = 0; k < 400; k++)
                {
                    mm[j][k] += visit[j][k];
                }
            }
        }
        for (j = 0; j < 400; j++)
        {
            for (k = 0; k < 400; k++)
            {
                if (mm[j][k] == n) cout << j - CHANGE << "\t" << k - CHANGE << endl;
            }
        }
    }
    int calc(vector <int> _x, vector <int> _y, int _m)
    {
        memset(dp, -1, sizeof(dp));
        x = _x;
        y = _y;
        m = _m;
        n = x.size();
        init();
        int i, j, k;
        for (i = 0; i < 400; i++)
        {
            for (j = 0; j < 400; j++)
            {
                long long tmp = 1;
                if (mm[i][j] < n) continue;
                for (k = 0; k < n; k++)
                {
                    int fx = abs(i - CHANGE - x[k]), fy = abs(j - CHANGE - y[k]);
                    tmp *= f(fx, fy, m);
                    tmp %= MOD;
                }
                ans += tmp;
                ans %= MOD;
            }
        }
        return (int)(ans % MOD);
    }
};
int main()
{
    m = 2; n = 3;
    WolfPackDivTwo tttt;
    int a[10] = {0,2,4};
    int b[10] = {0,0,0};
    vector<int>v1 (a, a + n);
    vector<int>v2 (b, b + n);
    cout << tttt.calc(v1, v2, m) << endl;
    return 0;
}

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define INT_MAX LONG_MAX
//#define INT_MAX 1000000000
#include <vector>
using namespace std;
#define N 100
#define MIN(x,y) (x<y)?(x):(y)
unsigned long long dp[N][3][(1 << 3)];
vector<int>_red, _green, _blue;
int get(int i, int j)
{
    int sum = _red[i] + _green[i] + _blue[i];
    if (i == 0) return sum - _red[i];
    if (i == 1) return sum - _green[i];
    return sum - _blue[i];
}
class BallsSeparating
{
public:
    int minOperations(vector <int> red, vector <int> green, vector <int> blue)
    {
        _red = red;
        _green = green;
        _blue = blue;
        int i, j, k;
        int n = red.size();
        if (n <= 2) return -1;
        memset(dp, -1, sizeof(dp));
        for (i = 0; i <= 2; i++) dp[0][i][0] = 0;
        for (i = 1; i <= n; i++)
        {
            for (k = 0; k < 8; k++)
            {
                for (j = 0; j < 3; j++)
                {
                    for (int t = 0; t < 3; t++)
                    {
                        dp[i][j][k | (1 << j)] = MIN(dp[i][j][k | (1 << j)], dp[i - 1][t][k]);
                    }
                    if (((long long)dp[i][j][k | (1 << j)]) == -1) continue;
                    dp[i][j][k | (1 << j)] += get(i-1, j);
                    cout << i << " " << j << " " << (k | (1 << j)) << " " << (int)dp[i][j][k | (1 << j)] << endl;
                }
            }
        }
        int ans = INT_MAX;
        for (i = 0; i < 3; i++) ans = MIN(ans, dp[n][i][7]);
        return (ans == INT_MAX) ? -1 : ans;
    }
};
int main()
{
    int a[] = {1,1,1};
    vector<int>r(a, a + 3);
    vector<int>g(a, a + 3);
    vector<int>b(a, a + 3);
    BallsSeparating x;
    cout << x.minOperations(r, g, b) << endl;
    return 0;
}

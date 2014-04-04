#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;
#define N (50 + 2)
long long dp[N + 5][N + 5][N * N / 2 + 1100];
long long mod = 1000000007LL;
long long n;
int m;
long long ans;
class DistinctRemainders {
public:
	int howMany(long long, int);
};

long long dfs()
{
    int i, j, k, q;
    dp[0][0][0] = 1;
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= i; j++)
        {
            for (k = i - 1; k <= i * (i - 1) / 2; k++)
            {
                for (q = std::min(i - 1, j - 1); q < i; q++)
                {
                    dp[i][j][k] += dp[q][j - 1][k - i + 1];
                    dp[i][j][k] %= mod;
                }
            }
        }
    }

    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= i; j++)
        {
            for (k = i - 1; k <= i * (i - 1) / 2; k++)
            {
                if ( k % m != n % m || k > n) continue;
                if (dp[i][j][k] == 0) continue;
                //cout << i <<"\t" << j << "\t" << k << "\t" << (int)dp[i][j][k] << " -- > ";
                long long tmp = (n - k) / m;
                tmp %= mod;
                //printf("tmp = %d\n", (int)tmp);
                long long tt = dp[i][j][k] * j;
                tt %= mod;
                for (q = 1; q < j; q++)
                {
                    tt *= (tmp + j - q);
                    tt %= mod;
                }
                //cout << tt << endl;
                ans += tt;
                ans %= mod;
            }
        }
    }
}

int DistinctRemainders::howMany(long long _N, int _M) {
    n = _N, m = _M;
	memset(dp, 0, sizeof(dp));
    ans = 0;
	dfs();
	return (int)ans;
}

int main()
{
    DistinctRemainders x;
    cout << x.howMany((long long)1000000000000000000LL, 50) << endl;
    return 0;
}

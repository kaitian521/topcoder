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
#define N 50 + 1
long long dp[N + 5][N + 5][N * N / 2 + 10];
long long n;
int m;
long long ans;
class DistinctRemainders {
public:
	int howMany(long long, int);
};

long long dfs()
{
    int i, j, k;
    dp[0][0][0] = 1;
    for (i = 1; i <= m; i++)
    {
        for (j = 0; j <= i + 1; j++)
        {
            for (k = 0; k <= m * (m + 1) / 2; k++)
            {
                if (j == 0) {dp[i][j][k] = 0; continue;}
                dp[i][j][k] += dp[i - 1][j][k];
                if (k >= i - 1) dp[i][j][k] += dp[i - 1][j - 1][k - i + 1];
            }
        }
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 0; j <= i + 1; j++)
        {
            for (k = 0; k <= i * (i + 1) / 2; k++)
            {
                cout << i <<"\t" << j << "\t" << k << "\t" << (int)dp[i][j][k] << endl;
            }
        }
    }
}
/*
# 下载
wget http://pypi.python.org/packages/source/l/lxml/lxml-3.0.1.tar.gz#md5=0f2b1a063ab3b6b0944cbc4a9a85dcfa
tar -xzvf lxml-3.0.1.tar.gz
cd lxml-3.0.1
# 解压缩、编译
/home/liheyuan/env/bin/python ./setup.py build --with-xslt-config=/home/liheyuan/env/bin/xslt-config
/home/liheyuan/env/bin/python ./setup.py install

vim ~/.bashrc
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/liheyuan/env/lib
*/
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
    x.howMany(2, 2);
    return 0;
}

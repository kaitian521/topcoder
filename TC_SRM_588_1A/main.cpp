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
using namespace std;
const int N = 13;
int dp[N][(1 << N) + 10];
int n;
class KeyDungeonDiv1 {
public:
	int maxKeys(vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>);
};
vector<int>doorR, doorG, roomR, roomG, roomW;

int dfs(int id, int state, int red, int green, int white)
{
    int &ret = dp[id][state];
    if (ret != -1) return ret; ret = 0;
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        if ( (state >> i) & i) continue;
        int queR = 0, queG = 0;
        if (red < doorR) queR = red - _doorR;
        if (green < doorG) queG = green - doorG;
        if (queR + queR < white) continue;
        int x, y, z;
        if (queR > 0) queR = 0;
        if (queG > 0)
        ret = std::max(ret, i, state | (1 << i), )
    }
}

int KeyDungeonDiv1::maxKeys(vector <int> _doorR, vector <int> _doorG, \
                            vector <int> _roomR, vector <int> _roomG, vector <int> _roomW, \
                            vector <int> _keys)
{
    doorR = _doorR; doorG = _doorG;
    roomR = _roomR; roomG = _roomG; roomW = _roomW;
    n = _dooR.size();
    int i, j, k, maxx = _keys[0] + _keys[1] + _keys[2];
    for (i = 0; i < n; i++)
    {
        memset(dp, -1, sizeof(dp));
        dfs(i, 1 << i, _keys[0], _keys[1], _keys[2]);
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < (1 << n); k++)
            {
                if (dp[j][k] != -1)
                {
                    maxx = std::max(maxx, dp[j][k]);
                }
            }
        }
    }
    return maxx;
}
//Powered by [KawigiEdit] 2.0!

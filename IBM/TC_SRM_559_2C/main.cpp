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
using namespace std;
const int N = 55;
bool used[N][N];
int heng[N][N], lie[N][N];
int m, n;
vector<string>v;
class ToyTrain {
public:
	int getMinCost(vector <string>);
};

int process(int startx, int starty)
{
    int i, j, k;
    int dir = 0, will = 1 - v[startx][starty] + 'A';
    used[startx][starty] = 1;
    nowx =  startx, nowy = starty;
    while (1)
    {
        if (dir == 0)
        {

        }
        else if (dir == 1)
        {

        }
    }
    return 0;
}

int ToyTrain::getMinCost(vector <string> field) {
	memset(used, 0, sizeof(used));
	memset(heng, -1, sizeof(heng));
	memset(lie, -1, sizeof(lie));
	m = field.size(); n = field[0].size();
	v = field;
	int cntA = 0, cntB = 0, cnt = 0;
	int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i][j] == 'A') cntA += 1;
            else if (v[i][j] == 'B') cntB = 1;
        }
    }
    if (cntA + cntB == 0 || cntA != cntB) return 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (heng[i][j] == -1)
            {
                bool flag = 0;
                for (k = j + 1; k < n; k++)
                {
                    if (heng[i][k] == -1)
                    {
                        flag = 1;
                        heng[i][j] = k;
                        heng[i][k] = j;
                    }
                }
                if (!flag) return -1;
            }
            if (lie[i][j] == -1)
            {
                bool flag = 0;
                for (k = i + 1; k < m; k++)
                {
                    if (lie[k][j] == -1)
                    {
                        flag = 1;
                        lie[i][j] = k;
                        lie[k][j] = i;
                    }
                }
                if (!flag) return -1;
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (!used[i][j] && (v[i][j] == 'A' || v[i][j] == 'B'))
            {
                int ret = process(i, j);
                if (ret == -1) return -1;
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i][j] == 'S' && used[i][j] == 0) return -1;
            if (used[i][j] && v[i][j] >= '0' && v[i][j] <= '9') cnt += v[i][j] - '0';
        }
    }
    return cnt;
}
//Powered by [KawigiEdit] 2.0!

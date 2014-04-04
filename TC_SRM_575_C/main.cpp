#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <math.h>
using namespace std;

#define N 60
int dp[N][1<<5][1<<5];
int mask[N];
int m, n;
vector <string> board;
bool in(int x, int y)
{
    return x >= 0 && x < m && y >= 0 && y < n;
}
int dfs(int pos, int mask1, int mask2)
{
    if (pos >= n - 1) return 0;
    int &ret = dp[pos][mask1][mask2];
    if (ret != -1) return ret;
    ret = 0;
    int i, j, k;
    for (i = 0; i < m; i++)
    {
        if ( (i + pos) % 2 == 0 && !(mask1 & (1 << i)) && !(mask2 & (1 << i)) )
        {
            if (in(i - 1, pos) && !(mask1 & (1 <<(i - 1))) ) ret = std::max(ret, 1 + dfs(pos, mask1 | (1 << i) | (1 <<(i - 1) ), mask2 | (1 << i) ));
            if (in(i + 1, pos) && !(mask1 & (1 <<(i + 1))) ) ret = std::max(ret, 1 + dfs(pos, mask1 | (1 << i) | (1 <<(i + 1) ), mask2 | (1 << i) ));
        }
        if ( (i + pos + 1) % 2 == 0 && !(mask1 & (1 << i)) && !(mask2 & (1 << i)) )
        {
            if (in(i - 1, pos) && !(mask2 & (1 <<(i - 1))) ) ret = std::max(ret, 1 + dfs(pos, mask1 | (1 << i) , mask2 | (1 << i) | (1 <<(i - 1) ) ));
            if (in(i + 1, pos) && !(mask2 & (1 <<(i + 1))) ) ret = std::max(ret, 1 + dfs(pos, mask1 | (1 << i) , mask2 | (1 << i) | (1 <<(i + 1) ) ));
        }
    }
    ret = std::max(ret, dfs(pos + 1, mask2, mask[pos + 2]));
    return ret;
}

class TheTilesDivTwo
{
public:
    int find(vector <string> _board)
    {
        memset(dp, -1, sizeof(dp));
        board = _board;
        m = _board.size();
        n = _board[0].length();
        int i, j;
        for (i = 0; i < n; i++)
        {
            mask[i] = 0;
            for (j = 0; j < m; j++)
            {
                if (_board[j][i] == 'X') mask[i] |= 1 << (j);
            }
        }
        return dfs(0, mask[0], mask[1]);
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

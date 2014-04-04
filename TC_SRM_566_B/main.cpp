#include <iostream>
#include <string>
#include <string.h>
using namespace std;
#define N 60
#define MAX(a,b) (a>b)?a:b
int dp[N][N];
int n;
int f(string colors)
{
    cout << colors << endl;
	memset(dp, 0, sizeof(dp));
    int i, j, k;
    for (i = 2; i <= n; i ++)
    {
        for(j = 0; j <= n - i ; j++)
        {
            k = j + i - 1;
            if (colors[j] == colors[k])
            {
                dp[j][k] = 1 + dp[j + 1][k - 1];
                dp[j][k] = MAX(dp[j][k], dp[j + 1][k]);
                dp[j][k] = MAX(dp[j][k], dp[j][k - 1]);
                if (colors[j] == colors[j + 1])dp[j][k] = MAX(dp[j][k], 1 + dp[j + 2][k]);
                if (colors[k] == colors[k - 1])dp[j][k] = MAX(dp[j][k], 1 + dp[j][k - 2]);
            }
            else
            {
                dp[j][k] = MAX(dp[j][k - 1], dp[j + 1][k]);
                dp[j][k] = MAX(dp[j][k], dp[j + 1][k - 1]);
                if (colors[j] == colors[j + 1])dp[j][k] = MAX(dp[j][k], 1 + dp[j + 2][k]);
                if (colors[k] == colors[k - 1])dp[j][k] = MAX(dp[j][k], 1 + dp[j][k - 2]);
            }
        }
    }
    return dp[0][n-1];
}
string col;
int solve(int a, int b)
{
    int tt = 0;
    if (a == b) return 0;
    if (a > b) return 0;
    if (dp[a][b]) return dp[a][b];
    if (col[a] == col[b]) tt = 1 + solve(a + 1, b - 1);
    int ttt = solve(a, b - 1);
    tt = MAX(tt, ttt);
    ttt = solve(a + 1, b);
    tt = MAX(tt, ttt);
    if (col[a] == col[a + 1]) tt = MAX(tt, 1 + solve(a + 2, b));
    if (col[b] == col[b - 1]) tt = MAX(tt, 1 + solve(a, b - 2));
    for (int i = a + 1; i < b; i++)
    {
        if (col[i] == col[a]) ttt = 1 + solve(a + 1, i - 1) + solve(i + 1, b);
        tt = MAX(tt, ttt);
    }
    dp[a][b] = tt;
    return tt;
}

class PenguinPals
{
public:
	int findMaximumMatching(string colors)
{
    //if (colors == "RBRBRBRBRBBRBRBRBBRBRBBBRBRBBRBRBRBBRBBBRBBBRBB")return 23;
    //if (colors == "BRBRBRBRBRBBRBRBRBRBBRBBBBBRRRRRRBRRBBRBRBR") return 21;
    /*
    int ans = 0;
    int t;
        n = colors.size();
        t = n;
        string str = colors;
        while(t--)
        {
            char rr = str[0];
            str = str.substr(1, n - 1) + rr;
            int tt = f(str);
            ans = MAX(tt, ans);
        }
        */
    n = colors.size();
    col = colors;
    solve(0, n- 1);
    return dp[0][n-1];
}
};

int main()
{
    PenguinPals x;
    cout << x.findMaximumMatching("RBRBRBRBRBRBRBRBRBRBRBRRBRBRBRBRBRBRBRB") << endl;
    return 0;
}

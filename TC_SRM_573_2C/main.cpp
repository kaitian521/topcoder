#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
#include <map>
#include <stdio.h>
#include <queue>
#include <algorithm>
#define N 60
#define INF (long long) (1LL << 60)
long long dp[N][N];
using namespace std;
int n, m;
struct node
{
    int id, hid;
    node(){}
    node(int _id, int _hid) {id = _id; hid = _hid;}
};

class SkiResorts
{
public:
    long long minCost(vector <string> road, vector <int> altitude)
    {
        int n = road.size();
        int i, j, k;
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                dp[i][j] = INF;
            }
        }
        map<long long, int>mm;
        vector<long long>v;
        for (i = 0; i < n; i ++)
        {
            mm[altitude[i]] = 1;
        }
        m = mm.size();
        for (map<long long, int>::iterator it = mm.begin(); it != mm.end(); it ++)
        {
            v.push_back(it->first);
            printf("%lld\n", it->first);
        }
        reverse(v.begin(), v.end());
        queue<node>q;
        for (i = 0; i < m; i++)
        {
            q.push(node(0, i));
            dp[0][i] = abs(v[i] - altitude[0]);
        }
        while (!q.empty())
        {
            node tt = q.front();
            q.pop();
            if (tt.id == n - 1) continue;
            for (i = 0; i < n; i++)
            {
                if (road[tt.id][i] != 'Y' || i == tt.id) continue;
                for (j = tt.hid; j < m; j++)
                {
                    long long tmp = dp[tt.id][tt.hid] + abs(v[j] - altitude[i]);
                    if (tmp < dp[i][j])
                    {
                        dp[i][j] = tmp;
                        q.push(node(i, j));
                    }
                }
            }
        }
        long long ans = INF;
        for (i = 0; i < m; i++)
        {
            if (dp[n - 1][i] < ans) ans = dp[n - 1][i];
        }
        if (ans == INF) return -1;
        return ans;
    }
};

int main()
{
    SkiResorts x;
    string str1[] = {"NYN","YNY", "NYN"};
    vector<string>test(str1, str1 + 3);
    int str2[] = {30, 20, 10};
    vector<int>test2(str2, str2 + 3);
    printf("%lld\n", x.minCost(test, test2));
    return 0;
}

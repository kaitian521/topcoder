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
class CityMap
{
public:
    string getLegend(vector <string> cityMap, vector <int> POIs)
    {
        int i, j;
        int row = cityMap.size(), colomn = cityMap[0].size();
        int cnt[200];
        memset (cnt, 0, sizeof(cnt));
        int pos[3000];
        for (i = 0; i < row; i ++)
        {
            for (j = 0; j < colomn; j++)
            {
                cnt[cityMap[i][j]] ++;
            }
        }
        for (i = 0; i < 200; i++)
        {
            pos[cnt[i]] = i;
        }
        string res = "";
        for (i = 0; i < POIs.size(); i++)
        {
            res += pos[POIs[i]];
        }
        return res;
    }
};
int main()
{
    return 0;
}

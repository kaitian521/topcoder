#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX(a,b) (a>b)?(a):(b)
using namespace std;
int n;
vector<int>low, upp;
struct point
{
    int x, y;
    point(int _x, int _y)
    {
        x = _x; y = _y;
    }
};
bool cmp(point p1, point p2)
{
    if (p1.x == p2.x) return p1.y < p2.y;
    return p1.x < p2.x;
}
vector<point>v;
void dfs(int step, int ll, int hh)
{
    if (step == n)
    {
        if (hh <= 9000) return;
        if (ll <= 9000) ll = 9001;
        v.push_back(point(ll, hh));
        return;
    }
    dfs(step + 1, ll, hh);
    dfs(step + 1, ll + low[step], hh + upp[step]);
}
class Over9000Rocks
{
public:
    int countPossibilities(vector <int> lowerBound, vector <int> upperBound)
    {
        n = lowerBound.size();
        low = lowerBound;
        upp = upperBound;
        dfs(0, 0, 0);
        int ans = 0, i;
        sort(v.begin(), v.end(), cmp);
        for (i = 0; i < v.size(); i++)
        {
            cout << v[i].x << "\t" << v[i].y << endl;
        }
        int m = v.size();
        if (v.size() == 0) return 0;
        int left = v[0].x;
        int right = v[0].y;
        for (i = 1; i < m; )
        {
            if (v[i].x <= right + 1)
            {
                right = MAX(right, v[i].y);
                i ++;
            }
            else
            {
                ans += right - left + 1;
                left = v[i].x;
                right = v[i].y;
                i++;
            }
        }
        ans += right - left + 1;
        return ans;
    }
};
int main()
{
    Over9000Rocks O;
    int a[] = {177258, 439976, 996972, 281567, 782547, 998375, 491481, 707710, 146177, 889410};
    int b[] = {293261, 559909, 997946, 410135, 784021, 998581, 925665, 743314, 626775, 943659};
    vector<int>v1(a, a + 10);
    vector<int>v2(b, b + 10);
    cout << O.countPossibilities(v1, v2) << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <stdio.h>
using namespace std;
int n;
int dir[4][2] = {1, 0, 0, -1, -1, 0, 0, 1};
long long x, y, angle;
vector<int>a;
long long myabs(long long T)
{
    if (T < 0) return -T;
    return T;
}
void f()
{
    int i;
    for (i = 0; i < a.size(); i++)
    {
        x += dir[angle][0] * a[i];
        y += dir[angle][1] * a[i];
        angle = (angle + a[i]) % 4;
    }
}
class RobotHerb
{
public:
    long long getdist(int T, vector <int> _a)
    {
        long long xx, yy;
        int i, j;
        a = _a;
        f();
        if (angle == 0)
        {
            xx = x * T;
            yy = y * T;
            return myabs(x) + myabs(y);
        }
        if (angle == 1)
        {
            x = 0; y = 0; angle = 0;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < a.size(); j++)
                {
                    x += dir[angle][0] * a[j];
                    y += dir[angle][1] * a[j];
                    angle = (angle + a[j]) % 4;
                }
            }
            long long cnt = T / 4;
            xx = x * cnt;
            yy = y * cnt;
            for (i = 0; i < T % 4; i++)
            {
                for (j = 0; j < a.size(); j++)
                {
                    xx += dir[angle][0] * a[j];
                    yy += dir[angle][1] * a[j];
                    angle = (angle + a[j]) % 4;
                }
            }
            return myabs(xx) + myabs(yy);
        }
        if (angle == 2)
        {
            x = 0; y = 0; angle = 0;
            for (i = 0; i < 2; i++)
            {
                for (j = 0; j < a.size(); j++)
                {
                    x += dir[angle][0] * a[j];
                    y += dir[angle][1] * a[j];
                    angle = (angle + a[j]) % 4;
                }
            }
            long long cnt = T / 2;
            xx = x * cnt;
            yy = y * cnt;
            for (i = 0; i < T % 2; i++)
            {
                for (j = 0; j < a.size(); j++)
                {
                    xx += dir[angle][0] * a[j];
                    yy += dir[angle][1] * a[j];
                    angle = (angle + a[j]) % 4;
                }
            }
            return myabs(xx) + myabs(yy);
        }
        if (angle == 3)
        {
            x = 0; y = 0; angle = 0;
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < a.size(); j++)
                {
                    x += dir[angle][0] * a[j];
                    y += dir[angle][1] * a[j];
                    angle = (angle + a[j]) % 4;
                }
            }
            long long cnt = T / 4;
            xx = x * cnt;
            yy = y * cnt;
            for (i = 0; i < T % 4; i++)
            {
                for (j = 0; j < a.size(); j++)
                {
                    xx += dir[angle][0] * a[j];
                    yy += dir[angle][1] * a[j];
                    angle = (angle + a[j]) % 4;
                }
            }
            return myabs(xx) + myabs(yy);
        }
        return 0;
    }
};
int main()
{
    return 0;
}

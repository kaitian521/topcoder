#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAX(x, y) (x>y)?x:y
#define INF -10000000000000.0
double MIN(double x, double y)
{
    return (x < y)? x : y;
}
#define EPS 1e-9
#define PI (double)3.14159265358979323846
#define N 260
struct point
{
    double x, y;
    point(double _x, double _y){x = _x; y = _y;}
};
double area(point p1, point p2)
{
    return (p1.x * p2.y - p1.y * p2.x) / 2;
}
double cross(point p1, point p2, point p3)
{
    point pp1(p2.x - p1.x, p2.y - p1.y);
    point pp2(p3.x - p1.x, p3.y - p1.y);
    return pp1.x * pp2.y - pp1.y * pp2.x;
}
vector<point>v;
vector<point>pul;
double dp[N][N];
bool can[N][N];
class FencingPenguinsEasy
{
public:
    double calculateMinArea(int numPosts, int radius, vector <int> x, vector <int> y)
    {
        int i, j, k, tt;
        double angel = 2.0 * PI / numPosts;
        for (i = 0; i < numPosts; i++)
        {
            v.push_back(point(1.0 * radius * cos(i * angel), 1.0 * radius * sin(i * angel)));
        }
        for (i = 0; i < x.size(); i++)
        {
            pul.push_back(point(x[i], y[i]));
        }
        for (i = 0; i < x.size(); i++)
        {
            double dis = sqrt(pul[i].x * pul[i].x + pul[i].y * pul[i].y);
            if (dis > radius) return -1;
        }

        for (i = 0; i < numPosts; i++)
        {
            for (j = 0; j < numPosts; j++)
            {
                bool flag = 1;
                if (i == j) continue;
                for (k = 0; k < x.size(); k++)
                {
                    if (cross(pul[k], v[i], v[j]) < 0) {flag = 0; break;}
                }
                if (flag) can[i][j] = 1;
            }
        }
        double ans = -1;
        for (i = 0; i < numPosts; i++)
        {
            for (int tt1 = 0; tt1 < N; tt1 ++)
                for (int tt2 = 0; tt2 < N; tt2 ++)
                    dp[tt1][tt2] = -1;
            for (j = 1; j < numPosts; j ++)
            {
                if (can[i][(j+i) % numPosts]) dp[i][(j+i) % numPosts] = area(v[i], v[(j+i) % numPosts]);
            }
            for (j = 2; j < numPosts; j++)
            {
                int jj = (j + i) % numPosts;
                for (k = 1; k < j; k++)
                {
                    int kk = (k + i) % numPosts;
                    if (dp[i][kk] != -1 && can[kk][jj])
                    {
                        if (dp[i][jj] == -1) dp[i][jj] = dp[i][kk] + area(v[kk], v[jj]);
                        else dp[i][jj] = MIN(dp[i][jj], dp[i][kk] + area(v[kk], v[jj]));
                    }
                }
                if (dp[i][jj] != -1 && can[jj][i])
                {
                      double tt = fabs(dp[i][jj] + area(v[jj], v[i]));
                      if (ans == -1) ans = tt;
                      else ans = MIN(ans, tt);
                }
            }
        }
        return ans;
    }
};

int main()
{
    FencingPenguinsEasy c;
    int a[] = {8,2,100,120,52,67,19,-36};
    int b[] = {-19,12,88,-22,53,66,-140,99};
    vector<int>x(a, a + 8);
    vector<int>y(b, b + 8);
    printf("%.4lf\n", c.calculateMinArea(30, 800, x, y));
    return 0;
}

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
#include <string>
#include <string.h>
#define N 310
int LL[N], RR[N];
long long mod = 1000000007LL;
int dp[N][N];
int m, n;
using namespace std;

class WolfInZooDivTwo {
public:
	int count(int, vector <string>, vector <string>);
};

bool check(int x, int y)
{
    if (x > y) return true;
    int i;
    for (i = 0; i < m; i++)
    {
        if (x <= LL[i] && y >= RR[i]) return false;
    }
    return true;
}

int WolfInZooDivTwo::count(int _N, vector <string> L, vector <string> R) {
	string str = "";
	m = 0;
	n = _N;
	int i, j, k, q;
	for (i = 0; i < L.size(); i++) str += L[i]; str += " ";
	i = 0;
	memset(dp, 0, sizeof(dp));
	while (i < str.size())
    {
        if (str[i] != ' ')
        {
            k = 0; j = i;
            while (j < str.size() && str[j] != ' ') {k = k * 10 + str[j] - '0'; j++;}
            LL[m++] = ++k;
            i = j + 1;
            //cout << k << " ";
        }
        else i ++;
    }

	i = 0;
	m = 0;
	str = "";
	for (i = 0; i < R.size(); i++) str += R[i]; str += " ";
	i = 0;
	while (i < str.size())
    {
        if (str[i] != ' ')
        {
            k = 0; j = i;
            while (j < str.size() && str[j] != ' ') {k = k * 10 + str[j] - '0'; j++;}
            RR[m++] = ++k;
            i = j + 1;
            //cout << k << " ";
        }
        else i ++;
    }
    long long sum = 0;
    dp[0][0] = 1;
    for (i = 1; i <= n; i++)
    {
        for(j = i - 1; j >= 0; j--)
        {
            if (check(j + 1, i - 1) == 0) continue;
            for (k = 0; k <= j; k++)
            {
                dp[j][i] += dp[k][j];
                dp[j][i] %= mod;
            }
            printf("dp[ %d ][ %d ] = %d\n", j, i, dp[j][i]);
            //sum += dp[j][i];
            //sum %= mod;
        }
    }
    for (j = n; j >= 0; j--)
    {
        if (!check(j + 1, n)) continue;
        for (k = 0; k <= j; k++)
        {
            dp[n + 1][j] += dp[k][j];
            dp[n + 1][j] %= mod;
        }
        sum += dp[n + 1][j];
        sum %= mod;
    }
    return sum;
    /*
    dp[0][0] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = i - 1; j >= 0; j--)
        {
            if (!check(j + 1, i - 1)) break; // cut-off branch
            for (k = 0; k <= j; k++)
            {
                dp[i][k + 1] += dp[j][k];
                dp[i][k + 1] %= mod;
                //printf("dp[ %d ][ %d ]= %d\n", i, k + 1, (int) dp[i][k + 1]);
            }
        }
    }
    for (j = 0; j <= n; j++)
    {
        for (k = 0; k <= j; k++)
        {
            if (check(j + 1, n)) dp[n + 1][k] += dp[j][k];
            dp[n + 1][k] %= mod;
        }
    }

    long long sum = 0;
    for(i = 0; i <= n; i++)
    {
        sum += dp[n + 1][i];
        sum %= mod;
    }
    */
    return (int)sum;
}



double test3() {
    // 001 010 011 101 110 111
	int p0 = 3;
	string t1[] = {"1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"2"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WolfInZooDivTwo * obj = new WolfInZooDivTwo();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main()
{
    test3();
    return 0;
}

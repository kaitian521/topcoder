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
bool can[N][N];
int m, n;
using namespace std;

class WolfInZooDivOne {
public:
	int count(int, vector <string>, vector <string>);
};

int check(int x, int y)
{
    int value = 10000;

    for (int i = 0; i < m; i++)
    {
        if (x >= LL[i] && y <= RR[i]) if (LL[i] < value) value = LL[i];
        if(x == 3 && y == 5) printf("-- %( %d --- %d )---\n", LL[i], RR[i]);
    }
    return value;
}

int WolfInZooDivOne::count(int _N, vector <string> L, vector <string> R) {
	string str = "";
	memset(can, 0, sizeof(can));
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
    for (i = 0; i < m; i++)
    {
        for (k = LL[i]; k <= RR[i]; k++)
        {
            for (j = k + 1; j <= RR[i]; j++) can[k][j] = 1;
        }
    }
    long long sum = 1;
    dp[0][0] = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = i - 1; j >= 0; j--)
        {
            for (k = 0; k <= j; k++)
            {
                if (can[k][i]) continue;
                dp[j][i] += dp[k][j];
                dp[j][i] %= mod;
            }
            sum += dp[j][i];
            sum %= mod;
        }
    }
    return (int)sum;
}


double test1() {
	int p0 = 5;
	string t1[] = {"0 1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"2 4"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WolfInZooDivOne * obj = new WolfInZooDivOne();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 21;
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
double test0() {
	int p0 = 5;
	string t1[] = {"0"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"4"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WolfInZooDivOne * obj = new WolfInZooDivOne();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 16;
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
double test2() {
	int p0 = 10;
	string t1[] = {"0 4 2 7"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"3 9 5 9"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WolfInZooDivOne * obj = new WolfInZooDivOne();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 225;
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

double test5() {
	int p0 = 4;
	string t1[] = {"0 1 0"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"2 3 3"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	WolfInZooDivOne * obj = new WolfInZooDivOne();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 21;
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
    //freopen("1.txt", "w", stdout);
    test2();
    return 0;
}

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

const int N= 55;
long long Aug[N][N];
long long getComposite(int m,int n)
{
    if (m < n) return 0;
    long long preResult0;
    long long preResult1;

    if (m==0 || n== 0 || m== 1 || m == n)
        return 1;
    if (Aug[m][n] != 0)
        return Aug[m][n];
    else
    {
        Aug[m-1][n]   = getComposite(m-1,n);
        Aug[m-1][n-1] = getComposite(m-1,n-1);
    }
    return Aug[m][n] = Aug[m-1][n] + Aug[m-1][n-1];
}

class Excavations {
public:
	long long count(vector <int>, vector <int>, vector <int>, int);
};
long long dp[N][N][2];
long long Excavations::count(vector <int> kind, vector <int> depth, vector <int> found, int K) {
    cout << (int) getComposite(6, 2) << endl;
    vector<int>v[N];
    vector<int>useless;
    map<int, int>mm;
    long long ans = 0;
    int i, j, k, n = kind.size(), m;
    for (i = 0; i < n; i++)
    {
        bool flag = 0;
        for (j = 0; j < found.size(); j++)
        {
            if (found[j] == kind[i])
            {
                flag = 1; break;
            }
        }
        int tmp = kind[i];
        if (flag)
        {
            v[kind[i]].push_back(depth[i]);
            mm[depth[i]] = 1;
        }
        else
        {
            useless.push_back(depth[i]);
        }
    }
    for (i = 0; i < found.size(); i++) sort(v[found[i]].begin(), v[found[i]].end());
    sort(useless.begin(), useless.end());
    map<int, int>::iterator it = mm.begin();
    for (; it != mm.end(); it++)
    {
        memset(dp, 0, sizeof(dp));
        int maxx = it->first;
        //if (maxx < 1000) continue;
        for (i = 0; i < found.size(); i++)
        {
            int id = found[i];
            int hehe = v[id].size();
            for (j = 0; j < v[id].size(); j++)
            {
                if (v[id][j] > maxx) break;
                for (k = 1 + i; k <= K; k++) // k是一共取了多少
                {
                    if (v[id][j] == maxx)
                    {
                        for (int kk = 1; kk <= j + 1 && kk <= k; kk++) // kk 是他自己取了几个
                        {
                            if (i == 0)
                            {
                                if(k == kk) dp[i][k][1] += getComposite(j, kk - 1);
                            }
                            else
                            {
                                dp[i][k][1] += dp[i - 1][k - kk][0] * getComposite(j, kk - 1);
                                dp[i][k][1] += dp[i - 1][k - kk][1] * getComposite(j, kk - 1);
                            }
                        }
                    }
                    else
                    {
                        for (int kk = 1; kk <= j + 1 && kk <= k; kk++) // kk 是他自己取了几个
                        {
                            if (i == 0)
                            {
                                if(k == kk) dp[i][k][0] += getComposite(j, kk - 1);
                            }
                            else
                            {
                                dp[i][k][0] += dp[i - 1][k - kk][0] * getComposite(j, kk - 1);
                                dp[i][k][1] += dp[i - 1][k - kk][1] * getComposite(j, kk - 1);
                            }
                        }
                    }
                }
            }
        }
        for (i = found.size(); i <= K; i++)
        {
            for (j = 0; j < useless.size(); j++)
            {
                if (useless[j] > maxx) break;
            }
            m = useless.size() - j;
            n = K - i;
            if(m >= n) ans += dp[found.size() - 1][i][1] * getComposite(m, n);
        }
    }
    return ans;
}
//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {1, 1, 2, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10, 15, 10, 20};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	Excavations * obj = new Excavations();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 3LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1, 1, 2, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10, 15, 10, 20};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	Excavations * obj = new Excavations();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 4LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1, 2, 3, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10, 10, 10, 10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 3;
	Excavations * obj = new Excavations();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {1, 2, 2, 3, 1, 3, 2, 1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {12512, 12859, 125, 1000, 99, 114, 125, 125, 114};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 2, 3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 7;
	Excavations * obj = new Excavations();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 35LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {50};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 18;
	Excavations * obj = new Excavations();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 9075135300LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;

	time = test0();
	if (time < 0)
		errors = true;

	time = test3();
	if (time < 0)
		errors = true;

	time = test2();
	if (time < 0)
		errors = true;

	time = test3();
	if (time < 0)
		errors = true;

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

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

int n;
const int N= 55;
long long Aug[N][N];
long long getComposite(int m,int n)
{
    if (m < 0 || n < 0) return 0;
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
vector<int>depth;

void lisan()
{
    vector<int>bak = depth;
    int id = 1;
    map<int, int>mm;
    map<int, int>::iterator it;
    sort(depth.begin(), depth.end());
    mm[depth[0]] = id++;
    for (int i = 1; i < depth.size(); i++)
    {
        it = mm.find(depth[i]);
        if (it == mm.end())
        {
            mm[depth[i]] = id++;
        }
    }
    depth.clear();
    for (int i = 0; i < n; i++)
    {
        depth.push_back(mm[bak[i]]);
    }
}
class Excavations2 {
public:
	long long count(vector <int>, vector <int>, int);
};
vector<int>v[N];
vector<int>useless;
vector<int>found;
int K;
long long dp[N][N];
long long dfs(int id, int select)
{
    if (select > K) return 0;
    long long &res = dp[id][select];
    if (res != -1) return res; res = 0;
    int i, j, k;
    if (id == found.size())
    {
    	if (select == K) return res = 1;
    	return 0;
    }
    for (i = 0; i < v[found[id]].size(); i++)
    {
        int ss = v[found[id]].size();
        int rest = v[found[id]].size() - i;
        for (j = 1; j <= rest; j++)
        {
            int tmp = v[found[id]][i];
            res += dfs(id + 1, j + select) * getComposite(rest - 1, j - 1);
        }
    }
    printf("dp[ %d ][ %d ] = %lld\n", id, select, res);
    return res;
}

long long Excavations2::count(vector <int> kind, vector <int> _found, int _K) {
    K = _K;
    found = _found;
    vector<int>depth = kind;
    n = kind.size();
    int i, j, k;
    for (i = 0; i < N; i++) v[i].clear();
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < found.size(); j++)
        {
            if (found[j] == kind[i]) break;
        }
        if (j != found.size())
        {
            v[kind[i]].push_back(depth[i]);
        }
    }
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0);
}
//Powered by [KawigiEdit] 2.0!

double test0() {
	int t0[] = {1, 2, 2, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	Excavations2 * obj = new Excavations2();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 1LL;
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
double test1() {
	int t0[] = {1, 2, 2, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	Excavations2 * obj = new Excavations2();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 4LL;
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
	int t0[] = {1, 2, 1, 1, 2, 3, 4, 3, 2, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {4, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	Excavations2 * obj = new Excavations2();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 6LL;
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
double test3() {
	int t0[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {50};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 21;
	Excavations2 * obj = new Excavations2();
	clock_t start = clock();
	long long my_answer = obj->count(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 5567902560LL;
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

int main() {
	int time;
	bool errors = false;

	time = test1();
	if (time < 0)
		errors = true;

	time = test1();
	if (time < 0)
		errors = true;

	time = test2();
	if (time < 0)
		errors = true;

	time = test3();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}


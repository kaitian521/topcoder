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
class Excavations {
public:
	long long count(vector <int>, vector <int>, vector <int>, int);
};
vector<int>v[N];
vector<int>useless;
vector<int>found;
int K;
long long dp[N][N][N + 10];
long long dfs(int id, int select, int maxx)
{
    long long &res = dp[id][select][maxx];
    if (res != -1) return res; res = 0;
    int i, j, k;
    int ss = useless.size();
    if (id == found.size())
    {
        if (K >= select)
        {
            for (i = 0; i < useless.size(); i++)
            {
                int val = useless[i];
                int val2 = useless[i + 1];
                if (useless[i] > maxx) break;
            }
            int mm = useless.size() - i;
            int nn = K - select;
            return res = getComposite(mm, nn);
        }
        else
        {
            return 0;
        }
    }
    for (i = 0; i < v[found[id]].size(); i++)
    {
        ss = v[found[id]].size();
        int rest = v[found[id]].size() - i;
        for (j = 1; j <= rest; j++)
        {
            int tmp = v[found[id]][i];
            res += dfs(id + 1, j + select, std::max(maxx, v[found[id]][i])) * getComposite(rest - 1, j - 1);
        }
    }
    printf("dp[ %d ][ %d ][ %d ] = %lld\n", id, select, maxx, res);
    return res;
}

long long Excavations::count(vector <int> kind, vector <int> _depth, vector <int> _found, int _K) {
    depth = _depth;
    K = _K;
    found = _found;
    n = kind.size();
    lisan();
    int i, j, k;
    for (i = 0; i < N; i++) v[i].clear(); useless.clear();
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
        else
        {
            useless.push_back(depth[i]);
        }
    }
    sort(useless.begin(), useless.end());
    for (i = 0; i < N; i++) sort(v[i].begin(), v[i].end());
    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, 0);
}
//Powered by [KawigiEdit] 2.0!


double test0() {
	int t0[] = {43,    45,    44,    43,    43,    10,    2,     9,     43,    45,    24,    32,    22,    11,    2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {11694, 13945, 22571, 13945, 96402, 46728, 46728, 30230, 18506, 25194, 96402, 61113, 46728, 13945, 32825};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {11, 43};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 13;
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
return 0;
	time = test1();
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



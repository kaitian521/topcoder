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
using namespace std;

class TheExperiment {
public:
	int countPlacements(vector <string>, int, int, int, int);
};
const int N = 400;
bool can[N][N];
long long dp[N][N][4];
string v;
int M, L, A, B, n;
const long long mod = 1000000009;


/**

** 0 : start
** 1 : have length L
** 2 : do not have L yet

**/
long long f(int id, int spongy, int last)
{
    int i, j, k;
    if (spongy == M)
    {
        if (id <= v.size() && last == 1) return 1;
        return 0;
    }
    if (id >= v.size()) return 0;
    long long &res = dp[id][spongy][last];
    if (res != -1) return res;
    res = 0;
    for (i = id; i < v.size(); i++)
    {
        if (can[id][i] && (i - id + 1 <= L) )
        {
            if (i - id + 1 == L || last == 1) res += f(i + 1, spongy + 1, 1);
            else res += f(i + 1, spongy + 1, 2);
            res %= mod;
        }
    }
    if(last != 2) res += f(id + 1, spongy, 0);
    res %= mod;
    return res;
}

int TheExperiment::countPlacements(vector <string> _intensity, int _M, int _L, int _A, int _B) {
	M = _M; L = _L; A = _A; B = _B; v = accumulate(_intensity.begin(), _intensity.end(), string(""));
	memset(dp, -1, sizeof(dp));
	memset(can, 0, sizeof(can));
	n = v.size();
	int i, j, k;
	for (i = 0; i < n; i++)
    {
        int tmp = 0;
        for (j = i; j < n; j++)
        {
            tmp += v[j] - '0';
            if (tmp >= A && tmp <= B) can[i][j] = 1;
        }
    }
    return (int)f(0, 0, 0);
}
//Powered by [KawigiEdit] 2.0!


double test0() {
	string t0[] = {"341156"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	int p2 = 3;
	int p3 = 6;
	int p4 = 10;
	TheExperiment * obj = new TheExperiment();
	clock_t start = clock();
	int my_answer = obj->countPlacements(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"999112999"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	int p2 = 4;
	int p3 = 21;
	int p4 = 30;
	TheExperiment * obj = new TheExperiment();
	clock_t start = clock();
	int my_answer = obj->countPlacements(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"111"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	int p2 = 2;
	int p3 = 2;
	int p4 = 3;
	TheExperiment * obj = new TheExperiment();
	clock_t start = clock();
	int my_answer = obj->countPlacements(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"59059", "110", "1132230231"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 5;
	int p3 = 10;
	int p4 = 20;
	TheExperiment * obj = new TheExperiment();
	clock_t start = clock();
	int my_answer = obj->countPlacements(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"111111111111111111111111", "111111111111111111111111111", "11111111111111111111111"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 12;
	int p2 = 8;
	int p3 = 4;
	int p4 = 2700;
	TheExperiment * obj = new TheExperiment();
	clock_t start = clock();
	int my_answer = obj->countPlacements(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 418629948;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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

	time = test2();
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

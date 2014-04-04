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
const int mod = 1000000007;
const int N = 1001000;
long long dp[N];

class TrafficCongestion {
public:
	int theMinCars(int);
};
long long bin[N];
long long dfs(int h)
{
    int i;
    long long ans = 0;
    while (h >= 0)
    {
        if (h == 0 || h == 1)
        {
            ans += 1;
            ans %= mod;
            break;
        }
        ans += bin[h - 1];
        ans += mod;
        h -= 2;
    }
    return ans;
}

int TrafficCongestion::theMinCars(int treeHeight) {
    memset(dp, -1, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;
    bin[0] = 1;
    bin[1] = 2;
    for (int i = 2; i < N; i++)
    {
        bin[i] = bin[i - 1] * 2;
        bin[i] %= mod;
    }
    return dfs(treeHeight);
    long long now = 2;
    for (int i = 3; i <= treeHeight; i++)
    {
        dp[i] = 2 * now + 1;
        dp[i] %= mod;
        now = now * 2 + dp[i - 2];
        now %= mod;
    }
    return dp[treeHeight];
}
//Powered by [KawigiEdit] 2.0!

double test0() {
	int p0 = 4;
	TrafficCongestion * obj = new TrafficCongestion();
	clock_t start = clock();
	int my_answer = obj->theMinCars(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	TrafficCongestion * obj = new TrafficCongestion();
	clock_t start = clock();
	int my_answer = obj->theMinCars(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 3;
	TrafficCongestion * obj = new TrafficCongestion();
	clock_t start = clock();
	int my_answer = obj->theMinCars(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 585858;
	TrafficCongestion * obj = new TrafficCongestion();
	clock_t start = clock();
	int my_answer = obj->theMinCars(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 548973404;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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

	time = test3();
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


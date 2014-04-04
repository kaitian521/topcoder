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
#include <queue>
using namespace std;

struct node
{
    int x, dis;
    node() {}
    node(int _x, int _dis){x = _x; dis = _dis;}
};
const int N = 60;
int n;
const int INF = 1000;
int dp[N];
class TravelOnMars {
public:
	int minTimes(vector <int>, int, int);
};

int TravelOnMars::minTimes(vector <int> range, int startCity, int endCity) {
    int i, j, k;
    n = range.size();
    for (i = 0; i < range.size(); i++) dp[i] = INF;
    queue<node>q;
    q.push(node(startCity, 0));
    dp[startCity] = 0;
    while (!q.empty())
    {
        node tt = q.front(); q.pop();
        if (tt.x == endCity) return tt.dis;
        for (i = 1; i <= range[tt.x]; i++)
        {
            int point = (i + tt.x) % n;
            if (dp[point] != INF) continue;
            dp[point] = tt.dis + 1;
            q.push(node(point, tt.dis + 1));
        }
        for (i = 1; i <= range[tt.x]; i++)
        {
            int point = (tt.x - i + n) % n;
            if (dp[point] != INF) continue;
            dp[point] = tt.dis + 1;
            q.push(node(point, tt.dis + 1));
        }
    }
    return -1;
}


double test0() {
	int t0[] = {2,1,1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	int p2 = 4;
	TravelOnMars * obj = new TravelOnMars();
	clock_t start = clock();
	int my_answer = obj->minTimes(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	int t0[] = {2,1,1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 4;
	int p2 = 1;
	TravelOnMars * obj = new TravelOnMars();
	clock_t start = clock();
	int my_answer = obj->minTimes(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int t0[] = {2,1,1,2,1,2,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	int p2 = 6;
	TravelOnMars * obj = new TravelOnMars();
	clock_t start = clock();
	int my_answer = obj->minTimes(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int t0[] = {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 6;
	int p2 = 13;
	TravelOnMars * obj = new TravelOnMars();
	clock_t start = clock();
	int my_answer = obj->minTimes(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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

	time = test0();
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


//Powered by [KawigiEdit] 2.0!

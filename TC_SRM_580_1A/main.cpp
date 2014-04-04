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
#include <string.h>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int n;
struct node
{
    long long start, end;
    int id;
    node(){}
    node(int _id, long long _start, long long _end){
        id = _id; start = _start; end = _end;
    }
};
vector<node>v;
bool cmp(node t1, node t2)
{
    if (t1.start == t2.start) return t1.end < t2.end;
    return t1.start < t2.start;
}

class EelAndRabbit {
public:
	int getmax(vector <int>, vector <int>);
};
const int N = 55;
bool cover[2 * N][N];
int EelAndRabbit::getmax(vector <int> l, vector <int> t) {
    int i, j, k;
	n = l.size();
	v.clear();
	memset(cover, 0, sizeof(cover));
	if (n == 1) return 1;
	vector<long long> duan;
	for (i = 0; i < n; i++)
    {
        duan.push_back(-t[i]);
        duan.push_back(-t[i] - l[i]);
        v.push_back(node(i, -t[i] - l[i], -t[i]));
    }
    for (i = 0; i < duan.size(); i++)
    {
        for (j = 0; j < n; j++)
        {
            if (duan[i] >= v[j].start && duan[i] <= v[j].end)
            {
                cover[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (i = 0; i < duan.size(); i++)
    {
        for (j = i + 1; j < duan.size(); j++)
        {
            set<int>s;
            s.clear();
            for (k = 0; k < n; k++)
            {
                if (cover[i][k]) s.insert(k);
            }
            for (k = 0; k < n; k++)
            {
                if (cover[j][k]) s.insert(k);
            }
            ans = std::max(ans, (int)s.size());
        }
    }
    return ans;
}


double test0() {
	int t0[] = {2, 4, 3, 2, 2, 1, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 6, 3, 7, 0, 2, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	EelAndRabbit * obj = new EelAndRabbit();
	clock_t start = clock();
	int my_answer = obj->getmax(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1, 1, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 0, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	EelAndRabbit * obj = new EelAndRabbit();
	clock_t start = clock();
	int my_answer = obj->getmax(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	EelAndRabbit * obj = new EelAndRabbit();
	clock_t start = clock();
	int my_answer = obj->getmax(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {8, 2, 1, 10, 8, 6, 3, 1, 2, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {17, 27, 26, 11, 1, 27, 23, 12, 11, 13};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	EelAndRabbit * obj = new EelAndRabbit();
	clock_t start = clock();
	int my_answer = obj->getmax(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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

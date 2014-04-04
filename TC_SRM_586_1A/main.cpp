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

using namespace std;

class PiecewiseLinearFunction {
public:
	int maximumSolutions(vector <int>);
};

bool judge(int x, int y, int z)
{
    return z >= x && z <= y;
}

int PiecewiseLinearFunction::maximumSolutions(vector <int> Y) {
    int i, j, k;
    for (i = 0; i < Y.size(); i++)
    {
        Y[i] *= 2;
    }
    for (i = 1; i < Y.size(); i++)
    {
        if (Y[i] == Y[i - 1]) return -1;
    }
    map<long long, int>mm;
    for (i = 0; i < Y.size(); i++)
    {
        mm[Y[i]] = 1;
        mm[Y[i] - 1] = 1;
        mm[Y[i] + 1] = 1;
    }
    map<long long, int>::iterator it;
    int maxx = 0;
    for (it = mm.begin(); it != mm.end(); it++)
    {
        int res = 0;
        long long tt = it->first;
        for (i = 1; i < Y.size(); i++)
        {
            int x = std::min(Y[i - 1], Y[i]);
            int y = std::max(Y[i - 1], Y[i]);
            if (judge(x, y, tt))
            {
                res ++;
                if (Y[i] == tt) i ++;
            }
        }
        maxx = std::max(maxx, res);
    }
    return maxx;
}
//Powered by [KawigiEdit] 2.0!


double test0() {
	int t0[] = {3, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PiecewiseLinearFunction * obj = new PiecewiseLinearFunction();
	clock_t start = clock();
	int my_answer = obj->maximumSolutions(p0);
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
	int t0[] = {4, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PiecewiseLinearFunction * obj = new PiecewiseLinearFunction();
	clock_t start = clock();
	int my_answer = obj->maximumSolutions(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	int t0[] = {1, 4, -1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PiecewiseLinearFunction * obj = new PiecewiseLinearFunction();
	clock_t start = clock();
	int my_answer = obj->maximumSolutions(p0);
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
double test3() {
	int t0[] = {2, 1, 2, 1, 3, 2, 3, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PiecewiseLinearFunction * obj = new PiecewiseLinearFunction();
	clock_t start = clock();
	int my_answer = obj->maximumSolutions(p0);
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
double test4() {
	int t0[] = {125612666, -991004227, 0, 6, 88023, -1000000000, 1000000000, -1000000000, 1000000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PiecewiseLinearFunction * obj = new PiecewiseLinearFunction();
	clock_t start = clock();
	int my_answer = obj->maximumSolutions(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

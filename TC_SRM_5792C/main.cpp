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
using namespace std;

class MarblePositioning {
public:
	double totalWidth(vector <int>);
};

double MarblePositioning::totalWidth(vector <int> radius) {
	int i, j, k;
	double ans = 0, maxx, best = 1000000000000.0;
	int seq[10];
	double b[10];
	for (i = 0; i < 10; i++) seq[i] = i;
	do
    {
        b[0] = 0;
        for (i = 1; i < radius.size(); i++)
        {
            maxx = 0;
            for (j = 0; j < i; j++)
            {
                double r1 = radius[seq[i]], r2 = radius[seq[j]];
                double tmp = sqrt(  (r1 + r2) * (r1 + r2) - (r1 - r2) * (r1 - r2) );
                if (b[j] + tmp > maxx) maxx = tmp + b[j];
            }
            b[i] = maxx;
        }
        if (b[radius.size() - 1] < best) best = b[radius.size() - 1];
    }
    while(next_permutation(seq, seq + radius.size()));
    return best;
}


double test0() {
	int t0[] = {1, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MarblePositioning * obj = new MarblePositioning();
	clock_t start = clock();
	double my_answer = obj->totalWidth(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 2.8284271247461903;
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
	int t0[] = {7,7,7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MarblePositioning * obj = new MarblePositioning();
	clock_t start = clock();
	double my_answer = obj->totalWidth(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 28.0;
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
	int t0[] = {10, 20, 30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MarblePositioning * obj = new MarblePositioning();
	clock_t start = clock();
	double my_answer = obj->totalWidth(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 62.92528739883945;
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
	int t0[] = {100, 100,11,11,25};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MarblePositioning * obj = new MarblePositioning();
	clock_t start = clock();
	double my_answer = obj->totalWidth(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 200.0;
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
	int t0[] = {1,999950884,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MarblePositioning * obj = new MarblePositioning();
	clock_t start = clock();
	double my_answer = obj->totalWidth(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p1 = 63246.0;
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

int main()
{
    test2();
    return 0;
}


//Powered by [KawigiEdit] 2.0!

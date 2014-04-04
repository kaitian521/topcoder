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

class SparseFactorialDiv2 {
public:
	long long getCount(long long, long long, long long);
};

bool visit[1000];

long long  divv;
long long f(long long value)
{
    if (value == 0) return 0;
    memset(visit, 0, sizeof(visit));
    long long i, mod;
    long long res = 0;
    for (i = 0; (i * i) < value; i++)
    {
        mod = (i * i) % divv;
        if (visit[mod]) continue;
        visit[mod] = 1;
        long long begin = i * i;
        begin += divv;
        if (begin > value) continue;
        res += (value - begin + divv) / divv;
    }
    printf("f( %d ) = %d\n", (int)value, (int)res);
    return res;
}

long long SparseFactorialDiv2::getCount(long long lo, long long hi, long long divisor) {
	divv = divisor;
	return f(hi) - f(lo - 1);
}
//Powered by [KawigiEdit] 2.0!



double test0() {
	long long p0 = 4LL;
	long long p1 = 8LL;
	long long p2 = 3LL;
	SparseFactorialDiv2 * obj = new SparseFactorialDiv2();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 3LL;
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
	long long p0 = 9LL;
	long long p1 = 11LL;
	long long p2 = 7LL;
	SparseFactorialDiv2 * obj = new SparseFactorialDiv2();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
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
double test2() {
	long long p0 = 1LL;
	long long p1 = 1000000000000LL;
	long long p2 = 2LL;
	SparseFactorialDiv2 * obj = new SparseFactorialDiv2();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 999999999999LL;
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
	long long p0 = 16LL;
	long long p1 = 26LL;
	long long p2 = 11LL;
	SparseFactorialDiv2 * obj = new SparseFactorialDiv2();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
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
double test4() {
	long long p0 = 10000LL;
	long long p1 = 20000LL;
	long long p2 = 997LL;
	SparseFactorialDiv2 * obj = new SparseFactorialDiv2();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 1211LL;
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
	long long p0 = 123456789LL;
	long long p1 = 987654321LL;
	long long p2 = 71LL;
	SparseFactorialDiv2 * obj = new SparseFactorialDiv2();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 438184668LL;
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
    test1();
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

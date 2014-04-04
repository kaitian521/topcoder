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
#include <stdio.h>
#include <string>
using namespace std;
const int N = 301;
const int INF = 1000;
int dp1[N][N], dp2[N][N];
string tree1, tree2;
int n;
void solve(string tree, int dp[N][N])
{
    int i, j, k = 0, id = 0;
    tree += " ";
    i = 0;
    while (i < tree.size())
    {
        if (tree[i] == ' ') {i ++; continue;}
        j = tree[i] - '0';
        i ++;
        while (tree[i] != ' ')
        {
            j = j * 10 + tree[i] - '0';
            i ++;
        }
        cout << j << endl;
        dp[ id + 1][ j ] = dp[ j ][ id + 1 ] = 1;
        i ++;
        id ++;
    }
    n = id + 1;
}
class TreeUnion {
public:
	double expectedCycles(vector <string>, vector <string>, int);
};

double TreeUnion::expectedCycles(vector <string> _tree1, vector <string> _tree2, int K) {
    int i, j, k, m;
	tree1 = accumulate(_tree1.begin(), _tree1.end(), string("") );
	tree2 = accumulate(_tree2.begin(), _tree2.end(), string("") );
    for (i = 0; i < N; i++) for (j = 0; j < N; j++) {dp1[i][j] = INF; dp2[i][j] = INF;}
    solve(tree1, dp1);
    solve(tree2, dp2);
    if (n == 1 || K == 3) return 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (dp1[i][j] > dp1[i][k] + dp1[k][j]) dp1[i][j] = dp1[i][k] + dp1[k][j];
                if (dp2[i][j] > dp2[i][k] + dp2[k][j]) dp2[i][j] = dp2[i][k] + dp2[k][j];
            }
        }
    }
    int hash[1000];
    for (i = 0; i < 1000; i++) hash[i] = 0;
    int ans = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            hash[ dp1[i][j] ] += 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (K - 2 - dp2[i][j] > 0) ans += hash[ K - 2 - dp2[i][j] ];
        }
    }
    return 2.0 * ans / (n * (n - 1));
}
//Powered by [KawigiEdit] 2.0!


double test0() {
	string t0[] = {"0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 4;
	TreeUnion * obj = new TreeUnion();
	clock_t start = clock();
	double my_answer = obj->expectedCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 1.0;
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
	string t0[] = {"0 1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0 1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 4;
	TreeUnion * obj = new TreeUnion();
	clock_t start = clock();
	double my_answer = obj->expectedCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 1.3333333333333333;
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
	string t0[] = {"0 1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0 1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 6;
	TreeUnion * obj = new TreeUnion();
	clock_t start = clock();
	double my_answer = obj->expectedCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.3333333333333333;
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
	string t0[] = {"0 ", "1 1 1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0 1 0 ", "1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 5;
	TreeUnion * obj = new TreeUnion();
	clock_t start = clock();
	double my_answer = obj->expectedCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 4.0;
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
	string t0[] = {"0 1 2 0 1 2 0 1 2 5 6 1", "0 11", " 4"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0 1 1 0 2 3 4 3 4 6 6", " 10 12 12"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 7;
	TreeUnion * obj = new TreeUnion();
	clock_t start = clock();
	double my_answer = obj->expectedCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 13.314285714285713;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}


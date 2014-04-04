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
const int N = 10;
const int INF = 100;
class TreeUnionDiv2 {
public:
	int maximumCycles(vector <string>, vector <string>, int);
};

int TreeUnionDiv2::maximumCycles(vector <string> tree1, vector <string> tree2, int K) {

	int dp1[N][N], dp2[N][N];
	int n = tree1.size();
    if (K == 3 || n == 1) return 0;
    int i, j, k;
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) {dp1[i][j] = INF; dp2[i][j] = INF;}
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (tree1[i][j] == 'X') dp1[i][j] = dp1[j][i] = 1;
            if (tree2[i][j] == 'X') dp2[i][j] = dp2[j][i] = 1;
        }
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
    int ans = 0;
    int perm[N];
    for (i = 0; i < n; i++) perm[i] = i;
    do
    {
        int tmp = 0;
        for (i = 0; i < n; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (dp1[i][j] + dp2[perm[i]][perm[j]] == K - 2) tmp += 1;
            }
        }
        ans = std::max(ans, tmp);

    }while( next_permutation(perm, perm + n) );
    return ans;
}
//Powered by [KawigiEdit] 2.0!

double test0() {
	string t0[] = {"-X",
 "X-"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"-X",
 "X-"}
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 4;
	TreeUnionDiv2 * obj = new TreeUnionDiv2();
	clock_t start = clock();
	int my_answer = obj->maximumCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	string t0[] = {"-X-",
 "X-X",
 "-X-"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"-X-",
 "X-X",
 "-X-"}
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 5;
	TreeUnionDiv2 * obj = new TreeUnionDiv2();
	clock_t start = clock();
	int my_answer = obj->maximumCycles(p0, p1, p2);
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
double test2() {
	string t0[] = {"-X-",
 "X-X",
 "-X-"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"-X-",
 "X-X",
 "-X-"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 3;
	TreeUnionDiv2 * obj = new TreeUnionDiv2();
	clock_t start = clock();
	int my_answer = obj->maximumCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	string t0[] = {"-X---",
 "X-XXX",
 "-X---",
 "-X---",
 "-X---"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"-X-X-",
 "X-X-X",
 "-X---",
 "X----",
 "-X---"}
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 6;
	TreeUnionDiv2 * obj = new TreeUnionDiv2();
	clock_t start = clock();
	int my_answer = obj->maximumCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
	string t0[] = {"-XX------",
 "X------X-",
 "X--XX-X--",
 "--X--X---",
 "--X------",
 "---X----X",
 "--X------",
 "-X-------",
 "-----X---"}

;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"-X-------",
 "X-X------",
 "-X-XX----",
 "--X---X--",
 "--X--X---",
 "----X--XX",
 "---X-----",
 "-----X---",
 "-----X---"}
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 7;
	TreeUnionDiv2 * obj = new TreeUnionDiv2();
	clock_t start = clock();
	int my_answer = obj->maximumCycles(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 17;
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


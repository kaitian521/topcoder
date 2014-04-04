#include <vector>
#include <string>
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

int common(string str1, string str2)
{
    int i, j;
    for (i = 0; i < str1.length() && i < str2.length(); i++)
    {
        if (str1[i] != str2[i]) return i;
    }
    return i;
}
using namespace std;

class UndoHistory {
public:
	int minPresses(vector <string>);
};

int UndoHistory::minPresses(vector <string> lines) {
	int i, j, k;
	int ans = 0;
	for (i = 0; i < lines.size(); i++)
    {
        int maxx = 0;
        for (j = 0; j < i; j++)
        {
            maxx = std::max(maxx, common(lines[i], lines[j]));
        }
        if (i == 0) ans = lines[i].size() + 1;
        else
        {
            if (maxx == 0) ans += 2 + lines[i].size() + 1;
            else
            {
                int INF = 100000000;
                int t1 = INF, t2 = INF;
                if (common(lines[i], lines[i - 1]) == lines[i - 1].length())
                {
                    t1 = (lines[i].size() - common(lines[i], lines[i - 1])) + 1;
                }
                t2 = (lines[i].size() - maxx + 2) + 1;
                if (t1 > t2) t1 = t2;
                ans += t1;
            }
        }
    }
    return ans;
}

double test0() {
	string t0[] = {"tomorrow", "topcoder"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 18;
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
	string t0[] = {"a","b"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
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
double test2() {
	string t0[] = {"a", "ab", "abac", "abacus" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 10;
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
	string t0[] = {"pyramid", "sphinx", "sphere", "python", "serpent"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 39;
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
	string t0[] = {"abcde", "a", "ab", "abcde"};
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	UndoHistory * obj = new UndoHistory();
	clock_t start = clock();
	int my_answer = obj->minPresses(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 13;
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

//Powered by [KawigiEdit] 2.0!
int main()
{
    test4();
    return 0;
}

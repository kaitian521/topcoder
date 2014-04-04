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
const int N = 55;
int cnt[N][N];
int (*cpy)[N];
int n;
class StringGame {
public:
	vector <int> getWinningStrings(vector <string>);
};

int f(int id)
{
    cpy = cnt;
    int i, j, k;
    bool visit[N];
    bool used[N];
    memset(visit, 0, sizeof(visit));
    memset(used, 0, sizeof(used));
    bool add = 1;
    visit[id] = 1;
    while (add)
    {
        add = false;
        for (i = 0; i < 26; i++)
        {
            if (used[i]) continue;
            int equal = -1;
            bool flag = 1;
            for (j = 0; j < n; j++)
            {
                if (visit[j]) continue;
                if (cpy[j][i] > cpy[id][i])
                {
                    flag = 0;
                    equal = 0;
                    break;
                }
                else if (cpy[j][i] == cpy[id][i])
                {
                    equal = 1;
                }
            }
            if (flag == 1 && equal == -1) return true;
            if (flag == 0) continue;
            used[i] = true;
            add = true;
            for (j = 0; j < n; j++)
            {
                if (visit[j]) continue;
                if (cpy[j][i] < cpy[id][i]) visit[j] = true;
            }
            break;
        }
    }
    return false;
}
vector <int> StringGame::getWinningStrings(vector <string> S) {
    n = S.size();
    int i, j, k;
    memset(cnt, 0, sizeof(cnt));
    for (i = 0; i < S.size(); i++)
    {
        for (j = 0; j < S[i].size(); j++)
        {
            cnt[i][S[i][j] - 'a'] += 1;
        }
    }
    vector<int>ans;
    for (i = 0; i < S.size(); i++)
    {
        if(f(i)) ans.push_back(i);
    }
    return ans;
}


double test0() {
	string t0[] = {"a", "b", "c", "d"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StringGame * obj = new StringGame();
	clock_t start = clock();
	vector <int> my_answer = obj->getWinningStrings(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {0, 1, 2, 3 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"aabbcc", "aaabbb", "aaaccc"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StringGame * obj = new StringGame();
	clock_t start = clock();
	vector <int> my_answer = obj->getWinningStrings(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {1, 2 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"ab", "ba"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StringGame * obj = new StringGame();
	clock_t start = clock();
	vector <int> my_answer = obj->getWinningStrings(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <int> p1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	StringGame * obj = new StringGame();
	clock_t start = clock();
	vector <int> my_answer = obj->getWinningStrings(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t1[] = {1, 3, 4 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<p1[0];
		for (int i=1; i<p1.size(); i++)
			cout <<", " <<p1[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
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

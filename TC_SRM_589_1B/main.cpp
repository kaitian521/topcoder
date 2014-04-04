#include <vector>
#include <list>
#include <map>
#include <string>
#include <stdio.h>
#include <string.h>
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
int m, n;
unsigned int dp[52][(1 << 16) + 2];
struct node
{
    int v, dis;
    node(){}
    node(int _v, int _dis){v = _v; dis = _dis;}
};

class TravellingPurchasingMan {
public:
	int maxStores(int, vector <string>, vector <string>);
};
struct item
{
    int open, close, dur;
    item(){}
    item(int _open, int _close, int _dur){open = _open; close = _close; dur = _dur;}
};
int f(int x){
    int ans = 0;
    while(x > 0){
        x &= x - 1;
        ans += 1;
    }
    return ans;
}
vector<item>yisi;
unsigned int bian[52][52];
int N;
int TravellingPurchasingMan::maxStores(int _N, vector <string> interestingStores, vector <string> roads) {
	int INF = 604800 * 100;
	N = _N;
	yisi.clear();
	m = interestingStores.size();
	int i, j, k;
	for (i = 0; i < 52; i++) for (j = 0; j < (1 << 16); j ++) dp[i][j] = INF;
	for (i = 0; i < 52; i++)for (j = 0; j < 52; j++) bian[i][j] = INF;
	for (i = 0; i < roads.size(); i++)
    {
        int start, end, dis;
        sscanf(roads[i].c_str(), "%d %d %d", &start, &end, &dis);
        bian[start][end] = bian[end][start] = dis;
    }
    //floyd
    for (i = 0; i < 52; i++)for (j = 0; j < 52; j++) bian[i][i] = 0;
    for (k = 0; k < 52; k++)
    	for (i = 0; i < 52; i++)
    		for (j = 0; j < 52; j++)
    			if (bian[i][j] > bian[i][k] + bian[k][j]) bian[i][j] = bian[i][k] + bian[k][j];
    for (i = 0; i < m; i++)
    {
        int open, close, dur;
        sscanf(interestingStores[i].c_str(), "%d %d %d", &open, &close, &dur);
        yisi.push_back(item(open, close, dur));
    }
    dp[N - 1][0] = 0;
    for (j = 0; j < (1 << m); j++)
    {
        for (i = 0; i < N; i++)
        {
            if (dp[i][j] != INF)
            {
                unsigned int *ttt;
                for (k = 0; k < m; k++)
                {
                    if (j & (1 << k)) continue;
                    if (dp[i][j] + bian[i][k] > yisi[k].close) continue;
                    if (bian[i][k] == INF) continue;
                    ttt = &dp[k][ j | (1 << k) ];
                    *ttt = std::min(*ttt, (unsigned)std::max(yisi[k].open, (int)dp[i][j] + (int)bian[i][k]) + yisi[k].dur);
                }
            }
        }
    }
    int res = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < (1 << m); j++)
        {
            if (dp[i][j] < INF) res = std::max(res, f(j));
        }
    }
    return res;
}


double test0() {
	int p0 = 3;
	string t1[] = {"1 10 10" , "1 55 31", "10 50 100" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"1 2 10"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	TravellingPurchasingMan * obj = new TravellingPurchasingMan();
	clock_t start = clock();
	int my_answer = obj->maxStores(p0, p1, p2);
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
	int p0 = 3;
	string t1[] = {"1 10 10" , "1 55 30", "10 50 100" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"1 2 10"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	TravellingPurchasingMan * obj = new TravellingPurchasingMan();
	clock_t start = clock();
	int my_answer = obj->maxStores(p0, p1, p2);
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
	int p0 = 5;
	string t1[] = {"0 1000 17"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"2 3 400", "4 1 500", "4 3 300", "1 0 700", "0 2 400"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	TravellingPurchasingMan * obj = new TravellingPurchasingMan();
	clock_t start = clock();
	int my_answer = obj->maxStores(p0, p1, p2);
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

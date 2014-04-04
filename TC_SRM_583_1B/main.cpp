#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

struct node
{
    int x, y;
    node() {}
    node(int _x, int _y) {x = _x; y = _y;}
};
struct item
{
    int x, last;
    item() {}
    item(int _x, int _last) {x = _x; last = _last;}
};
const int N = 60;
bool imp[N][N], init[N][N];
vector<node>longest, tmp;
int road[N][N];
int n;
int last[N];
class TurnOnLamps {
public:
	int minimize(vector <int>, string, string);
};

void bfs(int start, int end)
{
    bool visit[N];
    memset(visit,0, sizeof(visit));
    int i, j, k;
    queue<item>q;
    q.push(item(start, -1));
    visit[start] = 1;
    last[start] = -1;
    bool found = false;
    while (!q.empty())
    {
        item tt = q.front(); q.pop();
        if (tt.x == end)
        {
            found = true;
            break;
        }
        for (i = 0; i <= n; i++)
        {
            if (visit[i]) continue;
            if (!road[i][tt.x]) continue;
            bool x1 = (init[tt.x][i] == 1 && imp[tt.x][i] == 1);
            if (!x1)
            {
                q.push(item(i, tt.x));
                visit[i] = 1;
                last[i] = tt.x;
            }
        }
    }
    if (found)
    {
        int u = end, v = last[end];
        while (v != -1)
        {
            if (init[u][v] == 0 && imp[u][v] == 1) tmp.push_back(node(u, v));
            u = v;
            v = last[v];
        }
    }
}

int TurnOnLamps::minimize(vector <int> roads, string initState, string isImportant) {
    memset(road, 0, sizeof(road));
    int i, j, k;
    n = roads.size();
    for (i = 0; i < n; i++)
    {
        int u = roads[i], v = i + 1;
        road[u][v] = road[v][u] = 1;
        init[u][v] = init[v][u] = initState[i] - '0';
        imp[u][v] = imp[v][u] = isImportant[i] - '0';
    }
    int ans = 0;
    while (true)
    {
        longest.clear();
        for (i = 0; i <= n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                tmp.clear();
                bfs(i, j);
                if (tmp.size() > longest.size()) longest = tmp;
            }
        }
        if (0 == longest.size()) break;
        ans += 1;
        for (i = 0; i < longest.size(); i++)
        {
            int x = longest[i].x, y = longest[i].y;
            init[x][y] = init[y][x] = 1;
        }
    }
    return ans;
}


double test0() {
	int t0[] = {0,0,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "0001";
	string p2 = "0111";
	TurnOnLamps * obj = new TurnOnLamps();
	clock_t start = clock();
	int my_answer = obj->minimize(p0, p1, p2);
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
	int t0[] = {0,0,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "0000";
	string p2 = "0111";
	TurnOnLamps * obj = new TurnOnLamps();
	clock_t start = clock();
	int my_answer = obj->minimize(p0, p1, p2);
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
	int t0[] = {0,0,1,1,4,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "000100";
	string p2 = "111111";
	TurnOnLamps * obj = new TurnOnLamps();
	clock_t start = clock();
	int my_answer = obj->minimize(p0, p1, p2);
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
double test3() {
	int t0[] = {0,0,1,1,4,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "100100";
	string p2 = "011101";
	TurnOnLamps * obj = new TurnOnLamps();
	clock_t start = clock();
	int my_answer = obj->minimize(p0, p1, p2);
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
double test4() {
	int t0[] = {0,0,2,2,3,1,6,3,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "010001110";
	string p2 = "000110100";
	TurnOnLamps * obj = new TurnOnLamps();
	clock_t start = clock();
	int my_answer = obj->minimize(p0, p1, p2);
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
double test5() {
	int t0[] = {0,0,1,2,4,4,6,1,2,5,2,8,8,3,6,4,14,7,18,14,11,7,1,12,7,5,18,23,0,14,11,10,2,2,6,1,30,11,9,12,5,35,25,11,23,17,14,45,15};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string p1 = "0000000000010000000000000010000010100000000000000";
	string p2 = "1010111111111011011111000110111111111111111110111";
	TurnOnLamps * obj = new TurnOnLamps();
	clock_t start = clock();
	int my_answer = obj->minimize(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 14;
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!

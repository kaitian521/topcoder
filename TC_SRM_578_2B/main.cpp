#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
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
int m, n;
long long mod = 1000000007;
long long ans = 0;
vector<string>v;
class GooseInZooDivTwo {
public:
	int count(vector <string>, int);
};
struct node
{
    int x, y;
    node(){}
    node(int _x, int _y){x = _x; y = _y;}
};
#define N 60
bool visit[N][N];
int dist;

int BFS(int start, int end)
{
    int cnt = 1;
    int i, j;
    int x, y;
    queue<node>q;
    q.push(node(start, end));
    visit[start][end] = 1;
    while(!q.empty())
    {
        node tt = q.front();
        q.pop();
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (abs(i - tt.x) + abs(j - tt.y) <= dist && !visit[i][j] && v[i][j] == 'v')
                {
                    q.push(node(i, j));
                    visit[i][j] = 1;
                    cnt ++;
                }

            }
        }
    }
    return cnt;
}
int store[N * N];
int GooseInZooDivTwo::count(vector <string> _field, int _dist) {
	m = _field.size();
	n = _field[0].size();
	v = _field;
	dist = _dist;
	memset(visit, 0, sizeof(visit));
	ans = 1;
	int cnt = 0, i, j;
	for (i = 0; i < m; i++)
	{
	    for (j = 0; j < n; j++)
	    {
	        if (_field[i][j] == '.' || visit[i][j]) continue;
	        store[cnt++] = BFS(i, j);
	    }
	}
	if(cnt == 0) return 0;
	for (i = 0; i < cnt; i++)
	{
	    ans *= 2;
	    //cout << store[i] << endl;
	    ans %= mod;
	}
	return (int)ans - 1;
}

double test0() {
	string t0[] = {"vvv"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 0;
	GooseInZooDivTwo * obj = new GooseInZooDivTwo();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1);
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

int main()
{
    test0();
    return 0;
}

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <map>
#include <math.h>
#include <set>
#include <queue>
#include <stdlib.h>
using namespace std;
#define N 100
vector<string>v;
bool visit[N][N];
int m, n;
bool dfs(int L, int x, int y)
{
	if (x == m - 1) return true;
	if (visit[x][y]) return false;
	visit[x][y] = 1;
	int i, j, k;
	for (i = 0; i < m; i++)
	{		
		if (abs(x - i) > L) continue;
		if (v[i][y] == '.') continue;
		if (dfs(L, i, y)) return true;
	}
	for (i = x; i <= x; i++)
	{
		for (k = y - 1; k >= 0; k--)
		{
			if (v[i][k] == '.') break;
			if (dfs(L, i, k)) return true;
			
		}
		for (k = y + 1; k < n; k++)
		{
			if (v[i][k] == '.') break;
			if (dfs(L, i, k)) return true;
		}
	}
	return 0;
}

class ArcadeManao
{
public:
	int shortestLadder(vector <string> level, int coinRow, int coinColumn)
	{
		int i, j, k;
		m = level.size(), n = level[0].length();
		v = level;
		for (i = 0; i <= m; i++)
		{
			memset(visit, 0, sizeof(visit));
			if (dfs(i, coinRow-1, coinColumn-1)) return i;
		}
		return n;
	}
};

int main(int argc, char **argv)
{
	string str[] = {"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"};
	vector<string>vv(str, str + 6);
	ArcadeManao a;
	cout << a.shortestLadder(vv, 1, 3) << endl;
	getchar();
	return 0;
}

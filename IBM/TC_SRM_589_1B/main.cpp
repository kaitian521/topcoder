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
struct state
{
    char id;
    int length;
    unsigned short statee;
    bool operator < (state ttt2) const
    {
        return this->length < ttt2.length;
    }
    state(){}
    state(unsigned short _statee, char _id, int _length){statee = _statee; id = _id; length = _length;}
};
vector<node>edge[52];

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
void dfs(int id, int st, int length)
{
    if (dp[id][st] <= length) return;
    dp[id][st] = length;
    dp[N][st] = 1;
    int i, j, k;
    for (i = 0; i < edge[id].size(); i++)
    {
        int u = edge[id][i].v;
        int dis = edge[id][i].dis + length;
        if (yisi[u].close >= dis)
        {
            int tt = std::max(dis, yisi[u].open);
            //q.push(state(st | (1 << u), u, tt + yisi[u].dur));
            dfs(st | (1 << u), u, tt + yisi[u].dur);
        }
    }
}
int TravellingPurchasingMan::maxStores(int _N, vector <string> interestingStores, vector <string> roads) {
	int INF = 604800 * 100;
	N = _N;
	memset(dp, -1, sizeof(dp));
	yisi.clear();
	m = interestingStores.size();
	int i, j, k;
	for (i = 0; i < 52; i++)for (j = 0; j < 52; j++)bian[i][j] = INF;
	for (i = 0; i < 52; i++)edge[i].clear();
	for (i = 0; i < roads.size(); i++)
    {
        int start, end, dis;
        sscanf(roads[i].c_str(), "%d %d %d", &start, &end, &dis);
        bian[start][end] = bian[end][start] = dis;
    }
    //floyd
    for (k = 0; k < 52; k++)
    {
    	for (i = 0; i < 52; i++)
    	{
    		for (j = 0; j < 52; j++)
    		{
    			if (bian[i][j] > bian[i][k] + bian[k][j]) bian[i][j] = bian[i][k] + bian[k][j];
    		}
    	}
    }
    for (i = 0; i < m; i++)
    {
    	for (j = 0; j < m; j++)
    	{
    		if (bian[i][j] != INF) edge[i].push_back(node(j, bian[i][j]));
    	}
    }
    for (j = 0; j < m; j++)
    {
    	if (bian[N - 1][j] != INF) edge[N - 1].push_back(node(j, bian[N - 1][j]));
    }
    if (m == N)
    {
        edge[N].push_back(node(N - 1, 0));
        for (i = 0; i < edge[N - 1].size(); i++)
        {
            edge[N].push_back(node(edge[N - 1][i].v, edge[N - 1][i].dis));
        }
        N += 1;
    }
    for (i = 0; i < m; i++)
    {
        int open, close, dur;
        sscanf(interestingStores[i].c_str(), "%d %d %d", &open, &close, &dur);
        yisi.push_back(item(open, close, dur));
    }

    queue<state>q;
    q.push(state(0, N - 1, 0));
    int count = 0;
    while( !q.empty())
    {
        count ++;
    	state s = q.front(); q.pop();
    	int id = s.id;
        int st = s.statee;
        int length = s.length;
        dp[N][st] = 1;
        if (dp[id][st] <= length) continue;
        dp[id][st] = length;
        for (i = 0; i < edge[id].size(); i++)
        {
        	int u = edge[id][i].v;
            int dis = edge[id][i].dis + length;
            if (yisi[u].close >= dis)
            {
            	int tt = std::max(dis, yisi[u].open);
            	if(!( (st >> u) & 1) && dp[u][st | (1 << u)] > tt + yisi[u].dur)q.push(state(st | (1 << u), u, tt + yisi[u].dur));
            }
        }
    }
    cout << count << endl;
    //dfs(N - 1, 0, 0);
    int ans = 0;
    for (i = 0; i < (1 << 16) + 1; i++)
    {
        if (dp[N][i] < INF)
        {
            ans = std::max(ans, f(i));
        }
    }
    return ans;
}
double test0() {
//    {50, {"96 604763 201", "76 604782 599", "35 604789 707", "45 604709 781", "34 604731 485", "87 604730 67", "22 604705 864", "62 604742 511", "52 604774 66", "95 604729 94", "80 604759 843", "62 604708 466", "72 604796 894", "26 604766 606", "83 604730 773", "15 604744 553"}, {"0 1 94", "1 2 18", "2 3 22", "3 4 100", "4 5 97", "5 6 98", "6 7 39", "7 8 2", "8 9 88", "9 10 74", "10 11 85", "11 12 32", "12 13 89", "13 14 52", "14 15 40", "15 16 64", "16 17 84", "17 18 52", "18 19 64", "19 20 85", "20 21 6", "21 22 84", "22 23 11", "23 24 8", "24 25 21", "25 26 38", "26 27 46", "27 28 40", "28 29 12", "29 30 57", "30 31 57", "31 32 86", "32 33 72", "33 34 83", "34 35 79", "35 36 67", "36 37 9", "37 38 97", "38 39 88", "39 40 65", "40 41 74", "41 42 81", "42 43 17", "43 44 60", "44 45 99", "45 46 3", "46 47 58", "47 48 37", "48 49 41", "49 38 67"}}
	int p0 = 50;
	string t1[] = {"96 604763 201", "76 604782 599", "35 604789 707", "45 604709 781", "34 604731 485", "87 604730 67", "22 604705 864", "62 604742 511", "52 604774 66", "95 604729 94", "80 604759 843", "62 604708 466", "72 604796 894", "26 604766 606", "83 604730 773", "15 604744 553"};;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"0 1 94", "1 2 18", "2 3 22", "3 4 100", "4 5 97", "5 6 98", "6 7 39", "7 8 2", "8 9 88", "9 10 74", "10 11 85", "11 12 32", "12 13 89", "13 14 52", "14 15 40", "15 16 64", "16 17 84", "17 18 52", "18 19 64", "19 20 85", "20 21 6", "21 22 84", "22 23 11", "23 24 8", "24 25 21", "25 26 38", "26 27 46", "27 28 40", "28 29 12", "29 30 57", "30 31 57", "31 32 86", "32 33 72", "33 34 83", "34 35 79", "35 36 67", "36 37 9", "37 38 97", "38 39 88", "39 40 65", "40 41 74", "41 42 81", "42 43 17", "43 44 60", "44 45 99", "45 46 3", "46 47 58", "47 48 37", "48 49 41", "49 38 67"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	TravellingPurchasingMan * obj = new TravellingPurchasingMan();
	clock_t start = clock();
	int my_answer = obj->maxStores(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 16;
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
int main()
{
    test0();
    return 0;
}
//Powered by [KawigiEdit] 2.0

#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
#define N 110
int v[N][N];
bool visit[N][N], hash[N];
int n, m;

struct node
{
    int x, y, value;
    node(){}
    node(int _x, int _y, int _value){x = _x; y = _y; value = _value;}
};
bool cmp(node t1, node t2)
{
    return t1.value < t2.value;
}

vector<node>p;
bool f()
{
    int i, j, k;
    bool flag;
    map<int, int>row[N], colomn[N];
    map<int, int>::iterator it;
    memset(visit, 0, sizeof(visit));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            row[i][ v[i][j] ] ++;
            colomn[j][ v[i][j] ] ++;
        }
    }
    int cnt = 0;
    for (i = 0; i < m * n; i++)
    {
        int x = p[i].x, y = p[i].y, value = p[i].value;
        if (visit[x][y]) continue;
        if (row[x].size() == 1)
        {
            for (j = 0; j < m; j++)
            {
                if (!visit[x][j])
                {
                    colomn[j][ v[x][j] ] --;
                    if (colomn[j][ v[x][j] ] == 0)
                    {
                        it = colomn[j].find(v[x][j]);
                        colomn[j].erase(it);
                    }
                    visit[x][j] = 1;
                }
            }
            flag = 1;
        }
        if (colomn[y].size() == 1)
        {
            for (j = 0; j < n; j++)
            {
                if (!visit[j][y])
                {
                    row[j][ v[j][y] ] --;
                    if (row[j][ v[j][y] ] == 0)
                    {
                        it = row[j].find(v[j][y]);
                        row[j].erase(it);
                    }
                    visit[j][y] = 1;
                }
            }
            flag = 1;
        }
        if (!flag) return false;
    }
    return true;
}

int main()
{
    freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int T, i, j, id = 1;
    cin>> T;
    while(T--)
    {
        cin>>n>>m;
        memset(hash, 0, sizeof(hash));
        p.clear();
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
            {
                scanf("%d", &v[i][j]);
                p.push_back(node(i, j, v[i][j]));
            }
        sort(p.begin(), p.end(), cmp);
        printf("Case #%d: ", id++);
        if(f()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

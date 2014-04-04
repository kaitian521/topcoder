#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <algorithm>
#include <stdio.h>
using namespace std;

vector<int> magicPower;
vector<string> magicBond;
struct node
{
    int x, y;
    node(){}
    node(int _x, int _y){x = _x; y = _y;}
};
vector<node>edge;

int n, k;
int ans = -1;

void dfs(int id, long long state, int select)
{
    int i, j;
    int val = 0;
    if (select > k) return;
    if (id == n)
    {
        vector<int>v;
        for (i = 0; i < n; i++)
        {
            if ( (state >> i) & 1) val += magicPower[i];
            else v.push_back(magicPower[i]);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for (i = 0; i < k - select; i++)
        {
            val += v[i];
        }
        ans = max(ans, val);
        return;
    }
    int start = edge[id].x;
    int end = edge[id].y;
    if (  !((state >> start) & 1) && !((state >> end) & 1) )
    {
        dfs(id + 1, state | (1 << start), select + 1);
        dfs(id + 1, state | (1 << end), select + 1);
    }
    else dfs(id + 1, state, select);
}

class MagicMoleculeEasy
{
public:
    int maxMagicPower(vector<int> _magicPower, vector<string> _magicBond, int _k)
    {
        k = _k;
        magicPower = _magicPower;
        magicBond = _magicBond;
        n = magicPower.size();
        int i, j;
        for (i = 0; i < _magicBond.size(); i++)
        {
            for (j = 0; j < _magicBond[0].size(); j++)
            {
                if (_magicBond[i][j] == 'Y') edge.push_back(node(i, j));
            }
        }
        dfs(0, 0, 0);
        return ans;
    }
};

int main()
{
    n = 4;
    MagicMoleculeEasy T;
    int arr1[] = {4, 7, 5, 8};
    vector<int>v1(arr1, arr1 + n);
    string arr2[] = {"NYNY",
 "YNYN",
 "NYNY",
 "YNYN"};
    vector<string>v2(arr2, arr2 + n);
    cout << T.maxMagicPower(v1, v2, 2) << endl;
	return 0;
}

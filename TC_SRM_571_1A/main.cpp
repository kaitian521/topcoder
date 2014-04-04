#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <stdio.h>
using namespace std;
vector<string>ans;
int n;
void dfs(int val)
{
    if (val > n) return;
    if (ans.size() >= n || ans.size() >= 50) return;
    char s[100];
    sprintf(s, "%d", val);
    string str = s;
    str += ".mp3";
    ans.push_back(str);
    for (int i = 0; i < 9; i++)
    {
        if (val * 10 + i <= n) dfs(val * 10 + i);
    }
    dfs(val + 1);
}
class FoxAndMp3
{
public:
    vector<string> playList(int _n)
    {
        n = _n;
        dfs(1);
        return ans;
    }
};
int main()
{
    FoxAndMp3 x;
    x.playList(297);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
	return 0;
}

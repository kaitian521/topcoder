#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
   char x, y;
   int id;
   node(char _x, char _y, int _id) {x = _x; y = _y; id = _id;}
   node(){x = 0; y = 0;}
};
bool cmp(node t1, node t2)
{
    if (t1.x == t2.x)
    {
        if (t1.y == t2.y) return t1.id < t2.id;
        else return t1.y > t2.y;
    }
    return t1.x > t2.x;
}
vector<node>v;
class TheLargestString
{
public:
    string find(string s, string t)
    {
        int len = s.length();
        int i, j, k;
        for (i = 0; i < len; i++)
        {
            v.push_back(node(s[i], t[i], i));
        }
        sort(v.begin(), v.end(), cmp);
        for (i = 0; i < v.size(); i++)
        {
            cout << v[i].x << v[i].y << v[i].id << endl;
        }
        i = 0;
        int maxid = -1;
        string ans = "";
        vector<int>vv;
        while (i < len)
        {
            if (v[i].id <= maxid){i ++; continue;}
            vv.push_back(i);
            j = i + 1;
            maxid = std::max(maxid, v[i].id);
            while (j < len && v[j].x == v[i].x && v[j].y == v[i].y)
            {
                if (v[j].id > maxid) {vv.push_back(j); maxid = std::max(maxid, v[j].id);}
                j ++;
            }
            i = j;
        }
        for (i = 0; i < vv.size(); i++) ans += v[vv[i]].x;
        for (i = 0; i < vv.size(); i++) ans += v[vv[i]].y;
        return ans;
    }
};

int main()
{
    TheLargestString T;
    cout << T.find("abacaba", "zzzaaaa") << endl;
    return 0;
}

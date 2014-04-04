#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int>cubes;
int B;
int w;
vector<string>views;
int maxx(int x, int y)
{
    return (x > y)? x : y;
}
int minn(int x, int y)
{
    return (x < y)? x : y;
}

int process(int pos1, int pos2, int len)
{
    int i, j;
     int ans = 100000;
    for (i = 0; i < len; i += 2)
    {
	int y = pos2 - (len + 1 - i);
	if (y >=0) ans = minn(ans, y);
    }
    return ans;
}
string f(string str)
{
    bool up = 0;
    int i, j;
    int color[3] = {0};
    int rest[3];
    rest[0] = cubes[0], rest[1] = cubes[1], rest[2] = cubes[2];
    int BB = 0;
    vector<int>need;
    int now_w = 0;
    for (i = 0; i < str.size(); )
    {
        if (up == 1)now_w ++;
        up = 0;
        if (str[i] != 'b')
        {
            color[str[i] - '0'] ++;
            i ++;
        }
        else
        {
            j = i;
            while (j < str.size() && str[j] == 'b') j ++;
            int len = j - i;
            if ( len % 2 == 0)
            {
                BB += len / 2;
                i = j;
            }
            else
            {
                BB += (len + 1) / 2;
                if (i == 0 && len == 1) return "invalid";
                need.push_back(process(i, j, len));
                now_w += 1;
                i = j;
                up = 0;
            }
        }
    }
        rest[0] -= color[0];
        rest[1] -= color[1];
        rest[2] -= color[2];
        cout << rest[0] << "\t";
        cout << rest[1] << "\t";
        cout << rest[2] << endl;
        if (rest[0] < 0 || rest[2] < 0 || rest[1] < 0) return "invalid";
        int restBB = B - BB;
        cout << restBB << endl;
        if (restBB < 0) return "invalid";

        if (now_w >= w) return "invalid";
        int sum = 0;
        for (i = 0; i < need.size(); i++)
        {
        	cout << need[i] << "\t";
            if (restBB > 0 && need[i] >= 2)
            {
                int tt = minn(restBB, need[i] / 2);
                restBB -= tt;
                sum += (need[i] - tt * 2);
            }
            else
            {
                sum += need[i];
            }
        }
        cout << "###########################################" << sum << endl;
        int act = rest[0] + rest[1] + rest[2];
        if (act < sum) return "invalid";
    return "valid";
}

class SkewedPerspectives
{
public:
    vector <string> areTheyPossible(vector <int> _cubes, int _B, int _w, vector <string> _views)
    {
        vector<string>vs;
        cubes = _cubes;
        B = _B;
        w = _w;
        views = _views;
        int i, j, k;
        for (i = 0; i < views.size(); i++)
        {
            vs.push_back(f(_views[i]));
        }
        return vs;
    }
};

int mxain()
{
    cout << "Hello world!" << endl;
    return 0;
}

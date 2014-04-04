#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <set>
#include <map>
#include <math.h>
#define MOD (long long)1000000007L
#define LL long long
using namespace std;

struct node
{
    int value;
    int step;
    node(int _value, int _step)
    {
        value = _value; step = _step;
    }
    node(){value = 0; step = 0;}
};
node tt;
char s[100];
int rever(int x)
{
    sprintf(s, "%d", x);
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++)
    {
        swap(s[i], s[len - 1 - i]);
    }
    return atoi(s);
}
map<int, int> mm;
class TheNumberGameDiv2
{
public:
    int minimumMoves(int A, int B)
    {
        queue<node>q;
        mm[A] = 0;
        q.push(node(A, 0));
        while ( !q.empty())
        {
            tt = q.front(), q.pop();
            if (tt.value == B) return tt.step;
            int t1 = rever(tt.value);
            if (mm.find(t1) == mm.end()){
            q.push(node(t1, tt.step + 1));
            mm[t1] = 1;
            }
            int t2 = tt.value / 10;
            if (mm.find(t2) == mm.end()){
            q.push(node(t2, tt.step + 1));
            mm[t2] = 1;
            }
        }
        return -1;
    }
};
int main()
{
    TheNumberGameDiv2 T;
    cout << T.minimumMoves(25, 5) << endl;
    return 0;
}

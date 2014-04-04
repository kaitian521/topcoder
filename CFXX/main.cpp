#include <iostream>
#include <vector>
#include <stdio.h>
#define N 1011000
using namespace std;
bool a[2 * N], b[2 * N];
char s[2 * N];
int tie = 0, aa = 0, bb = 0;

void f()
{
    if (tie % 2 == 0)
    {
        if (aa == bb || bb - aa == 1) {cout << "Draw" << endl; return;}
        if (aa - bb >= 1) {cout << "First" << endl; return;}
        cout << "Second" << endl;
        return;
    }
    else
    {
        if (aa >= bb) {cout << "First" << endl; return;}
        if (bb - aa >= 3) {cout << "Second" << endl; return;}
        cout << "Draw" << endl;
        return;
    }
}

int main()
{
    int n, i, j;
    cin >> n;
    scanf("%s", s);
    for (i = 0; i < 2 * n; i++) a[i] = s[i] - '0';
    scanf("%s", s);
    for (i = 0; i < 2 * n; i++) b[i] = s[i] - '0';

    for (i = 0; i < 2 * n; i++)
    {
        if (a[i] && b[i]) tie ++;
        else if (a[i]) aa ++;
        else if (b[i]) bb ++;
    }
    f();
    return 0;
}

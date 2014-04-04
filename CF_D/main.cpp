#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <stdio.h>
#define N 100010
using namespace std;
#define N 200000
long long a[N],b[N];
int m, n, k;

bool f()
{
    int i, len = std::min(m, n);
    for (i = 1; i <= len; i++)
    {
        if (a[m - i] > b[n - i]) return true;
    }
    if (m > n) return true;
    return false;
}
int main()
{
    cin >> m >> n >> k;
    int i;
    for (i = 0; i < m; i++) scanf("%I64d", &a[i]);
    for (i = 0; i < n; i++) scanf("%I64d", &b[i]);
    sort(a, a + m);
    sort(b, b + n);
    if (f()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

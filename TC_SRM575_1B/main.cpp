#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;
#define N 1000010
char ch[N];
int n;
double p[N];
class TheSwapsDivOne
{
public:
    double find(vector <string> sequence, int k)
    {
        int i, j;
        long long sum = 0;
        for(i = 0; i < sequence.size(); i++)
        {
            for (j = 0; j < sequence[i].size(); j++)
            {
                ch[n++] = sequence[i][j] - '0';
                sum += sequence[i][j] - '0';
            }
        }
        p[0] = 1.0;
        for (i = 1; i <= k; i++)
        {
            p[i] = p[i - 1] * (1.0 - 2.0 / n ) + 2.0 * (1.0 - p[i - 1]) / ( n * (n - 1.0) );
            cout << "p[i] = " << p[i] << endl;
        }
        double ans = 0;
        for (i = 0; i < n; i++)
        {
            int cnt = i * (n - i - 1) + n;
            printf ("cnt[%d] = %d\n", i, cnt);
            int tmp = n * (n + 1);
            ans += (2.0 * cnt) * (p[k] * ch[i] + (1.0 - p[k]) * (1.0 * sum - ch[i]) / (n - 1.0) ) / tmp;
        }
        return ans;
    }
};
int main()
{
    string str[] = {"4", "77"};
    vector<string>v(str, str + 2);
    TheSwapsDivOne x;
    cout << x.find(v, 47) << endl;
    return 0;
}

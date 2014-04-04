#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define EPS 1e-10
#define N 100
class ShuffleSort
{
public:
    double shuffle(vector <int> cards)
    {
        for (int k = 0; k < cards.size(); k++) cout << cards[k] << endl;
        int n = cards.size();
        vector<int>v;
        for (int k = 0; k < n; k++) v.push_back(cards[k]);
        sort(v.begin(), v.end());
        for (int k = 0; k < n; k++) cout << v[k] << endl;
        int a[N];
        bool flag = false;
        int i, j;
        double ans = 0;
        for (i = 0; i < n; i++)
        {
            j = i + 1;
            while (j < n && v[j] == v[i]) j++;
            if (j == n) goto L;
            if (flag) ans += 1.0 * (n - i) / (j - i) - 1;
            else
            {
                ans += 1.0 * (n - i) / (j - i);
                flag = true;
            }
        }
 L:       return (ans <= EPS) ?  1.0 : ans;
    }
};
int main()
{
    int a[] = {1, 2, 3};
    vector<int>v(a, a + 3);
    ShuffleSort x;
    cout << x.shuffle(v) << endl;
    return 0;
}

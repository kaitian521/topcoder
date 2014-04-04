#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
#define ll long long
#define myabs(a) (a < 0)? -a : a
#define INF (ll)10
class TheArray
{
public:
	int find(int n, int d, int first, int last)
	{
	    if (d == 0) return first;
	    ll mid, rightt, leftt;
	    leftt = std::min(first, last) + 1;
	    rightt = INF;
	    while (leftt <= rightt)
	    {
	    	mid = (leftt + rightt) / 2;
	    	ll tt = (myabs(mid - first) + d - 1) / d + (myabs(mid - last) + d - 1) / d;
	    	if (tt <= n - 1) leftt = mid + 1;
	    	else rightt = mid - 1;
	    }
	    return std::max(std::max((int)rightt, first), last);
	}
};

int main()
{
    TheArray x;
    cout << x.find(3, 5, 2, 4) << endl;
    return 0;
}

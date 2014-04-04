#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class PrimalUnlicensedCreatures {
public:
	int maxWins(int, vector <int>);
};

int PrimalUnlicensedCreatures::maxWins(int initialLevel, vector <int> g) {
	int i;
	sort(g.begin(), g.end());
	int ans = 0, power = initialLevel;
	for (i = 0; i < g.size(); i++)
    {
        if (power > g[i])
        {
            ans ++;
            power += g[i] / 2;
        }
    }
    return ans;
}

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
#include <string.h>
#include <stdio.h>
#include <string>
using namespace std;

const int N = 1010;
int dp[N][N];

class JumpFurther {
public:
	int furthest(int, int);
};

int JumpFurther::furthest(int n, int badStep) {
	bool flag = 0;
	int i, j, k;
	for (i = 1; i <= N; i++)
	{
	    if (badStep == i * (i + 1) / 2)
	    {
	        flag = 1;
	        break;
	    }
	    else if (badStep < i * (i + 1) / 2)
	    {
	        break;
	    }
	}
	if (!flag) return n * (n + 1) / 2;
	return n * (n + 1) / 2 - 1;
}
//Powered by [KawigiEdit] 2.0!

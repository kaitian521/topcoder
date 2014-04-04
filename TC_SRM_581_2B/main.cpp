#include <vector>
#include <list>
#include <map>
#include <string.h>
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
const int N = 51;
int dp[N];
int cnt[N];
int rep[N];
int n, L;
vector<int>report;
class SurveillanceSystem {
public:
	string getContainerInfo(string, vector <int>, int);
};

int f(int id)
{
    int count;
    int i, j, k;
    int can = 0;
    for (i = 0; i <= L; i++)
    {
        if (cnt[i] == 0 || rep[i] == 0) continue;
        count = 0;
        for (j = 0; j <= n - L; j++)
        {
            if (id >= j && id <= j + L - 1 && dp[j] == i) count ++;
        }
        if (count) can = 1;
        cout << count << endl;
        if (rep[i] > cnt[i] - count) return '+';
    }
    return (can) ? '?' : '-';
}

string SurveillanceSystem::getContainerInfo(string containers, vector <int> _reports, int _L) {
    report = _reports;
    L = _L;
    n = containers.size();
    memset(cnt, 0, sizeof(cnt));
    memset(rep, 0, sizeof(rep));
    string ans = "";
    int i, j, k;
    for (i = 0; i <= n - L; i++)
    {
        dp[i] = 0;
        for (j = i; j < i + L; j++)
        {
            dp[i] += (containers[j] == 'X');
        }
        //cout << dp[i] << endl;
        cnt[dp[i]] += 1;
    }
    for (i = 0; i < report.size(); i++) rep[report[i]] += 1;
    for (i = 0; i < n; i++)
    {
        ans += f(i);
    }
    return ans;
}
//Powered by [KawigiEdit] 2.0!

double test2() {
	string p0 = "------X-XX-";
	int t1[] = {3, 0, 2, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 5;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "++++++++++?";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
int main()
{
    test2();
}

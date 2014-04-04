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
using namespace std;
const int N = 55;
bool used[N][N];
int heng[N][N], lie[N][N];
int m, n;
vector<string>v;
class ToyTrain {
public:
	int getMinCost(vector <string>);
};

int process(int startx, int starty)
{
    int i, j, k;
    int dir = 0;
    int will = 1 - v[startx][starty] + 'A';
    used[startx][starty] = 1;
    int nowx =  startx, nowy = starty;
    int x, y;
    while (1)
    {
        if (dir == 0)
        {
            dir = 1;
            y = heng[nowx][nowy];
            if (y > nowy)
            {
                for (i = nowy + 1; i <= y; i++)
                {
                    if (used[nowx][i]) return -1;
                    used[nowx][i] = 1;
                }
            }
            else
            {
                for (i = y; i < nowy; i++)
                {
                    if (used[nowx][i]) return -1;
                    used[nowx][i] = 1;
                }
            }
            nowy = y;
        }
        else if (dir == 1)
        {
            dir = 0;
            x = lie[nowx][nowy];
            int cha = 0;
            if (x == startx && nowy == starty) cha = 1;
            if (x > nowx)
            {
                for (i = nowx + 1; i <= x - cha; i++)
                {
                    if (used[i][nowy]) return -1;
                    used[i][nowy] = 1;
                }
            }
            else
            {
                for (i = x + cha; i < nowx; i++)
                {
                    if (used[i][nowy]) return -1;
                    used[i][nowy] = 1;
                }
            }
            nowx = x;
            if (cha == 1) return 0;
        }
    }
    return 0;
}

int ToyTrain::getMinCost(vector <string> field) {
	memset(used, 0, sizeof(used));
	memset(heng, -1, sizeof(heng));
	memset(lie, -1, sizeof(lie));
	m = field.size(); n = field[0].size();
	v = field;
	int cntA = 0, cntB = 0, cnt = 0;
	int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i][j] == 'A') cntA += 1;
            else if (v[i][j] == 'B') cntB += 1;
        }
    }
    if (cntA + cntB == 0 || cntA != cntB) return -1;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i][j] != 'A' && v[i][j] != 'B') continue;
            if (heng[i][j] == -1)
            {
                bool flag = 0;
                for (k = j + 1; k < n; k++)
                {
                    if (v[i][k] != 'A' && v[i][k] != 'B') continue;
                    if (v[i][k] == v[i][j]) return -1;
                    flag = 1;
                    heng[i][j] = k;
                    heng[i][k] = j;
                    break;
                }
                if (!flag) return -1;
            }
            if (lie[i][j] == -1)
            {
                bool flag = 0;
                for (k = i + 1; k < m; k++)
                {
                    if (v[k][j] != 'A' && v[k][j] != 'B') continue;
                    if (v[i][j] == v[k][j]) return -1;
                    flag = 1;
                    lie[i][j] = k;
                    lie[k][j] = i;
                    break;
                }
                if (!flag) return -1;
            }
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (!used[i][j] && (v[i][j] == 'A' || v[i][j] == 'B'))
            {
                int ret = process(i, j);
                if (ret == -1) return -1;
            }
        }
    }
    bool pay[10];
    memset(pay, 0, sizeof(pay));
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (v[i][j] == 'S' && !used[i][j]) return -1;
            if (used[i][j] && v[i][j] >= '0' && v[i][j] <= '9')
            {
                if (!pay[v[i][j] - '0'])
                {
                    cnt += v[i][j] - '0';
                    pay[ v[i][j] - '0' ] = 1;
                }
            }
        }
    }
    return cnt;
}
//Powered by [KawigiEdit] 2.0!



double test0() {
	string t0[] = {"BA",
 "SS",
 "AB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ToyTrain * obj = new ToyTrain();
	clock_t start = clock();
	int my_answer = obj->getMinCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ToyTrain * obj = new ToyTrain();
	clock_t start = clock();
	int my_answer = obj->getMinCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"ABBA",
 "BAAB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ToyTrain * obj = new ToyTrain();
	clock_t start = clock();
	int my_answer = obj->getMinCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"AA",
 "AA"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ToyTrain * obj = new ToyTrain();
	clock_t start = clock();
	int my_answer = obj->getMinCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"..AB",
 "B..A",
 "....",
 "A.B."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ToyTrain * obj = new ToyTrain();
	clock_t start = clock();
	int my_answer = obj->getMinCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"A1B8A2B",
 "16A.B22",
 "BAB.9.A",
 "ABA.7.B",
 "B12345A"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ToyTrain * obj = new ToyTrain();
	clock_t start = clock();
	int my_answer = obj->getMinCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 31;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	string t0[] = {"..A.B",
 ".1.2.",
 "A.B..",
 ".3.4.",
 "B...A"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ToyTrain * obj = new ToyTrain();
	clock_t start = clock();
	int my_answer = obj->getMinCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test7() {
	string t0[] = {"ASBSBSA",
 "S.S.S.S",
 "BSASASB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ToyTrain * obj = new ToyTrain();
	clock_t start = clock();
	int my_answer = obj->getMinCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;

	time = test5();
	if (time < 0)
		errors = true;

	time = test1();
	if (time < 0)
		errors = true;

	time = test2();
	if (time < 0)
		errors = true;

	time = test3();
	if (time < 0)
		errors = true;

	time = test4();
	if (time < 0)
		errors = true;

	time = test5();
	if (time < 0)
		errors = true;

	time = test6();
	if (time < 0)
		errors = true;

	time = test7();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}


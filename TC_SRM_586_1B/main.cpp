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

struct node
{
    int x, y;
    node(){x = 0; y = 0;}
    node(int _x, int _y) {x = _x; y = _y;}
};
vector<node>dy[100];
int n;
class History {
public:
	string verifyClaims(vector <string>, vector <string>, vector <string>);
};
bool can[100][100];
int minn[100][100];
int maxx[100][100];

string History::verifyClaims(vector <string> dynasties, vector <string> battles, vector <string> queries) {
    memset(can, 0, sizeof(can));
	string battle = accumulate(battles.begin(), battles.end(), string(""));
	n = dynasties.size();
	int i, j, k;
	int INF = 10000000;
	for (i = 0; i < 100; i++)
    {
        for (j = 0; j < 100; j++)
        {
            minn[i][j] = INF;
            maxx[i][j] = INF;
        }
    }
	for (i = 0; i < dynasties.size(); i++)
    {
        dy[i].clear();
        stringstream s;
        int str[10];
        int ss;
        j = 0;
        s << dynasties[i];
        while (s >> ss)
        {
            str[j++] = ss;
            cout << ss << " ";
        }
        for (k = 0; k < j - 1; k++)
        {
            dy[i].push_back(node(str[k], str[k + 1] - 1));
        }
        cout << endl;
    }
    stringstream ss;
    ss << battle;
    string ttt;
    while (ss >> ttt)
    {
        int id1 = ttt[0] - 'A';
        int id2 = ttt[3] - 'A';
        int king1 = ttt[1] - '0';
        int king2 = ttt[4] - '0';
        can[id1][id2] = 1;
        can[id2][id1] = 1;
        int x1 = dy[id1][king1].x;
        int y1 = dy[id1][king1].y;
        int x2 = dy[id2][king2].x;
        int y2 = dy[id2][king2].y;
        minn[id1][id2] = -(x2 - y1);
        minn[id2][id1] = -(y1 - x2);
        maxx[id1][id2] = y2 - x1;
        maxx[id2][id1] = x1 - y2;
    }
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (!can[i][k] || !can[j][k]) continue;
                can[i][j] = can[j][i] = 1;
                minn[i][j] = std::min(minn[i][j], minn[i][k] + minn[k][j]);
                minn[j][i] = -minn[i][j];
                maxx[i][j] = std::min(maxx[i][j], maxx[i][k] + maxx[k][j]);
                maxx[j][i] = -maxx[i][j];
            }
        }
    }
    string res = "";
    for (i = 0; i < queries.size(); i++)
    {
        string ttt = queries[i];
        int id1 = ttt[0] - 'A';
        int id2 = ttt[3] - 'A';
        int king1 = ttt[1] - '0';
        int king2 = ttt[4] - '0';
        if (!can[id1][id2])
        {
            res += "N";
        }
        else
        {
            res += 'X';
        }
    }
    return res;
}
//Powered by [KawigiEdit] 2.0!


double test0() {
	string t0[] = {"1 2 4",
 "1 2 3"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"A1-B0"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"A0-B0",
 "A0-B1",
 "A1-B0",
 "A1-B1"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	History * obj = new History();
	clock_t start = clock();
	string my_answer = obj->verifyClaims(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "NNYY";
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
double test1() {
	string t0[] = {"1000 2000 3000 10000",
 "600 650 2000",
 "1 1001 20001"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"B1-C0 A0-B0 A2-C1 B1-C1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"A0-B1",
 "A1-B1",
 "A2-B1",
 "C0-A0",
 "B0-A2",
 "C1-B0"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	History * obj = new History();
	clock_t start = clock();
	string my_answer = obj->verifyClaims(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "YYYYNN";
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
double test2() {
	string t0[] = {"1 4 5",
 "10 13 17"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"A0-B0 A0-B0 B0-A0"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"A1-B0",
 "A0-B1",
 "A1-B1"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	History * obj = new History();
	clock_t start = clock();
	string my_answer = obj->verifyClaims(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "YYY";
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
double test3() {
	string t0[] = {"1 5 6",
 "1 2 5"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"A0",
 "-B0 A",
 "1-B1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"A0-B0",
 "A1-B0",
 "A0-B1",
 "A1-B1"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	History * obj = new History();
	clock_t start = clock();
	string my_answer = obj->verifyClaims(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "YNYY";
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
double test4() {
	string t0[] = {"2294 7344","366 384 449 965 1307 1415","307 473 648 688 1097","1145 1411 1569 2606","87 188 551 598 947 998 1917 1942"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"A0-B4 B4-E2 B3-E2 D2-E4 A0-E4 B1-C3 A0-E3 A0-E6 D0","-E2 B2-E1 B4-E3 B4-D0 D0-E3 A0-D1 B2-C3 B1-C3 B4-E","3 D0-E1 B3-D0 B3-E2"}
;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"A0-C2","E6-C2","A0-E4","B3-C1","C0-D2","B0-C1","D1-C3","C3-D0","C1-E3","D1-A0"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	History * obj = new History();
	clock_t start = clock();
	string my_answer = obj->verifyClaims(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "YNYNNYNNNY";
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

int main() {
	int time;
	bool errors = false;

	time = test0();
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

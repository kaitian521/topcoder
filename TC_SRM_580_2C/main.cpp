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
const int INF = 55 * 55 * 10 + 100;
const int N = 55;
int n, m;
int dp[N][N];
class WallGameDiv2 {
public:
	int play(vector <string>);
};
vector<string>v;
int f(int row, int col1, int col2)
{
    int tt = col2;
    int ans = 0;
    int i, j, k;
    if (col1 > col2) swap(col1, col2);
    for (j = col1; j <= col2; j++)
    {
        if (v[row][j] == 'x') return -INF;
        ans += v[row][j] - '0';
    }
    return ans + dp[row - 1][tt];
}
int WallGameDiv2::play(vector <string> costs) {
	int i, j, k;
	v = costs;
	m = costs.size();
	n = costs[0].size();
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) dp[i][j] = -INF;
	dp[0][0] = 0;
	for (j = 1; j < n; j++)
    {
        if (costs[0][j] == 'x') break;
        dp[0][j] = dp[0][j - 1] + costs[0][j] - '0';
    }
    for (i = 1; i < m - 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (costs[i][j] == 'x') continue;
            for (k = 0; k < n; k++)
            {
                dp[i][j] = std::max(dp[i][j], f(i, j, k));
            }
        }
    }
    int ans = 0;
    for (j = 0; j < n; j++)
    {
        if (costs[m - 1][j] == 'x') continue;
        ans = std::max(ans, dp[m - 2][j] + costs[m - 1][j] - '0');
    }
    return ans;
}



double test0() {
	string t0[] = {"042"
,"391"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	WallGameDiv2 * obj = new WallGameDiv2();
	clock_t start = clock();
	int my_answer = obj->play(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 13;
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
	string t0[] = {"0xxxx"
,"1x111"
,"1x1x1"
,"11191"
,"xxxx1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	WallGameDiv2 * obj = new WallGameDiv2();
	clock_t start = clock();
	int my_answer = obj->play(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 16;
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
	string t0[] = {"0"
,"5"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	WallGameDiv2 * obj = new WallGameDiv2();
	clock_t start = clock();
	int my_answer = obj->play(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 5;
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
	string t0[] = {"0698023477896606x2235481563x59345762591987823x663"
,"1x88x8338355814562x2096x7x68546x18x54xx1077xx5131"
,"64343565721335639575x18059738478x156x781476124780"
,"2139850139989209547489708x3466104x5x3979260330074"
,"15316x57171x182167994729710304x24339370252x2x8846"
,"459x479948xx26916349194540891252317x99x4329x34x91"
,"96x3631804253899x69460666282614302698504342364742"
,"4x41693527443x7987953128673046855x793298x8747219x"
,"7735427289436x56129435153x83x37703808694432026643"
,"340x973216747311x970578x9324423865921864682853036"
,"x1442314831447x860181542569525471281x762734425650"
,"x756258910x0529918564126476x481206117984425792x97"
,"467692076x43x91258xx3xx079x34x29xx916574022682343"
,"9307x08x451x2882604411x67995x333x045x0x5xx4644590"
,"4x9x088309856x342242x12x79x2935566358156323631235"
,"04596921625156134477422x2691011895x8564609x837773"
,"223x353086929x27222x48467846970564701987061975216"
,"x4x5887805x89746997xx1419x758406034689902x6152567"
,"20573059x699979871151x444449x5170122650576586x898"
,"683344308229681464514453186x51040742xx138x5170x93"
,"1219892x9407xx63107x24x4914598xx4x478x31485x69139"
,"856756530006196x8722179365838x9037411399x41126560"
,"73012x9290145x1764125785844477355xx827269976x4x56"
,"37x95684445661771730x80xx2x459547x780556228951360"
,"54532923632041379753304212490929413x377x204659874"
,"30801x8716360708478705081091961915925276739027360"
,"5x74x4x39091353819x10x433010250089676063173896656"
,"03x07174x648272618831383631629x020633861270224x38"
,"855475149124358107x635160129488205151x45274x18854"
,"091902044504xx868401923845074542x50x143161647934x"
,"71215871802698346x390x2570413992678429588x5866973"
,"87x4538137828472265480468315701832x24590429832627"
,"9479550007750x658x618193862x80317248236583631x846"
,"49802902x511965239855908151316389x972x253946284x6"
,"053078091010241324x8166428x1x93x83809001454563464"
,"2176345x693826342x093950x12x7290x1186505760xx978x"
,"x9244898104910492948x2500050208763770568x92514431"
,"6855xx7x145213846746325656963x0419064369747824511"
,"88x15690xxx31x20312255171137133511507008114887695"
,"x391503034x01776xx30264908792724712819642x291x750"
,"17x1921464904885298x58x58xx174x7x673958x9615x9230"
,"x9217049564455797269x484428813681307xx85205112873"
,"19360179004x70496337008802296x7758386170452xx359x"
,"5057547822326798x0x0569420173277288269x486x582463"
,"2287970x0x474635353111x85933x33443884726179587xx9"
,"0x697597684843071327073893661811597376x4767247755"
,"668920978869307x17435748153x4233659379063530x646x"
,"0019868300350499779516950730410231x9x18749463x537"
,"00508xx083203827x42144x147181308668x3192478607467"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	WallGameDiv2 * obj = new WallGameDiv2();
	clock_t start = clock();
	int my_answer = obj->play(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3512;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}



//Powered by [KawigiEdit] 2.0!

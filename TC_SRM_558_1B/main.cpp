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
#include <assert.h>

using namespace std;
const int N = 310;
const double EPS = 1e-10;
int m, n;
int redx[N], bluex[N], bluey[N];
void process(vector <string> v, int vv[], int &k)
{
    string tmp = std::accumulate(v.begin(), v.end(), string(""));
    stringstream os;
    os << tmp;
    int i = 0, val;
    while(os >> val)
    {
        vv[i] = val;
        k = ++i;
    }
}
int bi_less(double val)
{
    int left = 0, right = m, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (redx[mid] * 1.0 >= val) right = mid - 1;
        else left = mid + 1;
    }
    return right;
}
int bi_more(double val)
{
    int left = 0, right = m, mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (redx[mid] * 1.0 > val) right = mid - 1;
        else left = mid + 1;
    }
    return left;
}

void TEST()
{
    int arr[10] = {1, 3, 4, 4, 7, 8, 9, 20, 100, 101};
    m = 10;
    memcpy(redx, arr, sizeof(arr));
    assert(bi_less(3.0) == 0);
    assert(bi_less(4.0) == 1);
    assert(bi_less(1.0) == -1);
    assert(bi_less(100.0) == 7);
    assert(bi_less(101.0) == 8);
    assert(bi_less(1000.0) == 10);

    assert(bi_more(0.0) == 0);
    assert(bi_more(1.0) == 1);
    assert(bi_more(4.0) == 4);
    assert(bi_more(101.0) == 11);
}

class Ear {
public:
	long long getCount(vector <string>, vector <string>, vector <string>);
};

long long Ear::getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {
    process(redX, redx, m);
    process(blueX, bluex, n);
    process(blueY, bluey, n);
    //cout << m << "\t" << n << endl;
    std::sort(redx, redx + m);
    //if (bluey[n - 1] == 9537 && bluey[n - 2] == 9505) return 1LL * 84010934475;
    int i, j, k;
    long long ans = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = j + 1; k < n; k++)
            {
                // make sure that Ax < Px and Ax < Qx and Py > Qy
                bool flag = (redx[i] < bluex[j]) && (redx[i] < bluex[k]);
                if (!flag) continue;
                if (bluey[j] == bluey[k]) continue;
                int jj = j, kk = k;
                if (bluey[j] < bluey[k]) {swap(jj, kk);}
                if (bluey[jj] * (bluex[kk] - redx[i]) <= bluey[kk] * (bluex[jj] - redx[i])) continue;
                // get how many B( Bx > Ax and Bx < Qx)
                int id1, id2;
                //id1 = bi_more(redx[i] + 0.1);
                id1 = i + 1;
                if (id1 >= m) continue;
                id2 = bi_less(bluex[kk] - 0.1);
                int record1 = id2, record2;
                if (id2 < 0) continue;
                long long r1 = id2 - id1 + 1;
                if (r1 <= 0) continue;
                long long r2 = 0;
                int x, y;
                // Px == Qx
                if (bluex[jj] == bluex[kk])
                {
                    id1 = bi_more(bluex[jj] + 0.1);
                    if (id1 >= m) continue;
                    id1 = m - id1;
                    r2 = id1 * (id1 - 1) / 2;
                    ans += r1 * r2;
                }
                // Px > Qx
                else if (bluex[jj] > bluex[kk])
                {
                    //id1 = bi_more(bluex[kk] + 0.1);
                    if (record1 == m - 1) continue;
                    if (redx[record1 + 1] > bluex[kk] + 0.1) id1 = record1 + 1;
                    else id1 = record1 + 2;
                    if (id1 >= m) continue;
                    id2 = bi_less(bluex[jj] + 0.1);
                    if (id2 < 0) continue;
                    x = id2 - id1 + 1;
                    if (x <= 0) x = 0;

                    //id2 = bi_more(bluex[jj] + 0.1);
                    id2 += 1;
                    if (id2 >= m) y = 0;
                    else y = m - id2;
                    r2 = x * y + y * (y - 1) / 2;
                    ans += r1 * r2;
                }
                // Px < Qx
                else
                {
                    bool zheng = 0;
                    int A = bluey[kk] - bluey[jj];
                    int B = bluex[kk] - bluex[jj];
                    int C = -bluey[kk];
                    if (abs(B * C) % A == 0)
                    {
                        zheng = 1;
                    }
                    double R = 1.0 * B * C / A + bluex[kk];
                    //id1 = bi_more(bluex[kk] + 0.1);
                    if (record1 == m - 1) continue;
                    if (redx[record1 + 1] > bluex[kk] + 0.1) id1 = record1 + 1;
                    else id1 = record1 + 2;
                    if (id1 >= m) continue;
                    if (zheng) id2 = bi_less(R + 0.1);
                    else id2 = bi_less(R);
                    record2 = id2;
                    if (id2 < 0) continue;
                    x = id2 - id1 + 1;
                    if (x <= 0) x = 0;
                    //if (zheng) id1 = bi_more(R + 0.1);
                    //else id1 = bi_more(R);
                    if (id2 == m - 1) id1 = m;
                    else
                    {
                        if (zheng)
                        {
                            if (redx[id2 + 1] > R + 0.1) id1 = id2 + 1;
                            else id1 = id2 + 2;
                        }
                        else
                        {
                            if (redx[id2 + 1] > R) id1 = id2 + 1;
                            else id1 = id2 + 2;
                        }
                    }
                    if (id1 >= m) y = 0;
                    else y = m - id1;
                    r2 = x * y + y * (y - 1) / 2;
                    ans += r1 * r2;
                }
            }
        }
    }
    //TEST();
    return ans;
}
//Powered by [KawigiEdit] 2.0!


double test0() {
	string t0[] = {"1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20", " 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 3", "7 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 ", "54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70", " 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 8", "7 88 89 90 91 92 93 94 95 96 97 98 99 100 101 102 ", "103 104 105 106 107 108 109 110 111 112 113 114 11", "5 116 117 118 119 120 121 122 123 124 125 126 127 ", "128 129 130 131 132 133 134 135 136 137 138 139 14", "0 141 142 143 144 145 146 147 148 149 150 151 152 ", "153 154 155 156 157 158 159 160 161 162 163 164 16", "5 166 167 168 169 170 171 172 173 174 175 176 177 ", "178 179 180 181 182 183 184 185 186 187 188 189 19", "0 191 192 193 194 195 196 197 198 199 200 201 202 ", "203 204 205 206 207 208 209 210 211 212 213 214 21", "5 216 217 218 219 220 221 222 223 224 225 226 227 ", "228 229 230 231 232 233 234 235 236 237 238 239 24", "0 241 242 243 244 245 246 247 248 249 250 251 252 ", "253 254 255 256 257 258 259 260 261 262 263 264 26", "5 266 267 268 269 270 271 272 273 274 275 276 277 ", "278 279 280 281 282 283 284 285 286 287 288 289 29", "0 10000 9999 9998 9997 9996 9995 9994 9993 9992 99", "91"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"4900 4898 4896 4894 4892 4890 4888 4886 4884 4882 ", "4880 4878 4876 4874 4872 4870 4868 4866 4864 4862 ", "4860 4858 4856 4854 4852 4850 4848 4846 4844 4842 ", "4840 4838 4836 4834 4832 4830 4828 4826 4824 4822 ", "4820 4818 4816 4814 4812 4810 4808 4806 4804 4802 ", "4800 4798 4796 4794 4792 4790 4788 4786 4784 4782 ", "4780 4778 4776 4774 4772 4770 4768 4766 4764 4762 ", "4760 4758 4756 4754 4752 4750 4748 4746 4744 4742 ", "4740 4738 4736 4734 4732 4730 4728 4726 4724 4722 ", "4720 4718 4716 4714 4712 4710 4708 4706 4704 4702 ", "4700 4698 4696 4694 4692 4690 4688 4686 4684 4682 ", "4680 4678 4676 4674 4672 4670 4668 4666 4664 4662 ", "4660 4658 4656 4654 4652 4650 4648 4646 4644 4642 ", "4640 4638 4636 4634 4632 4630 4628 4626 4624 4622 ", "4620 4618 4616 4614 4612 4610 4608 4606 4604 4602 ", "4600 4598 4596 4594 4592 4590 4588 4586 4584 4582 ", "4580 4578 4576 4574 4572 4570 4568 4566 4564 4562 ", "4560 4558 4556 4554 4552 4550 4548 4546 4544 4542 ", "4540 4538 4536 4534 4532 4530 4528 4526 4524 4522 ", "4520 4518 4516 4514 4512 4510 4508 4506 4504 4502 ", "4500 4498 4496 4494 4492 4490 4488 4486 4484 4482 ", "4480 4478 4476 4474 4472 4470 4468 4466 4464 4462 ", "4460 4458 4456 4454 4452 4450 4448 4446 4444 4442 ", "4440 4438 4436 4434 4432 4430 4428 4426 4424 4422 ", "4420 4418 4416 4414 4412 4410 4408 4406 4404 4402 ", "4400 4398 4396 4394 4392 4390 4388 4386 4384 4382 ", "4380 4378 4376 4374 4372 4370 4368 4366 4364 4362 ", "4360 4358 4356 4354 4352 4350 4348 4346 4344 4342 ", "4340 4338 4336 4334 4332 4330 4328 4326 4324 4322 ", "4320 4318 4316 4314 4312 4310 4308 4306 4304"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"1 33 65 97 129 161 193 225 257 289 321 353 385 417", " 449 481 513 545 577 609 641 673 705 737 769 801 8", "33 865 897 929 961 993 1025 1057 1089 1121 1153 11", "85 1217 1249 1281 1313 1345 1377 1409 1441 1473 15", "05 1537 1569 1601 1633 1665 1697 1729 1761 1793 18", "25 1857 1889 1921 1953 1985 2017 2049 2081 2113 21", "45 2177 2209 2241 2273 2305 2337 2369 2401 2433 24", "65 2497 2529 2561 2593 2625 2657 2689 2721 2753 27", "85 2817 2849 2881 2913 2945 2977 3009 3041 3073 31", "05 3137 3169 3201 3233 3265 3297 3329 3361 3393 34", "25 3457 3489 3521 3553 3585 3617 3649 3681 3713 37", "45 3777 3809 3841 3873 3905 3937 3969 4001 4033 40", "65 4097 4129 4161 4193 4225 4257 4289 4321 4353 43", "85 4417 4449 4481 4513 4545 4577 4609 4641 4673 47", "05 4737 4769 4801 4833 4865 4897 4929 4961 4993 50", "25 5057 5089 5121 5153 5185 5217 5249 5281 5313 53", "45 5377 5409 5441 5473 5505 5537 5569 5601 5633 56", "65 5697 5729 5761 5793 5825 5857 5889 5921 5953 59", "85 6017 6049 6081 6113 6145 6177 6209 6241 6273 63", "05 6337 6369 6401 6433 6465 6497 6529 6561 6593 66", "25 6657 6689 6721 6753 6785 6817 6849 6881 6913 69", "45 6977 7009 7041 7073 7105 7137 7169 7201 7233 72", "65 7297 7329 7361 7393 7425 7457 7489 7521 7553 75", "85 7617 7649 7681 7713 7745 7777 7809 7841 7873 79", "05 7937 7969 8001 8033 8065 8097 8129 8161 8193 82", "25 8257 8289 8321 8353 8385 8417 8449 8481 8513 85", "45 8577 8609 8641 8673 8705 8737 8769 8801 8833 88", "65 8897 8929 8961 8993 9025 9057 9089 9121 9153 91", "85 9217 9249 9281 9313 9345 9377 9409 9441 9473 95", "05 9537"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	Ear * obj = new Ear();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 84010934475LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"3 2 8 7"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"2 8"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"3 4"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	Ear * obj = new Ear();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"1 2 6 9"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"3 6 8 5"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"1 5 4 3"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	Ear * obj = new Ear();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 4LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"10000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"10000 9999"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"10000 9999"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	Ear * obj = new Ear();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"100 2", "00", " 39", "9", " 800 900 9", "99"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"15", "0 250 ", "349"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"2 3 1"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	Ear * obj = new Ear();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 12LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"4", " ", "5", " ", "6", " 7 ", "8"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"1", " 2 ", "3 4", " 5"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	Ear * obj = new Ear();
	clock_t start = clock();
	long long my_answer = obj->getCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 204LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}


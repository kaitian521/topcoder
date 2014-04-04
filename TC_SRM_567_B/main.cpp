#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
int square[300] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144,
169, 196, 225, 256, 289, 324, 361, 400, 441, 484, 529, 576, 625, 676,
729, 784, 841, 900, 961, 1024, 1089, 1156, 1225, 1296, 1369, 1444,
1521, 1600, 1681, 1764, 1849, 1936, 2025, 2116, 2209, 2304, 2401,
2500, 2601, 2704, 2809, 2916, 3025, 3136, 3249, 3364, 3481, 3600,
3721, 3844, 3969, 4096, 4225, 4356, 4489, 4624, 4761, 4900, 5041,
5184, 5329, 5476, 5625, 5776, 5929, 6084, 6241, 6400, 6561, 6724,
6889, 7056, 7225, 7396, 7569, 7744, 7921, 8100, 8281, 8464, 8649,
8836, 9025, 9216, 9409, 9604, 9801, 10000, 10201, 10404, 10609, 10816,
11025, 11236, 11449, 11664, 11881, 12100, 12321, 12544, 12769, 12996,
13225, 13456, 13689, 13924, 14161, 14400, 14641, 14884, 15129, 15376,
15625, 15876, 16129, 16384, 16641, 16900, 17161, 17424, 17689, 17956,
18225, 18496, 18769, 19044, 19321, 19600, 19881, 20164, 20449, 20736,
21025, 21316, 21609, 21904, 22201, 22500, 22801, 23104, 23409, 23716,
24025, 24336, 24649, 24964, 25281, 25600, 25921, 26244, 26569, 26896,
27225, 27556, 27889, 28224, 28561, 28900, 29241, 29584, 29929, 30276,
30625, 30976, 31329, 31684, 32041, 32400, 32761, 33124, 33489, 33856,
34225, 34596, 34969, 35344, 35721, 36100, 36481, 36864, 37249, 37636,
38025, 38416, 38809, 39204, 39601, 40000, 40401, 40804, 41209, 41616,
42025, 42436, 42849, 43264, 43681, 44100, 44521, 44944, 45369, 45796,
46225, 46656, 47089, 47524, 47961, 48400, 48841, 49284, 49729, 50176,
50625, 51076, 51529, 51984, 52441, 52900, 53361, 53824, 54289, 54756,
55225, 55696, 56169, 56644, 57121, 57600, 58081, 58564, 59049, 59536,
60025, 60516, 61009, 61504, 62001, 62500, 63001, 63504, 64009, 64516,
65025, 65536, 66049, 66564, 67081, 67600, 68121, 68644, 69169, 69696,
70225, 70756, 71289, 71824, 72361, 72900, 73441, 73984, 74529, 75076,
75625, 76176, 76729, 77284, -1};

int prime[100] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271,
277, 281, 283, 293, -1};
using namespace std;

long long f(int x)
{
        int i, cnt;
        long long fac = 1;
        for (i = 0; prime[i] != -1 && prime[i] <= x; i++)
        {
                cnt = 0;
                if (x % prime[i] == 0)
                {
                        while (x % prime[i] == 0) {cnt ++; x /= prime[i];}
                }
                if (cnt % 2 == 1) fac *= prime[i];
        }
        return fac * x;
}
#define A TheSquareRootDilemma
#define process countPairs
class A
{
public:
        int process(int m, int n)
        {
                int sum = 0, tmp;
                int i, j;
                if (m > n) swap(m, n);
                for (i = 1; i <= n; i++)
                {
                        long long fac = (long long)1 * f(i);
                        printf("%d\t%lld\n",i, fac);
                        tmp = 0;
                        for (j = 0; (long long)square[j] * fac <= (long long)m && square[j] != -1; j++) tmp ++;
                        sum += tmp;
                }
        return sum;
        }
};
int macin()
{
        A a;
        cout <<  a.process(77777, 1) << endl;
}
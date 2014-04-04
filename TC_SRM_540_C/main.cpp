#include <iostream>
#include <stdio.h>
using namespace std;
#define N 1001000
bool boo[N + 100];
int prime[N];
void Prime()
{
    int num,k,i;
    for(i=2; i<=N; i+=2)
        boo[i] = 0;
    for(i=2; i<=1010; i++)
        for(k=i*i; k<=N; k+=i)
            boo[k] = 1;
    num = 0;
    for(i=2; i<=N; i++)
        if(boo[i] == 0)
            prime[num++] = i;
    //for (i = 0; prime[i]; i++) cout << prime[i] << endl;
}

long long gcd(long long x, long long y)
{
    if (y == 0) return x;
    if (x < y) return gcd(y, x);
    return gcd(y, x % y);
}
long long tt;
int id;
long long fac[N];
long long  f(long long x)
{
    long long sum = 1;
    for (int i = 0; i < id; i++) sum *= fac[i];
    return x / sum;
}
class FractionInDifferentBases
{
public:
    long long getNumberOfGoodBases(long long P, long long Q, long long A, long long B)
    {
        Prime();
        Q /= gcd(P, Q);
        printf ("Q = %lld\n", Q);
        if (Q == 1) return 0;
        int i = 0;
        while (prime[i] < Q && prime[i])
        {
            if (Q % prime[i] == 0)
            {
                fac[id ++] = prime[i];
                while (Q % prime[i] == 0) Q /= prime[i];
            }
            i ++;
        }
        if (Q != 1) fac[id ++] = Q;
        return B - A + 1 - f(B) + f(A - 1);
    }
};
int main()
{
    FractionInDifferentBases a;
    cout << a.getNumberOfGoodBases(99999999977, 99999999977, 2, 1000000000000000000) << endl;
    //cout << a.getNumberOfGoodBases(5, 6, 2, 10) << endl;
    return 0;
}

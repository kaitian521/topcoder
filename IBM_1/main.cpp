#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
void f(string arg)
{
    int cnt[1000];
    char ch[100]={'O', 'I','V','X','L','C','D','M'};
    int in[100]= { 0, 1,  5,  10, 50, 100,500,1000};
    int mm[225];
    memset(cnt, 0, sizeof(cnt));
    int x, i, n, j;
    string str;
    if (arg[0] >= '0' && arg[0] <= '9')
    {
        n = atoi(arg.c_str());
        for (i = 1; i <= n; i++)
        {
            x = i;
            while (x > 0)
            {
                if (x >= 1000)
                {
                    str = str + "M";
                    cnt[(int)'M'] += 1;
                    x -= 1000;
                }
                else if (x >= 900)
                {
                    str = str + "CM";
                    cnt[(int)'M'] += 1;
                    cnt[(int)'C'] += 1;
                    x -= 900;
                }
                else if (x >= 500)
                {
                    str = str + "D";
                    cnt[(int)'D'] += 1;
                    x -= 500;
                }
                else if (x >= 400)
                {
                    str = str + "CD";
                    cnt[(int)'C'] += 1;
                    cnt[(int)'D'] += 1;
                    x -= 400;
                }
                else if (x >= 100)
                {
                    str = str + "C";
                    cnt[(int)'C'] += 1;
                    x -= 100;
                }
                else if (x >= 90)
                {
                    str = str + "XC";
                    cnt[(int)'C'] += 1;
                    cnt[(int)'X'] += 1;
                    x -= 90;
                }
                else if (x >= 50)
                {
                    str = str + "L";
                    cnt[(int)'L'] += 1;
                    x -= 50;
                }
                else if (x >= 40)
                {
                    str = str + "XL";
                    cnt[(int)'X'] += 1;
                    cnt[(int)'L'] += 1;
                    x -= 40;
                }
                else if (x >= 10)
                {
                    str = str + "X";
                    cnt[(int)'X'] += 1;
                    x -= 10;
                }
                else if (x == 9)
                {
                    str = str + "IX";
                    cnt[(int)'X'] += 1;
                    cnt[(int)'I'] += 1;
                    x -= 9;
                }
                else if (x >= 5)
                {
                    str = str + "V";
                    cnt[(int)'V'] += 1;
                    x -= 5;
                }
                else if (x == 4)
                {
                    str = str + "IV";
                    cnt[(int)'I'] += 1;
                    cnt[(int)'V'] += 1;
                    x -= 4;
                }
                else
                {
                    str = str + "I";
                    cnt[(int)'I'] += 1;
                    x -= 1;
                }
            }
            if (i % 100 != 0) continue;
            cout << "{";
            for (j = 1; j <= 7; j++)
            {
                cout << cnt[ch[j]] << ",";
            }
            cout << "}," << endl;
        }
    }
}

int main()
{
    freopen("1.txt", "w", stdout);
    char s[10];
    sprintf(s, "%d", 3500);
    f(s);
    return 0;
}

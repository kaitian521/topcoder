#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#define abs (int)fabs
using namespace std;
int n;
string str[2] = {"CAN", "CANNOT"};
class EvenRoute
{
public:
    string isItPossible(vector<int>x, vector<int>y, int wantedParity)
    {
        int i, flag, j, k;
        int tt;
        n = x.size();
        bool ans = 0;
        if (wantedParity == 0)
        {
            for (i = 0; i < n; i++)
            {
                flag = (abs(x[i]) + abs(y[i])) % 2;
                if (flag == 0) return str[0];
                flag = 0;
                for (j = 0; j < n; j++)
                {
                    for (k = 0; k < n; k++)
                    {
                        if (j == k) continue;
                        if ( (abs(x[j] - x[k]) + abs(y[j] - y[k])) % 2 == 1)
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    ans = 1;
                    break;
                }
            }
        }
        else
        {
            for (i = 0; i < n; i++)
            {
                flag = (abs(x[i]) + abs(y[i])) % 2;
                if (flag == 1) return str[0];
                flag = 0;
                for (j = 0; j < n; j++)
                {
                    for (k = 0; k < n; k++)
                    {
                        if (j == k) continue;
                        if ( (abs(x[j] - x[k]) + abs(y[j] - y[k])) % 2 == 1)
                        {
                            flag = 1;
                            break;
                        }
                    }
                }
                if (flag)
                {
                    ans = 1;
                    break;
                }
            }
        }
        return str[1 - ans];
    }

};
int macin()
{
    cout << "Hello world!" << endl;
    return 0;
}

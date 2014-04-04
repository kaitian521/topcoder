#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <string.h>
#include <stdio.h>
using namespace std;
#define N 60
map<string, vector<string> > mm;
map<string, vector<string> >::iterator it;
string next(string tt)
{
    int len = tt.length(), i = 0;
    while (i < len && tt[i] == '9') {tt[i] = '0'; i ++;}
    if (i == len) return "";
    tt[i] ++;
    return tt;
}
char s[N];
string res;
class EllysBulls
{
public:
    string getNumber(vector <string> guesses, vector <int> bulls)
    {
        int i, j, k, n = guesses[0].size();
        int mask;
        for (string tt(n / 2, '0'); tt != ""; tt = next(tt))
        {
            //cout << tt << endl;
            for (i = 0; i < guesses.size(); i++)s[i] = '0';
            mask = 1;
            for (j = 0; j < guesses.size(); j++)
            {
                for (k = 0; k < n / 2; k++)
                {
                    if (guesses[j][k] == tt[k])
                    {
                        s[j] ++;
                    }
                }
                mask &= (s[j] - '0' <= bulls[j]);
            }
            if (mask)
            {
                //cout << s << endl;
                string ss = s;
                it = mm.find(ss);
                if (it == mm.end())
                {
                    vector<string>vvv;
                    vvv.push_back(tt);
                    mm[ss] = vvv;
                }
                else
                {
                    mm[ss].push_back(tt);
                }
                //cout << ss << "\t" << tt << endl;
            }
        }
        int ans = -1;
        for (string tx(n - n / 2, '0'); tx != ""; tx = next(tx))
        {
            memset(s, 0, sizeof(s));
            for (i = 0; i < guesses.size(); i++)s[i] = '0';
            mask = 1;
            for (j = 0; j < guesses.size(); j++)
            {
                for (k = n / 2; k < n; k++)
                {
                    if (guesses[j][k] == tx[k - n / 2])
                    {
                        s[j] ++;
                    }
                }
                mask &= (s[j] - '0' <= bulls[j]);
            }
            if (mask)
            {
                string ttttt;
                for (k = 0; k < guesses.size(); k++)
                {
                    ttttt += (char)(bulls[k] - s[k] + '0' + '0');
                }
                it = mm.find(ttttt);
                if (it == mm.end()) continue;
                if (it->second.size() > 1) return "Ambiguity";
                else
                {
                    if (ans == 0) return "Ambiguity";
                    res = it->second[0] + tx;
                    ans = 0;
                }
            }
        }
        if (ans == -1) return "Liar";
        return res;
    }
};
int main()
{
    //freopen("1.txt", "w", stdout);
    EllysBulls E;
    string str[100] = {"1234", "4321", "1111", "2222", "3333", "4444", "5555", "6666", "7777", "8888", "9999"};
    int b[100] = {2, 1, 1, 0, 2, 0, 0, 0, 1, 0, 0};
    vector<string>vv(str, str + 11);
    vector<int>vvv(b, b + 11);
    cout << E.getNumber(vv, vvv) << endl;
    return 0;
}

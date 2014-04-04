#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <set>
using namespace std;
#define N 100
int ans = 0;
map<int, int >s;
set<int>ss;
class NewArenaPassword
{
public:
    int minChange(string oldPassword, int K)
    {
        string old = oldPassword;
        int i, j, k;
        int len = strlen(oldPassword.c_str());
        int a[100], b[100], hash[100];
        if (len == K) return 0;
        bool visit[100];
        memset (hash, -1, sizeof(hash));
        memset (visit, 0, sizeof(visit));
        for (i = 0; i < K; i ++)
        {
            a[i] = i;
            b[i] = len + i - K;
            hash[i] = b[i];
        }
        for (i = 0; i < K; i++)
        {
            int j = i;
            s.clear();
            ss.clear();
            if (visit[j]) continue;
            char ch = oldPassword[a[j]];
            while (hash[j] != -1)
            {
                visit[j] = 1;
                ss.insert(j);
                visit[b[j]] = 1;
                ss.insert(b[j]);
                j = b[j];
            }
            map<int, int >::iterator it;
            set<int>::iterator its;
            for (its = ss.begin(); its != ss.end(); its++)
            {
                cout << *its << endl;
                if(s.find(old[*its]) == s.end()) s[old[*its]] = 1;
                else s[old[*its]] += 1;
            }
            int tt = 0;
            for (it = s.begin(); it != s.end(); it++)
            {
                if (tt < it->second) tt = it->second;
            }
            bool flag = 1;
            for (it = s.begin(); it != s.end(); it++)
            {
                if (flag && it->second == tt) {flag = 0;continue;}
                ans += it->second;
            }
        }
        return ans;
    }
};

int main()
{
    NewArenaPassword A;
    cout << A.minChange("loool", 3) << endl;
    return 0;
}

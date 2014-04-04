#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<string>words;
int m, n;
bool canequal(string str1, string str2)
{
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}
#define N 60
bool visit[N];

bool dfs(string str1, string str2, int len)
{
    if (len == 0) return 1;
    if (len & 1)
    {
        if (str1[len - 1] != str2[len - 1]) return 0;
        return dfs(str1, str2, len - 1);
    }
    char ch1 = str2[len - 1], ch2 = str2[len - 2];
    char ch3, ch4;
    int i, j, k;
    for (i = 0; i < len - 1; i += 2)
    {
        ch3 = str1[i], ch4 = str1[i + 1];
        if ( (ch1 == ch3 && ch2 == ch4) || (ch1 == ch4 && ch2 == ch3) )
        {
            string str1_c = str1;
            reverse(str1_c.begin(), str1_c.begin() + i + 2);
            //cout << str1 << "\t" << str1_c << "\t";
            char s[50] = "";
            k = 0;
            for (j = i + 1; j >= 2; j--)
            {
                s[k++] = str1_c[j];
            }
            for (j = i + 2; j < len; j++)
            {
                s[k++] = str1_c[j];
            }
            //cout << s << endl;
            if (dfs(s, str2.substr(0, len - 2), len - 2)) return 1;
            else return 0;
        }

    }
    return 0;
}

bool dfs2(string str1, string str2, int len)
{
    if (len == 0) return 1;
    if (len & 1)
    {
        if (str1[len - 1] != str2[len - 1]) return 0;
        return dfs2(str1, str2, len - 1);
    }
    int i;
    vector<string>v1, v2;
    for (i = 0; i < len - 1; i += 2)
    {
        string str1_c;
        str1_c += str1[i];
        str1_c += str1[i + 1];
        if (str1_c[0] > str1_c[1])swap(str1_c[0], str1_c[1]);
        v1.push_back(str1_c);

        string str2_c;
        str2_c += str2[i];
        str2_c += str2[i + 1];
        if (str2_c[0] > str2_c[1])swap(str2_c[0], str2_c[1]);
        v2.push_back(str2_c);
        //cout << str1_c << "\t" << str2_c << endl;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    return v1 == v2;
}
bool judge(string str1, string str2)
{
    if (!canequal(str1, str2)) return 0;
    if (str1.length() == 1) return 0;
    return dfs(str1, str2, str1.length());
}

class EllysReversals
{
public:
    int getMin(vector <string> _words)
    {
        m = _words.size();
        words = _words;
        int i, j;
        for (i = 0; i < m; i++)
        {
            if (visit[i]) continue;
            for (j = i + 1; j < m; j++)
            {
                if (visit[j]) continue;
                if (judge(words[i], words[j]))
                {
                    visit[i] = visit[j] = 1;
                    break;
                }
            }
        }
        int ans = 0;
        for (i = 0; i < m; i++)
        {
            ans += 1 - visit[i];
        }
        return ans;
    }
};

int main()
{
    string sss[] = {"ababababababababababababababababababababababababab", "abababababababaaababbaabababababababababababababab", "ababababababababababababababaabaababababababababab", "abababababaaabaaababababababababaabbababababababab", "ababababababababababababaabaaabaaabababababababab", "abababababababaaabababababababababaabbabababababab", "ababaaabababababababababababaaabababababababaaabab", "baaabbabababababababaaabababababababababababababab", "ababaabbabababaaaaabababbabababababababababababab", "ababababababababababababababaaababababababababaaab", "abababababbaabaaabaaababababababababababababababab", "abaaababababaabbababababababaaabaabababababababab", "ababaaababababaaaabbabababababababababababakababab", "ababaaababababababaabbabababaaabaaababababkbaaabab", "abababababaaabaaabaaaabbababababababababakabababab", "abaaababababababababababaabbaaabaaabababkbabababab", "ababaaababababaaabababababababababababakababababab", "ababaaabababababababababababaaabaabbabkbababaaabab", "ababaaababababaaababababababababababakabababababab", "ababaaabababababababababababaaabaaabkbabababaaabab", "abababababababababababababababababbaababababababab", "abababababababaaababababababababababaabbababababab", "ababababababababababababababaaababababaabbabababab", "abababababaaabaaababababababababababababaabbababab", "abababababababaebababababababaaabaaabababababababa", "abababababababacaabababababababababababababababbaa", "ababaaababababadbababababababaaabababababababaaaba", "baababababababaabababaaabababababababababababbaaba", "abababababababataaaababababababababababababababbba", "abababababababaybababababababaaababababababababbbb", "abababababaaabauaabaaababababababababababababbbaba", "abaaabababababaibababababababaaabaaabababaaaaababa", "ababaaababababakabbbbabababababababababababakababa", "ababaaabababababababaaaaabablaaabaaababababkbaaaba", "abababababaaabaaabaaababaaaalababababababakabababa", "abaaababababababababababababaaabaalabababkbabababa", "ababaaababababaaabababababababaaaaaababakababababa", "ababaaabababababababababababaaabaalaaaakbababaaaba", "ababaaababababaaabababababababababalbakaaaaabababa", "ababaaabababababababababababaaabaaalbkbababaaaaaba", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaababaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "aaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaa", "fuck"};
    int ll = 0;
    while (sss[ll] != "fuck") ll++;
    vector<string>v(sss, sss + ll);
    EllysReversals x;
    cout << x.getMin(v) << endl;
    return 0;
}

#include <iostream>
#include <assert.h>
#include <sstream>
#include <string>
#include <string.h>
#include <map>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;

#define N 1010
#define MOD 2017
int match[30];
bool be_matched[30];
vector<int> v[16][MOD];
set<string>ss;
string dict[N];
string origin[100];
int len[100];
int hash_t[100];

struct node
{
    int id;
    int cnt;
    node(){}
    node(int _id, int _cnt)
    {
        id = _id; cnt = _cnt;
    }
};
bool cmp(node t1, node t2)
{
    return t1.cnt < t2.cnt;
}
vector<node>pp;

int n;

int magic[] = {2, 3, 5, 7, 11, 13 ,17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};
int hash(string s)
{
    bool visit[20];
    memset(visit, 0, sizeof(visit));
    int lenn = s.length();
    if (lenn == 1) return 0;
    int i, j, k;
    long long val = 0;
    k = 0;
    for (i = 0; i < lenn; i++)
    {
        if (visit[i]) continue;
        long long tmp = i + 1;
        for (j = i + 1; j < lenn; j++)
        {
            if (s[i] == s[j])
            {
                tmp = tmp * 10 + j + 1;
                tmp %= MOD;
                visit[j] = 1;
            }
        }
        if (tmp != i + 1)
        {
            val += tmp * magic[k++];
            val %= MOD;
        }
    }
    return val % MOD;
}

void init()
{
    ss.clear();
    pp.clear();
    memset(be_matched, 0, sizeof(be_matched));
    memset(match, -1, sizeof(match));
}

int match_cache[30];
bool be_matched_cache[30];
struct mypair
{
    int first, second;
    mypair(){first = 0; second = 0;}
    mypair(int _first, int _second)
    {
        first = _first; second = _second;
    }
};

mypair ppair[26];
int pair_num;
bool check(string s, string t)
{
    pair_num = 0;
    memcpy(match_cache, match, sizeof(match));
    memcpy(be_matched_cache, be_matched, sizeof(be_matched));
    //cout << s << "    " << t << endl;
    int i, j, k;
    for (i = 0; i < s.length(); i++)
    {
        if (match_cache[ t[i] -'a' ] != -1)
        {
            if (match_cache[ t[i] - 'a' ] != s[i] - 'a') return false;
        }
        else
        {
            if (be_matched_cache[ s[i] - 'a' ] ) return false;
            ppair[pair_num].first = t[i] - 'a';
            ppair[pair_num++].second = s[i] - 'a';
            be_matched_cache[ s[i] - 'a' ] = 1;
            match_cache[t[i] - 'a'] = s[i] - 'a';
        }
    }
    return true;
}

bool dfs(int step)
{
    if (step == pp.size()) return true;
    int i, j, k;
    int id = pp[step].id;

    mypair pairr[26];
    int ppair_num;
    for (i = 0; i < pp[step].cnt; i++)
    {
        string s = dict[ v[len[id]][hash_t[id]][i] ];
        if (check(s, origin[id]))
        {
            memcpy(match, match_cache, sizeof(match));
            memcpy(be_matched, be_matched_cache, sizeof(be_matched));
            for(j = 0; j < pair_num; j++)
            {
                pairr[j].first = ppair[j].first;
                pairr[j].second = ppair[j].second;
            }
            ppair_num = pair_num;
            if (dfs(step + 1)) return true;
            for (j = 0; j < ppair_num; j++)
            {
                match[ pairr[j].first ] = -1;
                be_matched[ pairr[j].second ] = 0;
            }
        }
    }
    return false;
}


int main()
{
    string tt;
    char * buffer = new char[10000];
    while(1)
    {
        char *ppp = gets(buffer);
        if (strlen(ppp) == 1 && buffer[0] == '0') break;
        std::istringstream iss(buffer);
        while(iss >> tt)
        {
            cout << tt << " ";
        }
        cout << endl;
    }
    return 0;
}

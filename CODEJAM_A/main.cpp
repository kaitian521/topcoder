#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;
char v[4][5];
#define BSZIE 10
int b[BSZIE][4] = {
    {0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}, {12, 13, 14, 15},
    {0, 4, 8, 12}, {1, 5, 9, 13}, {2, 6, 10, 14}, {3, 7, 11, 15},
    {0, 5, 10, 15},{3, 6, 9, 12},
};

void f(int id)
{
    bool OO = false, XX = false;
    bool canOO= false, canXX = false;
    int i, j, k = 0;
    int cnt[4];
    int hash[1000];
    memset(hash, -1, sizeof(hash));
    hash['O'] = 0;
    hash['X'] = 1;
    hash['T'] = 2;
    hash['.'] = 3;

    for (k = 0; k < BSZIE; k++)
    {
        memset(cnt, 0, sizeof(cnt));
        for (i = 0; i < 4; i++)
        {
            int tt = b[k][i];
            int x = tt / 4, y = tt % 4;
            cnt[ hash[v[x][y] ] ]++;
        }
        if (cnt[0] && cnt[1]) continue;
        if (!cnt[0] && !cnt[1]) {canOO = true; canXX = true;}
        else if (cnt[0])
        {
               if (cnt[0] + cnt[2] == 4) {OO = true; break;}
               else if (cnt[1] == 0){canOO = 1;}

        }
        else
        {
            if (cnt[1] + cnt[2] == 4) {XX = true; break;}
            else if(cnt[0] == 0) {canXX = 1;}
        }
    }
    printf("Case #%d: ", id);
    if (OO) printf("O won");
    else if (XX) printf("X won");
    else if (canOO || canXX) printf("Game has not completed");
    else printf("Draw");
    printf("\n");
}

int main()
{
    //freopen("1.txt", "r", stdin);
    //freopen("2.txt", "w", stdout);
    int T, id = 1, i;
    cin>>T;
    while(T--)
    {
        for (i = 0; i < 4; i++)
        {
            cin >> v[i];
        }
        f(id++);
    }
    return 0;
}

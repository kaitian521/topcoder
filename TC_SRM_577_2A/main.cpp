#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <stdio.h>
using namespace std;
bool hash[400];
class EllysNewNickname
{
public:
    int getLength(string nickname)
    {
        hash['a'] = hash['e'] = hash['i'] = 1;
        hash['o'] = hash['u'] = hash['y'] = 1;

        string str = nickname + 'z';
        int i = 0, j, len = nickname.length();
        while (i < str.length())
        {
            if (hash[str[i]])
            {
                j = i + 1;
                while(hash[str[j]]) j ++;
                len -= (j - i - 1);
                i = j;
            }
            else
            {
                i ++;
            }
        }
        return len;
    }
};
int main()
{
    int T;
    EllysNewNickname x;
    cout << x.getLength("tourist") << endl;

	return 0;
}

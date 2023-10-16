



#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
 
bool isNum(char c)
{
    return c >= '0' && c <= '9';
}
int main()
{
    string str;
    cin >> str;
    if (str.size() == 0)
    {
        return 0;
    }
    int maxlen = -1;
    for (int i = 0; i < str.length(); i++)
    {
        if (isNum(str[i]))
        {
            maxlen = max(maxlen,1);
            int tmplen = 1;
            for (int j = i+1; j < str.length(); j++)
            {
                if (isNum(str[j]) && str[j] >= str[j-1])
                {
                    tmplen++;
                }
                else
                {
                    break;
                }
            }
            maxlen = max(maxlen, tmplen);
        }
    }
    if (maxlen == -1)
    {
        maxlen = 0;
    }
    cout << maxlen << endl;
    return 0;
 
}
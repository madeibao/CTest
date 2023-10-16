


#include <string>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <utility>
using namespace std;
int main()
{
    map<int,int> colects;
    int n = 0;
    int maxNum = 0;
    while (cin>>n)
    {
        auto it = colects.find(n);
        if (it != colects.end())
        {
            it->second++;
            maxNum = max(maxNum, it->second);
        }
        else
        {
            colects.insert(std::make_pair(n, 1));
            maxNum = max(maxNum, 1);
        }
    }
 
    vector<int> middles;
    for (auto it = colects.begin(); it != colects.end(); it++)
    {
        if (it->second == maxNum)
        {
            middles.push_back(it->first);
        }
    }
 
    if (middles.size()%2)
    {
        cout << middles[middles.size() / 2] << endl;
    }
    else
    {
        cout << (middles[middles.size() / 2 - 1] + middles[middles.size() / 2]) / 2 << endl;
    }
 
    return 0;
}
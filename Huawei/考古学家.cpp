


#include <string>
#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
 
bool checkAnyNoVisited(vector<int> &visited)
{
    bool n = true;
    for_each(visited.begin(), visited.end(), [&](int x) { n &= x;});
    return n;
}
void function(vector<string> &colects, map<string, bool> &result, string & str, vector<int> &visited)
{
    //如果尚有未访问的，则继续，否则push到map里
    if (!checkAnyNoVisited(visited))
    {
        for (int i = 0; i < colects.size(); i++)
        {
            if (visited[i] == 0)
            {
                visited[i] = 1;
                string tempstr = str + colects[i];
                function(colects, result, tempstr, visited);
                visited[i] = 0;
            }
        }
    }
    else
    {
        result.insert(std::make_pair(str, true));
    }
 
    return;
};
 
int main()
{
    int n;
    vector<string> colects;
    cin >> n;
    while (n)
    {
        n--;
        string s;
        cin >> s;
        colects.push_back(s);
    }
 
    map<string, bool> result;
     
    for (int i = 0; i < colects.size(); i++)
    {
        vector<int> visited(colects.size(), 0);
        visited[i] = 1;
        string str = colects[i];
        function(colects, result, str, visited);
        visited[i] = 0;
    }
 
    for (auto it = result.begin(); it != result.end(); it++)
    {
        cout << it->first << endl;
    }
 
    return 0;
}

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    deque< pair<int,int> > rVec;//pair: 优先级,序号
    int priority, index = 0;
    while (cin>> priority)
    {
        rVec.push_back(std::pair<int, int>(priority, index++));
        if (cin.get() == '\n')
        {
            break;
        }
    }

    vector< int> result(rVec.size(),0);
    index = 0;
    while (!rVec.empty()) 
    {
        //将front 弄成优先级最高的那个，只要front这个不是，就弄到最低下去
        bool isFrontTheMostPriority = true;
        std::pair<int, int> top = rVec.front();
        for (int i = 1; i < rVec.size(); i++) 
        {
            if (rVec[i].first > top.first)
            {
                rVec.push_back(top);
                rVec.pop_front();
                isFrontTheMostPriority = false;
                break;
            }
        }

        if (isFrontTheMostPriority)
        {
            result[top.second] = index;
            rVec.pop_front();
            index++;
        }
    }

    while (!result.empty()) 
    {
        char opr = ',';
        if (result.size() == 1)
        {
            opr = '\n';
        }
        cout << result.front() << opr;
        result.erase(result.begin());
    }

    return 0;

}
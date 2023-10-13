
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    vector vec;
    string tmp;
    while (getline(ss, tmp, ','))
    {
        vec.push_back(atoi(tmp.c_str()));
    }
    
    int ret = -1;
    for (int i = 0; i < vec.size(); i++)
    {
        if (i == 0)
        {
            // 第0个左边是0，判断右边所有元素加起来是否为0
            int right = 0;
            for (int j = 1; j < vec.size(); j++)
            {
                right += vec[j];
            }
            if (right == 0)
            {
                ret = 0;
                break;
            }
        }
        else if (i == vec.size() - 1)
        {
            // 最后一个右边是0，判断左边所有元素加起来是否为0
            int left = 0;
            for (int j = 0; j < vec.size() - 1; j++)
            {
                left += vec[j];
            }
            if (left == 0)
            {
                ret = vec.size() - 1;
                break;
            }
        }
        else
        {
            int left = 0;
            for (int m = 0; m < i; m++)
            {
                left += vec[m];
            }
            int right = 0;
            for (int n = i + 1; n < vec.size(); n++)
            {
                right += vec[n];
            }
            if (left == right)
            {
                ret = i;
                break;
            }
        }
    }
    cout << ret << endl;
    return 0;
}
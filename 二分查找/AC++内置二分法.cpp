
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

// 1 lower_bound(起始位置first,结束位置last,目标元素val);
// 2 upper_bound(起始位置first,结束位置last,目标元素val);
// 3  //lower_bound/upperbound的返回值是一个地址值，若要得到目标元素的下标，直接减去数组首地址的值即可


// 最近在工作中遇到了std::map中的lower_bound与upper_bound，再次记录下其功能和使用方式。
// std::map<char, int> mp;

// mp.lower_bound<key> ： 返回的是第一个大于、等于key的iterator，如果没有则返回空。
// mp.upper_bound<key> ：返回的是第一个大于key的iterator，如果没有，则返回空

// lower_bound(ForwardIter first,ForwardIter last, const_Tp& val) 算法返回一个非递减序列[first,last) 中第一个大于等于值val的位置。

//  upper_bound(ForwardIter first,ForwardIter last, const_Tp& val) 算法返回一个非递减序列[first,last) 中第一个大于值val的位置。

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    vector<int> t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(3);
    t.push_back(4);
    t.push_back(5);
    t.push_back(6);
    t.push_back(7);
    t.push_back(8);


    int low=lower_bound(t.begin(),t.end(),5)-t.begin();
    int upp=upper_bound(t.begin(),t.end(),4)-t.begin();
    cout<<low<<endl;
    cout<<upp<<endl;


    return 0;
    system("pause");
}






#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
//降序函数

bool cmpa(int a, int b)
{
    return a>b;//升序则为a<b
}
//改成相应的参数

bool cmp2(PII a,PII b)
{
    return a.first<b.first;//根据fisrt的值升序排序
    //return a.second<b.second;//根据second的值升序排序
}

int main()
{

    vector<int> nums;

    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(10);

    sort(nums.begin(),nums.end(),cmpa);

    for(auto i:nums) {
        cout<<i<<" ";
    }

    cout<<endl<<"------------------------"<<endl;
    vector<pair<int,int>> vec;
    vec.push_back(make_pair(3,2));
    vec.push_back(make_pair(3,5));
    vec.push_back(make_pair(6,7));
    vec.push_back(make_pair(9,3));
    vec.push_back(make_pair(10,1));

    //如何调用
    sort(vec.begin(),vec.end(),cmp2);//降序排列

    for(auto i:vec) {
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}

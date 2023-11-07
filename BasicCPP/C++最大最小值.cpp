
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n[]={1,4,22,3,8,5};
    int len=sizeof(n)/sizeof(int);
    cout<<*max_element(n,n+len)<<endl;
    cout<<*min_element(n,n+len)<<endl;
    return 0;
}


//---------------------------------------------------------------------------------

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n[]={1,4,2,3,5,0};
    vector<int>   v(n,n+sizeof(n)/sizeof(int));//sizeof(n)/sizeof(int)是求数组n的长度
    cout<<*min_element(v.begin(),v.end())<<endl;//最小元素
    cout<<*max_element(v.begin(),v.end())<<endl;//最大元素
    return 0;
}
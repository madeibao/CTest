
#include<bits/stdc++.h>
using namespace std;
const int n=5;
int arr[n]={1,3,7,5,2};
int sum[n];

void get_sum()  //前缀和
{
    sum[0]=arr[0];
    for(int i=1;i<n;i++)
    sum[i]=sum[i-1]+arr[i];
}

int add(int l,int r) //对区间（l,r）求和
{
    if(l==0) {
        return  sum[r];  //如果l=0，说明此时只需要求(0,r)之间的数字和，也就是此时的sum[r
    }
    return sum[r]-sum[l-1]; //如果l>0，说明求的是(l,r)之间的和，也就是需要将sum[r]减去sum[l-1]
    //因为sum[r]存储的是0~r之间的数字和,sum[l]存储的是0~l之间的数字和；
}

int main(int argc, char** argv) {   //没有一点技术含量的主函数
    get_sum();
    cout<<add(2,4)<<endl;
    cout<<add(0,3)<<endl;
    cout<<add(3,4)<<endl;
    return 0;
}

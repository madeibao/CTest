

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
 
int main()
{
    double a[4];
    int ca=0,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&a[0],&a[1],&a[2],&a[3]);
        printf("Case %d: ",++ca);
        sort(a,a+4);
        double p=(a[0]+a[1]+a[3]+a[2])/2.0;
        if(a[0]+a[1]+a[2]<=a[3])
            puts("-1");
        else
            printf("%.6f\n",sqrt((p-a[0])*(p-a[1])*(p-a[2])*(p-a[3])));
    }
    return 0;
}
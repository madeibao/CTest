/*#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#include<map>

*/


#include<bits/stdc++.h>
#include<iostream>

using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=1000+10;
int f[N],n,m;


struct Edge
{
    int u,v,c;
    bool operator<(const Edge& b)
    {
        return c<b.c;
    }
} e[3000+300];

int Find(int x)
{
    return f[x]==x?x:f[x]=Find(f[x]);
}

int Kruscal()
{
    int mini=INF;
    for(int k=0; k<m; ++k)
    {
        int cnt=0,lowb=INF,upb=~INF;
        for(int i=1; i<=n; ++i)
            f[i]=i;
        for(int i=k; i<m; ++i)
        {
            int u=e[i].u,v=e[i].v,c=e[i].c;
            if(Find(u)!=Find(v))
            {
                f[Find(u)]=Find(v);
                cnt++;
                lowb=min(lowb,c);
                upb=max(upb,c);
                if(cnt==n-1)
                {
                    mini=min(mini,upb-lowb);
                    break;
                }
            }
        }
    }
    return mini==INF?-1:mini;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<m; ++i)
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
    sort(e,e+m);
    printf("%d\n",Kruscal());
    return 0;
}
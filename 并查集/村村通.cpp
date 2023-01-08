

#include <bits/stdc++.h>
#define MAXN 10000

int fat[MAXN], siz[MAXN];

void INIT(int n)
{
    for(int i=1;i<=n;++i)
    {
        fat[i] = i;
        siz[i] = 1;
    }
}

int find(int x) {
	return x==fat[x]?x:fat[x] = find(fat[x]);
}

void UNION(int u, int v)
{
    u = FIND(u); v = FIND(v);
    if(siz[u] > siz[v])
        std::swap(u,v);
    fat[u] = v; siz[v] += siz[u];
    return ;
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF && n!=0)
    {
        int m;scanf("%d",&m);
        INIT(n);
        for(int i=1;i<=m;++i)
        {
            int x,y;scanf("%d%d",&x,&y);
            UNION(x,y);
        }
        int nul = 0;
        for(int i=1;i<=n;++i)
        {
            if(fat[i] == i)
            {
                ++nul;
            }
        }
        printf("%d\n",nul - 1);
    }
    return 0;
}
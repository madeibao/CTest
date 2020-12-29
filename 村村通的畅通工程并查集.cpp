


#include<bits/stdc++.h>
#include<iostream>

using namespace std;


// 最大的节点的值。

const int maxn=1001;
int parent[maxn]={0};

int findRoot(int x) {
   if(x==parent[x]) {
   	return x;
   }
   else
   {
       int root=findRoot(parent[x]);
       parent[x]=root;
       return root;
   }
}

void unionSet(int a,int b)
{
    //合并a，b元素
    int fa=findRoot(a);
    int fb=findRoot(b);
    if(fa!=fb)
    {
        parent[fa]=fb;
    }
}

int main()
{
    int n,m;
    while(cin>>n>>m&&n!=0)
    {
        int u,v;
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<m;i++)
        {
            cin>>u>>v;
            unionSet(u,v);
        }
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(parent[i]==i)
            {
                count++;
            }
        }
        cout<<count-1<<endl;
    }
    return 0;
}

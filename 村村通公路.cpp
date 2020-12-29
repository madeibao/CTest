

/*

5 2
1 2
3 5
*/

#include<iostream>
using namespace std;

// 定义节点的存储数组。
int parent[10];
int n,m,x,y,ans=0;

int find(int x)
{
	int r;
	if(parent[x]==x) {
		r=x;
	}
	else{
		r=find(parent[x]);
	}
	return r;	
}

void unite(int a,int b) {
	parent[find(a)]=find(b);
}

int main() {
	while(cin>>n>>m) {
		ans=0;
		if(n==0)return 0;

		// 节点从0或者是从1开始都可以的。
		for(int i=1;i<=n;i++) {
			parent[i]=i;
		}

		for(int j=1;j<=m;j++)
		{
			cin>>x>>y;
			unite(x,y);
		}


		for(int k=1;k<=n;k++)
		{
			if(parent[k]==k)ans++;
		}
		cout<<ans-1<<endl;
	}
	
}





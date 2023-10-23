


#include<bits/stdc++.h>
using namespace std;
string str,res;
int vis[10];
void DFS(int now){
	if(now == str.size()){
		cout<<res<<endl;
		return;
	}
	for(int i=0; i<str.size(); i++){
		if(vis[i]) continue;
		vis[i] = 1;
		res[now] = str[i];
		DFS(now+1);
		vis[i] = 0; //回溯 
	}
}
int main(){
	while(cin>>str){
		memset(vis, 0, sizeof(vis));
		sort(str.begin(),str.end());
		res = str;
		DFS(0);
		cout<<endl;			
	}
	return 0;
} 


//----------------------------------------------------------------
// 输入abc 


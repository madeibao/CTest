


// 输入结果值
mayuan 4

// 输出结果值。
ayu

// ----------------------------------------------------------------------------------------

#include<iostream>
#include<bits/stdc++.h>

using namespace std;
string s;
int k;
int n;
void solve() {
    cin>>s>>k;
    set<string> ss;
    n = s.size();
    for(int i=0;i<n;i++){
        for(int j=1;j<=k&&i+j<=n;j++){
            ss.insert(s.substr(i,j));
        }
    }


    for(int i=1;i<k;i++){
        ss.erase(ss.begin());
    }
    cout<<*ss.begin()<<endl;
}

int main() {
    solve();
    return 0;
}




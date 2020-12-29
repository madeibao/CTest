


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> dfs(int n) {

    vector<vector<int>> res = {n, vector<int>(n)};
        int count = 1;
        for(int i=0;i<=n/2;i++) {
            for(int j=i;j<=n-i-1;j++) {
                res[i][j] = count++;
            }
            for(int j=i+1;j<=n-i-1;j++) {
                res[j][n-i-1] = count++;
            }

            for(int j=n-i-2;j>=i;j--) {
                res[n-i-1][j] = count++;
            }

            for(int j=n-i-2;j>=i+1;j--) {
                res[j][i] = count++;
            }
        }
        return res;
}

int main() {
    int T;
    unsigned int N,M;
    cin>>T;
    int x,y;
    while(T-->0) {
        cin>>N>>M;
        for(int i=0;i<M;i++) {
            cin>>x>>y;
            vector<vector<int>> temp = dfs(N);
            cout<<temp[x][y]<<endl;
        }
    }
    return 0;
}





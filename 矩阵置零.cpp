
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<bool>pox(m),poy(n);
        for(int i=0;i<m;i++) {
            pox[i]=false;
        }
        for(int i=0;i<n;i++) {
            poy[i]=false;
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(matrix[i][j]==0) {
                    pox[i]=true;
                    poy[j]=true;
                }
            }
        }
        for(int i=0;i<m;i++) {
            if(pox[i]){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(poy[j]){
                for(int i=0;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

int main(){
	vector<vector<int> > res  = {{1,1,1},{1,0,1},{1,1,1}};
	Solution s;
	s.setZeroes(res);
	for(auto i:res) {
		for(auto j: i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}


	return 0;
}

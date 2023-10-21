

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1=s1.size();
        int len2=s2.size();
        int len3=s3.size();
        if(len1+len2!=len3){
            return false;
        }
        if(len1==0&&len2==0){
            return true;
        }
        //dp[i][j]表示s1长度i,s2长度j能不能组成长度为i+j的s3
        vector<vector<int>> dp(len1+1,vector<int>(len2+1));
        dp[0][0]=1;
        for(int i=1;i<=len1;i++){
            if(s1[i-1]==s3[i-1]){
                dp[i][0]=dp[i-1][0];
            }else{
                dp[i][0]=0;
            }
        }
        for(int i=1;i<=len2;i++){
            if(s2[i-1]==s3[i-1]){
                dp[0][i]=dp[0][i-1];
            }else{
                dp[0][i]=0;
            }
        }


        for(int i=1;i<=len1;i++) {
            for(int j=1;j<=len2;j++) {
                int flag1=dp[i][j-1]*(s2[j-1]==s3[i+j-1]? 1 :0);
                int flag2=dp[i-1][j]*(s1[i-1]==s3[i+j-1]? 1 :0);

                int x=flag1+flag2;
                
                if(x>0) {
                    dp[i][j]=1;
                }
                else {
                    dp[i][j]=0;
                }
            }
        }
        return dp[len1][len2];
    }
};

int main(int argc, char** argv){


    string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
    Solution s;
    cout<<s.isInterleave(s1,s2,s3)<<endl;
	return 0;
}

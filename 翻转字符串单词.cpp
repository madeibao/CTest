
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        cout<<n<<endl;
        int begin=0,end;

        for(int i=0;i<n+1;i++) {
           if(s[i]==' '||s[i]=='\1') {
               for(end=i-1;begin<end;begin++,end--) {
                   swap(s[begin],s[end]);
               }
               // 从下一个空格+1的位置重新开始
               begin=i+1;
           }
        }
        
               // 从下一个空格的位置重新开始
        return s;
    }
};


int main(int argc,char** argv) {
    string str ="Let's take LeetCode contest";
    Solution s;
    cout<<s.reverseWords(str)<<endl;
    return 0;
}


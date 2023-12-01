
#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        for(int i =  0 , j = 0; i < chars.size() && j < chars.size();){
            int count = 0;
            while(j < chars.size() && chars[j] == chars[i]){
                j++;
                count++;
            }
            if(count > 1) {
                ans = ans + chars[i] + to_string(count);
                i = j;
            }
            else {
                ans = ans + chars[i];
                i++;
            }

        }
        for(int i = 0 ; i < ans.size() ; i++){
            chars[i] = ans[i];
        }
        return ans.size();
    }
private:
    string ans;
};


int main() {


    vector<char> chars = {'a','a','b','b','c','c','c'};
    Solution s2;
    cout<<s2.compress(chars)<<endl;
    return 0;
}

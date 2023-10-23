



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {

        int index = 0;
        const int size = 32;
        string binary = bitset<size>(n).to_string();
        for(int i=0;i<binary.size();i++) {
            if(binary[i]=='1'){
                index = i;
                break;
            }
        }

        string str2 = binary.substr(index);
        
        int result = 0;
        for(int i=0,j=1;j<str2.size();j++) {

            if(str2[j]=='1') {
                result = max(result,j-i);
                i = j;
            }
        }
        return result;
    }
};

int main() {

    Solution s2;
    cout<<s2.binaryGap(22)<<endl;

    return 0;
}


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Solution {
public:
    int largestArea(vector<int> &A){
        int len = A.size();
        if(len<3){return 0;}
        sort(A.begin(),A.end());
        reverse(A.begin(),A.end());
        for(auto i = A.begin();i<A.end();i++) {
            if(*i< (*(i+1)+*(i+2))) {
                return *i +(*(i+1)+*(i+2));
            }
        }
        return 0;
    }
};
int main() {
    vector<int> res = {3,2,3,4};
    Solution s;
    cout<<s.largestArea(res);
    return 0;
}




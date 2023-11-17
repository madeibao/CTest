

#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string oddString(vector<string>& words) {

        map<vector<int>,vector<string> > map2;
        for(auto &s: words) {
            vector<int> vec;
            for(int i=1;i<s.size();i++) {
                vec.push_back(s[i]-s[i-1]);
            }
            map2[vec].push_back(s);
        }

        for (auto it = map2.begin(); it != map2.end(); it++) {
            if (it->second.size() == 1)
            return (it->second)[0];
        }
    }
};

int main() {

    vector<string> nums = {"aaa","bob","ccc","ddd"};
    vector<string> nums2 = {"ddd","poo","baa","onn"};

    Solution s2;
    cout<<s2.oddString(nums2)<<endl;
    return 0;
}

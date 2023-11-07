


class Solution {
public:
    int thirdMax(vector<int>& nums) {

        set<int> set2;

        for(auto i:nums) {
            set2.insert(i);
        }

        vector<int> res(set2.begin(),set2.end());

        int n = res.size();
        if(res.size()<3) {
            return res[n-1];
        }
        else {
            return res[n-3];
        }

    }
};




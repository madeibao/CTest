


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> Hash, Hash1;
        vector<int> ans;
        for (auto &i : nums1){
            ++Hash[i];
        }
        for (auto &i : nums2){
            ++Hash1[i];
        }
        for (auto &it : Hash){
            if (Hash1.find(it.first) != Hash1.end()){
                ans.emplace_back(it.first);
            }
        }
        return ans;
    }
};






class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> cnt;

        for(auto i:words) {
            ++cnt[i];
        }

        vector<string> res;

        for(auto i:cnt) {
            res.push_back(i.first);
        }

        sort(res.begin(),res.end(),[&](const string a,const string b) {
            return cnt[a]==cnt[b]?a<b:cnt[a]>cnt[b];
        });

        res.erase(res.begin()+k,res.end());
        return res;


    }
};
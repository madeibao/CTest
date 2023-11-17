

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {

        vector<pair<int,int>> res;

        for(int i:arr){
            res.push_back(make_pair(i,getNum(i)));
        }
        
        sort(res.begin(),res.end(),compare);

        vector<int> result;

        for(auto i:res) {
            result.push_back(i.first);
        }
        return result;
    }

    static bool compare(pair<int,int> pa, pair<int,int> pb) {
        if(pa.second==pb.second) {
            return pa.first<pb.first;
        }   
        return pa.second<pb.second;
    }

    static int getNum(int n) {

        int res= 0;
        while(n!=0) {
            n =n&(n-1);
            res+=1;
        }
        return res;
    }
};
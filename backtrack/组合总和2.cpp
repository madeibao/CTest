

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
 	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    	sort(candidates.begin(), candidates.end());
    	backtrace(candidates, target, 0);
    	return res;
  	}

private:
  vector<vector<int>> res;
  vector<int> cur;

  void backtrace(vector<int>& candidates, int target, int start) {
  	if(target<0) { return;}
  	if(target==0) {
  		res.push_back(cur);
  		return;
  	}

  	for(unsigned int i=start;i<candidates.size();i++) {
  		if(i>start&&candidates[i]==candidates[i-1]) { continue;}
  		cur.push_back(candidates[i]);
  		backtrace(candidates,target-candidates[i],i+1);
  		cur.pop_back();
  	}
  }

};


int main(){

    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    Solution s2;
    vector<vector<int>> res;
    res = s2.combinationSum2(candidates, target);
    for(auto i:res) {
        for(auto j:i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}

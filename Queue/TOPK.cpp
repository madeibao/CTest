

// 高频元素，前面 K 个高频元素
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
	struct cmp {
		bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
			return a.second < b.second;
		}
	};

    vector<int> topKFrequent(vector<int>& nums, int k) {
    	map<int, int> map2;
    	for(int i:nums) {
    		++map2[i];
    	}

    	// 优先权队列
    	priority_queue<pair<int, int>,vector<pair<int, int>>, cmp> queue;

    	for(auto it = map2.begin(); it != map2.end(); ++it) {
    		queue.push(*it);
    	}

		// priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
        // for(auto & count : counts) {
        //     pq.push(count);
        // }

        // 注意的是，res 一定要初始化，并且将初始化大小为k 
        vector<int> res(k);
    	for(int i=0;i<k;i++) {
    		res[i] = queue.top().first;
    		queue.pop();
    	}

    	return res;
    }
};


class Solution {
public:
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int>mp;
        for( auto num : nums )  ++mp[num];
        vector<pair<int,int>> vec;
        for( auto it = mp.begin();it!=mp.end();it++ ){
            vec.push_back(pair<int,int>{it->second,it->first});
        }
        sort(vec.begin(),vec.end(),greater<>{});        
        for( auto it = vec.begin();it!=vec.begin()+k;it++ ){
            ans.push_back(it->second);
        }
        return ans;
    }   
};


int main(int argc, char* argv[]) {

	vector<int> nums = {1,1,1,2,2,3};
	int k =2;
	Solution s2;
	vector<int> res;
	res= s2.topKFrequent(nums, k);
	for(auto i:res) {
		cout<<i<<" "<<endl;
	}
	return 0;
}
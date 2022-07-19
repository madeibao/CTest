


#include <string.h>
#include<bits/stdc++.h>
#include <iostream>

using namespace std;



typedef pair<int, int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {                
        // [數字 : 出現次數]
        unordered_map<int, int> m;
        for (int val : nums) ++m[val];


        unordered_map<int, int> m;
    	for(int val:nums) m[val]++;
        // 預設為依照第一個元素排列，由大到小
        /*
             priority_queue
            -----------------
        ==> (1,3) (2,2) (3,1)  ==> 
            -----------------             
        */


       	// 优先权队列
        priority_queue<pair<int, int>> q;
        for (auto it : m) q.push( make_pair(it.second, it.first) );

        // 注意和 queue 不一樣要用 top 而不是 front
        vector<int> res;

    	// 按照 最高的 k 元素。
        for (int i = 0; i < k; ++i) {
            res.push_back( q.top().second ); 
            // 弹出元素。
            q.pop();
        }
        return res;
    }
};




int main(int argc, char** argv) {


	vector<int> nums = {1,1,1,2,2,3};
		int k(2);
	Solution s;
	vector<int> res;
	res = s.topKFrequent(nums,k);
	for(int i:res) {
		cout << i<<" ";
	}
	return 0;
}

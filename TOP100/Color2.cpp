
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {

    	int pa = 0, pb= nums.size()-1;

    	int i =0;
    	while(i <=pb) {
    		if(nums[i] == 2) {
    			swap(nums[i++], nums[pb--]);
    		}
    		else if(nums[i] == 0) {
    			swap(nums[i++], nums[pa++]);
    		}
    		else {
    			i++;
    		}
    	}
    }
};


int main(int argc, char** argv) {

	vector<int> colors {2,0,2,1,1,0};
	Solution solution;
	solution.sortColors(colors);
	for(int i:colors) {
		cout<<i<<" "<<endl;
	}
	return 0;
}

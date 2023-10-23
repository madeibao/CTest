

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {


    	if(ratings.size()<2) {
    		return ratings.size();
    	}

    	int size = ratings.size();
    	vector<int> num(size, 1);

    	for(int i=1;i<size;i++) {
    		if(ratings[i]>ratings[i-1]) {
    			num[i] = num[i-1]+ 1;
    		}
    	}

		for (int i = size - 1; i > 0; --i) {
			if (ratings[i] < ratings[i-1]) {
				num[i-1] = max(num[i-1], num[i] + 1);
			}
		}

		return accumulate(num.begin(), num.end(),0);
    }
};

int main(int argc, char* argv[]) {


	vector<int> res ={2,1,2};
	Solution s;
	cout<<s.candy(res)<<endl;
	retunr 0;
}



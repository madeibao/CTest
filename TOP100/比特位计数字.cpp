

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
        vector<int> result(num+1);
        result[0] = 0;
        for(int i = 1; i <= num; i++)
        {
            if(i % 2 == 1)
            {
                result[i] = result[i-1] + 1;
            }
            else
            {
                result[i] = result[i/2];
            }
        } 
        return result;
    }

};


int main(int argc, char** argv) {

	vector<int> res;
	Solution s2;
	res = s2.countBits(5);
	for(int i:res) {
		cout << i<<" "<<endl;

	}
	return 0;
}
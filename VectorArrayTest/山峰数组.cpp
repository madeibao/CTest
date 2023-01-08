


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int i = 0;
        int j = A.size()-1;

        while (i < A.size() - 1) {
            if (A[i] < A[i+1]) {
                i++;
            }
            else {
            	break;
            }
        }

        while (j > 0) {
            if (A[j] < A[j-1]) {
                j--;
            }
            else{
            	break;
            } 
        }

        return j != 0 && i != A.size() - 1 && i == j;
    }
};

int main() {
	vector<int> res = {0,3,2,1};
	Solution s2;
	cout<<s2.validMountainArray(res)<<endl;


}

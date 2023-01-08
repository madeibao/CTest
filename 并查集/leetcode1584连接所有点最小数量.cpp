

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> A, B;
    struct dis{
        int a;
        int b;
        int d;
        dis(int aa, int bb, int dd):a(aa),b(bb),d(dd){ }
        bool operator< (dis& x){
            return d<x.d;
        }
    };
    int find(int a){
        if(a!=A[a]) A[a] = find(A[a]);
        return A[a];
    }
    void join(int a, int b){
        if(B[a]<B[b])  {
			A[find(b)] = find(a);
            B[a] += B[b];
        }
        else {
        	A[find(a)] = find(b);
        	B[b]+=B[a];
        }
    }


    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<dis> nums;
        A = vector<int>(n, 0);
        B = vector<int>(n, 1);
        for(int i=1;i<n;i++) A[i]=A[i-1]+1;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                int d = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                nums.push_back(dis(i, j, d));
            }
        }

        sort(nums.begin(), nums.end());
        int res = 0;
        for(auto& num:nums) {
            if(find(num.a)==find(num.b)) {
            	continue;
            }
            res += num.d;
            join(num.a, num.b);
        }
        return res;
    }
};

int main(int argc, char* argv[]) {

	vector<vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
	Solution s2;
	cout<<s2.minCostConnectPoints(points)<<endl;
}


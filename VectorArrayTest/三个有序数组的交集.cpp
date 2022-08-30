

#include<vector>
#include<map>
#include<iostream>
using namespace std;


class Solution{
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3){
        map<int,int> tmp;
        for(auto it:arr1) {
            tmp[it]++;
        }
        for(auto it:arr2) {
            tmp[it]++;
        }
        for(auto it:arr3) {
            tmp[it]++;
        }

        vector<int> res;
        for(auto it:tmp) {
            if(3==it.second) {
                res.push_back(it.first);
            }
        }
        return res;

    }
};
int main() {
    vector<int> i1 = {1,2,3,4,5};
    vector<int> i2 = {1,2,5,7,9};
    vector<int> i3 = {1,3,4,5,8};
    Solution s;
    vector<int> mn = s.arraysIntersection(i1,i2,i3);
    for(int i=0;i<mn.size();i++) {
        cout<<mn[i]<<" "<<endl;
    }
    return 0;
}




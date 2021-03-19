
#include<iostream>
using namespace std;

class Solution {
public:
    int minNumberdisappered(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0;i < n;i++) {
            //@ 把元素放到正确的位置上
            if(arr[i] < n && arr[i] > 0)
                swap(arr[i],arr[arr[i]-1]);
        }
        
        //@ 第一个不符合位置和数据关系的数据
        for(int i = 0;i < n;i++)
            if(arr[i] != i+1)
                return i+1;


        // 默认的返回时 n + 1
        return n + 1;
    }
};


int main(int argc, char* argv[]) {

	vector<int> res {1,2,3,4};
	Solution s;
	cout<<s.minNumberdisappered(res)<<endl;
	return 0;
}

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        vector<string> sort_nums;
        for(auto &i : numbers) // 循环取出numbers中的元素放入i、
            sort_nums.push_back(to_string(i)); // 将数组放入到string中

        // 匿名函数
        auto it = [](const string &a , const string &b){
            return a+b<b+a;
        };

        sort(sort_nums.begin(), sort_nums.end(),it); // 根据第三个参数定义的比较规则将string中的元素排序
        string result = "";
        for(auto &s : sort_nums) // 循环取出sortedNums中的元素放入s中
            result += s;
        return result;
    }
};

int main(int argc, char** argv) {

	vector<int> nums = {12,21};
	Solution s2;
	cout<<s2.PrintMinNumber(nums)<<endl;
	return 0;
}

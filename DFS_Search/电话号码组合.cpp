
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<char,string> map={{'2',"abc"},{'3',"def"},{'4',"ghi"},
                                    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},
                                    {'8',"tuv"},{'9',"wxyz"}};
    string s; //储存遍历字符串
    vector<string> ans; //储存最终结果
    void backtracking( string digits,int index)
    {
        if(index==digits.size()) //如果下标为digits长度时，一组遍历就完成了
        {
            ans.push_back(s); //储存字符串
            return;
        }
        string a=map[digits[index]]; //当前数字的字母串
        for(int i=0;i<a.size();i++)
        {
            s.push_back(a[i]); //将当前字母插入字符串
            backtracking(digits,index+1); //递归下个数字
            s.pop_back(); //一组字母组合已经储存，将字母串末尾字母出队，遍历当前数字的下个字母
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) {
            return {};
        }
        s.clear();
        ans.clear();
        backtracking(digits,0);
        return ans;
    }
};

int main() {

	string digits = "2";
	vector<string> res;
	Solution s2;
	res = s2.letterCombinations(digits);
	for(auto i:res) {
		cout<<i<<" ";
	}
	return 0;
}

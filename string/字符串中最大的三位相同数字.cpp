



#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {

		// 滑动窗口长度
		int windowSize = 3;
		int len = num.length();
		// 顺序遍历字符串

        string result;
		vector<string> strs;
		for (int i = 0; i <= len - windowSize; i++)
		{
            string res="";
			// 子字符串要连续，且各字符不相等
			if (num[i] == num[i + 1] && num[i + 1] == num[i + 2] && num[i] == num[i + 2])
			{
                res+=num[i];
                res+=num[i+1];
                res+=num[i+2];
                result = max(result,res);
			}
		}

        return result;
    }
};

int main() {
    string num = "6777133339";
    Solution s2;
    cout<<s2.largestGoodInteger(num)<<endl;

    return 0;
}




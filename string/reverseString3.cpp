
#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    //局部交换的函数 从begin 到 end （闭区间）逆序
    void reverse_substr(string& s, int begin, int end){
        while(end > begin){
            //使用swap函数
            swap(s[begin], s[end]);
            begin++;
            end--;
        }
    }
    string reverseStr(string s, int k) {
        int length = s.size();
        if (length <= 1) return s;
        int i = 0;

        while (i < length){
            //i 到i+k闭区间的翻转
            // 判断剩余部分不足k个的直接全部翻转
            if (i + k - 1 >= length) reverse_substr(s, i, s.size()-1);
            else reverse_substr(s, i, i+k-1);
            //i每次需要递增2k
            i = i + 2*k;
        }
        return s;
    }

};


int main(int argc, char** argv) {

	string str = "abcdefg";
	int k = 2;

	Solution s;
	cout<<s.reverseStr(str,k)<<endl;
	return 0;
}




#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string strs) {

        // 构建一个字典
        // 字典的构建是逆的顺序。
        unordered_map<char, char> map2 = {{')','('},{']','['},{'}','{'}};

        stack<char> stack2;
        for(char c:strs) {
            if(c=='(' ||c=='[' ||c=='{') {
                stack2.push(c);
            }

            // 首先是栈不为空，然后逐渐的弹出栈中的序列。
            else if(stack2.size()>0&& stack2.top()==map2[c]) {
                stack2.pop();
            }
            else {
                return false;
            }
        }
        return stack2.empty();
    }
};

int main(int argc, char* argv[])  {

    string str2 ="()(){}";
    Solution s;
    cout<<s.isValid(str2)<<endl;
    return 0;
}






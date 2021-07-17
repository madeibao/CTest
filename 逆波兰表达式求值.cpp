



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (int i = 0; i < tokens.size(); i ++ ) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int a = stk.top();                      //取得栈顶的两个数
                stk.pop();
                int b = stk.top();
                stk.pop();

                if (tokens[i] == "+") stk.push(b + a);  //计算结果，再推入栈
                if (tokens[i] == "-") stk.push(b - a);
                if (tokens[i] == "*") stk.push(b * a);
                if (tokens[i] == "/") stk.push(b / a);
            }                                           //当前为数字就直接入栈，为运算符就出栈两个数来计算
            else stk.push(stoi(tokens[i]));             //stoi表示string to int，字符串转整数
        }

        int res = stk.top();                            //最后剩下的栈顶元素即是逆波兰表达式的计算结果

        return res;
    }
};


int main(int argc, char **argv) {

	vector<string> tokens {"2","1","+","3","*"};
	Solution s;
	cout<<s.evalRPN(tokens);
	return 0;

}

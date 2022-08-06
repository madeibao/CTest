
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
	int strToInt(string str) {
		if(str.size()==0) {
			return 0;
		}
		unsigned int i= 0;
		long ans=0;
		bool negative = false;

		// 跳过前面的空格位置。
		while(str[i]==' ') {
			i++;
		}
		// 如果第一个不为空的位置上是负号

		if(str[i]=='-') {
			negative = true;
			i++;
		}
		// 如果是第一个符号位为“+”
		else if(str[i]=='+') {
			i++;
		}
		// 逐渐的向后面来遍历。

		for(;i<str.size(); i++) {
			if(str[i]>='0' && str[i] <='9') {
				ans = ans*10+(str[i]-'0');

				if(ans>INT_MAX&&negative==true) {
					return INT_MIN;
				}

				if(ans>INT_MAX&&negative==false) {
					return INT_MAX;
				}
			}
			// 碰到非有效的数字，当即推出。
			else {
				break;
			}
		}

		// 返回是否为负号开头的
		return negative==true?-ans:ans;
	}

};

int main(int argc, char* argv[]) {

	string str ="123";
	Solution s;
	cout<<s.strToInt(str);
	return 0;
}

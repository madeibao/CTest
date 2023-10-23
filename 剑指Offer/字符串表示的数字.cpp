
#include "iostream"

using namespace std;

class Solution {
public:
    int strToInt(string str) {

    	int size = 0;
    	size = str.size();
    	if(size == 0) {
    		return 0;
    	}

    	int i =0;
    	// 用long 来进行存储
    	long ans = 0;

    	// 判断是否为负数
    	bool negative = false;

    	while(str[i]==' ') {
    		i++;
    	}

		if(str[i]=='-') {
			negative = true;
			i++;
		}
		// 如果是第一个符号位为“+”
		else if(str[i]=='+') {
			i++;
		}

		for(;i<str.size();i++) {
			if(str[i]>='0'&&str[i]<='9') {
				ans = ans*10+(str[i]-'0');

				if(ans>INT_MAX&&negative==true) {
					return INT_MIN;
				}

				if(ans>INT_MAX&&negative==false) {
					return INT_MAX;
				}
			}
			else {
				// 如果是遇到了非法的数字
				break;
			}
		}

		return negative==true?-ans:ans;
    }
};


int main(int argc, char** argv) {

	string str ="-91283472332";
	Solution s2;
	cout<<s2.strToInt(str)<<endl;
	return 0;
}
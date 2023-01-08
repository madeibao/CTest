


// to-lower-case
#include <cctype>
#include <iostream>
using namespace std;


class Solution {
public:
    string toLowerCase(string str) {
        int ls = str.size();
        for (int i = 0; i < ls; ++i) {
            if (isupper(str[i])) {
                str[i] = str[i] - 'A' + 'a';
            }
        }
        return str;
    }
};

int main(int argc, char* argv[]) {

	string s = "Hello";
	Solution s2;
	cout<<s2.toLowerCase(s)<<endl;
	return 0;
}

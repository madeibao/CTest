
#include "iostream"
#include "bits/stdc++.h"

using namespace std;
class Solution {
public:

    string sum(string a, string b) {
        int i = (int)a.size() - 1, j = (int)b.size() - 1;
        int add = 0, x, y, res;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            x = i >= 0 ? a[i] - '0' : 0;
            y = j >= 0 ? b[j] - '0' : 0;
            res = x + y + add;
            ans.push_back(res % 2 + '0');
            add = res / 2;
            i --;
            j --;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }

    string addBinary(string a, string b) {
        return sum(a, b);
    }
};


int main(int argc, char* argv[]) {

	string stra ="11";
	string strb = "1";

	Solution s;
	cout<<s.addBinary(stra,strb)<<endl;

	return 0;

}

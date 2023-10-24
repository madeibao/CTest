


#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
    string a="asfsagds asf";
    string b="sagd sAsP";
    cout<<*(--a.end())<<endl<<*(--b.end())<<endl;
    return 0;
}



//----------------------------------------------------------------------------------------

// isdigit 方法判断是否为数字

字母（不区分大小写）：isalpha();

大写字母：isupper();

小写字母：islower();

数字：isdigit();

字母和数字：isalnum();




#include "iostream"
#include<bits/stdc++.h>

using namespace std;

int main() {

    string str = "123";
    int res = 0;
    for(int i=0;i<str.size();i++) {
        if(isdigit(str[i])) {
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}


	

	判断是否全部是数字组成
	bool isAlldigit(string_view s) {
		for (auto& ch : s) if (!('0' <= ch && ch <= '9')) return false;
		return true;
	}
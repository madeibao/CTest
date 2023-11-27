

string 的初始化构造函数

string(int n,char c); //用n个字符c初始化


char c = 'a';
string s(1,c);

#include "iostream"
#include<bits/stdc++.h>

using namespace std;

int main() {
    string str = string(2,'a');
    cout<<str<<endl;
    return 0;
}

//_______________________________________________________________________________________________________________


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



—————————————————————————————————————————————————————————————————————————————————————————————————————————————————



#include "iostream"
#include<bits/stdc++.h>

using namespace std;

int main() {
    string str = string(2,'a');
    cout<<str<<endl;

    unordered_set<char> set2(str.begin(),str.end());

    for(auto i:set2) {
        cout<<i<<" ";
    }
    return 0;
}


//-----------------------------------------------------------------------------
// string 的append 方法

#include <iostream>
#include <string>
using namespace std;

// Function to demonstrate append()
void appendDemo(string str1, string str2)
{
    // Appends str2 in str1
    str1.append(str2);
    cout << "Using append():";
    cout << str1 << endl;
}

// Driver code
int main()
{
    string str1("Hello World! ");
    string str2("GeeksforGeeks");

    cout << "Original String:" << str1 << endl;
    appendDemo(str1, str2);

    return 0;
}


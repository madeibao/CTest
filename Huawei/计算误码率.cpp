


#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string compare(string stra,string strb) {
	string ans = "";
	int lens = stra.length();
	int error = 0;

	for(int i=0;i<stra.size();i++) {
		if(stra[i]==strb[i])
			continue;
		else
			error++;
	}

	ans += to_string(error);
	ans += '/';
	ans += to_string(lens);
	return ans;
}

bool isNum(char c) {
	return c>='0' && c<='9';
}

int myStoi(string str) {
	int res = 0;
	for(int i=str.length()-1;i>=0;i--) {
		res+=(str[i]-'0')*pow(10,(i-str.length()+1));
	}

	return res;
}


string decode(string & str) {


	string ans = "";
	string num = "";
	for(int i=0;i<str.size();) {
		if(isNum(str[i])) {
			num+=str[i];
			i++;
			continue;
		}
		else {
			string temp = num;
			int num2 = stoi(temp);
			for(int j=0;j<num2;j++) {
				ans+=str[i];
			}
			num= "";
			i++;
		}
	}

	return ans;
}

int main(){

	string input, output;
	cin>>input>>output;
	string ans = compare(decode(input),decode(output));
	cout<<ans;
	return 0;
}

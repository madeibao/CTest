


#include "iostream"
#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string password) {
    	
    	if(password.length()<8) {
    		return false;
    	}

        bool lowerCase = false;
        bool upperCase = false;
        bool number = false;
        bool other = false;


        // 全部的字符
        for (int i = 1; i < password.size(); i++){
            if (password[i] == password[i - 1])
                return false;    
        }   

		set<char> charSet = {'!','@','#','$','%','^','&','*','(',')','-','+'};

        for(int i=0;i<password.size();i++) {
        	if( password[i]>='0'&& password[i]<='9' ) {
        		number = true;
        	}
        	else if( password[i]>='a'&& password[i]<='z') {
        		lowerCase = true;
        	}
        	else if( password[i]>='A'&& password[i]<='Z') {
        		upperCase = true;
        	}
        	else if( charset.find(password[i])!=charSet.end() ) {
        		other = true;
        	}
        }

        return lowerCase&&upperCase&&number&&other;
    }
};

int main(int argc, char** argv) {

	
	Solution s;
	string str = "IloveLe3tcode!";
	cout<<s.strongPasswordCheckerII(str)<<endl;
	return 0;


}
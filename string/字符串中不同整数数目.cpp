


#include <iostream>
#include <bits/stdc++.h>

using namespace std;



class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> set; 
        for (int i = 0; i < word.length(); i++) {
            if (word[i] <= '9') {
                int j = i;
                while (j < word.length() && word[j] <= '9') j++;
                while (i < j && word[i] == '0') i++;
                set.insert(word.substr(i, j -i)); 
                i = j; 
            }
        }
        return set.size();
    }
};


// ---------------------------------
// 自己的算法

class Solution {
public:
    int numDifferentIntegers(string word) {

        vector<string> res;
        set<string> res2;
        for(int j=0;j<word.size();) {
            string temp = "";
            while(word[j]>='0'&&word[j]<='9'){
                temp+=word[j];
                j++;
            }
            if(temp!="") {
                res.push_back(temp);
            }
            j = j+1;
        }

        for(int i=0;i<res.size();i++) {
            res2.insert(remove(res[i]));
        }

        return res2.size();
    }

    string remove(string str) {
    	int index = 0;
    	for(int i=0;i<str.length()-1;i++) {

    		if(str[i]!='0') {
    			break;
    		}
    		else {
    			index++;
    		}
		}
		return str.substr(index);

    }
};


int main()
{
    string word2 = "a1b01c001";
    Solution s2;
    cout<<s2.numDifferentIntegers(word2)<<endl;
    return 0;
}







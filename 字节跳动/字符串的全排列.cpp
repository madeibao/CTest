
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> result;
    vector<string> Permutation(string str) {
        if(str.size() == 0){
            return result;
        }
        Permutation1(str, 0);
        sort(result.begin(), result.end());
        return result;
    }

    void Permutation1(string str, int begin){
        if(begin == str.size() - 1){
            result.push_back(str);
            return;
        }
        for(int i = begin; i < str.size(); i++){
            if(i != begin && str[i] == str[begin]){
                continue;
            }
            swap(str[i], str[begin]);
            Permutation1(str, begin + 1);
            swap(str[i], str[begin]);
        }
    }
};


int main(int argc, char **argv) {

	Solution s;
	vector<string> res;
	res = s.Permutation("abc");

	for(string s:res) {
		cout<<s<<" "<<endl;
	}
	return 0;
}

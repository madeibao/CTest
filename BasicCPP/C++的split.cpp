
#include<string>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<string> stringSplit(const string& str, char delim) {
    size_t previous = 0;
    size_t current = str.find(delim);
    vector<string> elems;
    while (current != string::npos) {
        if (current > previous) {
            elems.push_back(str.substr(previous, current - previous));
        }
        previous = current + 1;
        current = str.find(delim, previous);
    }
    if (previous != str.size()) {
        elems.push_back(str.substr(previous));
    }
    return elems;
}

int main(){

    string str2 = "hello,world,mayuan,graduate,student";
    char c = ',';
    vector<string> res;
    res = stringSplit(str2, c);
    for(auto i:res) {
        cout<<i<<" ";
    }
    return 0;
}





#include<iostream>
#include<bits/stdc++.h>

using namespace std;


#include <algorithm>

int main() {
    vector<string> strings = {"apple", "banana", "cherry", "date"};

    // Sort the vector of strings in descending order of string size using a lambda function
    sort(strings.begin(), strings.end(), [](const string& a, const string& b) {
        return a.size() > b.size();
    });

    // Print the sorted vector of strings
    for (const string& str : strings) {
        cout << str << endl;
    }

    return 0;
}


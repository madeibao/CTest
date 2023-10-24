

#include "iostream"
#include "bits/stdc++.h"

using namespace std;

int main() {

    string h = "aeiouAEIOU";

    string a= "amend";
    
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
        if (h.find_first_of(a[i]) != string::npos) {
            count++;
        }
    }

    cout<<count<<endl;
    return 0;
}

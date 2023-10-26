

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


//------------------------------------------------------------------------------------------------------------
// 查找指定的字符来进行


#include "iostream"
#include<bits/stdc++.h>

using namespace std;

int main() {

    string str = "abcdefgHI";
    if(str.find('a')!=-1) {
        cout<<"find"<<endl;
    }
    return 0;
}
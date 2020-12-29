/**


#include<iostream>
#include<bits/stdc++.h>

const int MAX =3;
using namespace std;

int main() {
    int num[MAX] = {10,20,30};
    int *ptr[MAX];

    for(int i=0;i<MAX;i++) {
        ptr[i] = &num[i];
    }

    for(int i=0;i<MAX;i++) {
        cout<<*ptr[i]<<" "<<endl;
    }
    return 0;
}
*/



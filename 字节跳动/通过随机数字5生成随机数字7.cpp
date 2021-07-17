
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Rand5()
{
    int m = rand() % 5 + 1;
    return m;
}

int Rand7() {
    int x = 22;
    while (x > 21)
        x = Rand5() + (Rand5() - 1) * 5;
    return x % 7 + 1;
}

int main() {

    for(int i=0;i<100;i++) {
        cout<<Rand7()<<endl;
    }
    return 0;
}

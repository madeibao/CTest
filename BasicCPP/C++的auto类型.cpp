
#include<iostream>
#include<typeinfo>
using namespace std;

int main(){

    int a=10;
    auto a_auto = a;
    long long b = 100;
    auto b_auto = b;
    cout<<typeid(b_auto).name()<<endl;
    cout<<typeid(a_auto).name()<<endl;
    return 0;
}



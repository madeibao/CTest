
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


/**
        Linux  ./a.out | c++filt -t
        
        
        bool:                     b
         
        char:                     c
        signed char:              a
        unsigned char:            h
         
        (signed) short (int):     s
        unsigned short (int):     t
         
        (signed) (int):           i
        unsigned (int):           j
         
        (signed) long (int):      l
        unsigned long (int):      m
         
        (signed) long long (int): x
        unsigned long long (int): y
         
        float:                    f
        double:                   d
        long double:              e

        Linux下输出完整的名字需要：
        ./execute | c++filt -t

*/

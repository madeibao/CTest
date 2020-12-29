
#include <iostream>
#include <stdlib.h>

using namespace std;

int add(int num1, int num2);
int main() {
    int a= 3,b=4;
    int sum2 = add(a, b);
    cout<<sum2<<" "<<endl;
}

int add(int num1, int num2) {
    int sum,carry;
    do {
        sum = num1^num2;
        carry = (num1&num2)<<1;
        num1= sum;
        num2= carry;
    }while(num2!=0);
    return num1;
}



#include <iostream>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int add(int a, int b) {
        int temp, temp2;
        while(b!=0) {
            temp = a^b;
            temp2= (unsigned int)(a&b)<<1;
            a= temp;
            b = temp2;
        }
        return a;
    }
};



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
        carry = (unsigned int)(num1&num2)<<1;
        num1= sum;
        num2= carry;
    }while(num2!=0);
    return num1;
}


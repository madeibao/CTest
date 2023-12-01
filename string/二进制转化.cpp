





#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;
    for (int i = binary.size() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }
    return decimal;
}

int main(int argc, char* argv[]) {

    string str = "100";
    cout<<binaryToDecimal(str)<<endl;
    return 0;
}




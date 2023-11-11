


#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// 辗转相除法
// 确保 a > b
int gcd(int a,int b)
{
	if(a % b == 0)
		return b;
	else
		return gcd(b ,a % b);
}

int main() {
    int m = 12, n = 4;
	cout<<gcd(m,n)<<endl;

    return 0;
}
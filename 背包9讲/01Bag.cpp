

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 100;

// 背包转换公式
int maxValue(int n, int c, int*w, int* p) {
    int f[N][N];
    int i=0,j=0;

    for(i=1;i<=n;i++) {
        for(j=1;j<=c;j++) {
            f[i][j] = f[i-1][j];
            if(j>=w[i]) {
                f[i][j] = max(f[i-1][j],f[i-1][j-w[i]]+p[i]);
            }
        }
    }
    return f[i-1][j-1];
}

int main() {

    int n;
    int c;

    c = 10;  // 背包容量
    n = 5;   // 物体数量
    // 数组前面的0,没有意义，只是方便计算
    int w[6]={0,2,2,6,5,4};   //物重w
    int p[6]={0,6,3,5,4,6};   //物价p

    int res;
    res = maxValue(n,c,w,p);
    cout<<"final results  "<< res<<endl;
    return 0;
}



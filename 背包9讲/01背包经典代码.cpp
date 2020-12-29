
// 淡出的01背包问题总结
0/1背包问题



题目要求
有N件物品和一个容量为V的背包。第i件物品的费用是c[i]，价值是w[i]。求解将哪些物品装入背包可使这些物品的费用总和不超过背包容量，且价值总和最大。

输入格式
第一行两个整数，N,M空格隔开，分别表示物品数量和背包容积。

接下来有N行,每行两个整数vi,wi,空格隔开,分别表示第i件物品的体积和价格

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,M<1000

0<vi,wi<1000

输入样例
4 5
1 2
2 4
3 4
4 5
输出样例：
8
//--------------------------------------------------------------------------------

/**
 *  python的代码：
 * 
 * 
 * 
 * 
 * 
 * */



#include<iostream>
using namespace std;

const int N = 1010;

int v[N], w[N], dp[N];//dp[N][N]

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i] >> w[i];
    }

    for(int i = 1; i <= n; i++){
        // for(int j = 0; j <= m; j++){
        //     if(j < v[i])
        //         dp[i][j] = dp[i-1][j];
        //     else
        //         dp[i][j]=max(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
        // }

        for(int j = m; j >=v[i]; j--){
            dp[j] = max(dp[j], dp[j-v[i]]+w[i]);
        }
    }
    cout<<dp[m]<<endl;;
    return 0;
}




a, b = map(int, input().split(" "))

w = [0 for i in range(a+1)]
v = [0 for i in range(a+1)]

for i in range(1, a+1):
    temp = input()
    w[i], v[i] = list(map(int, temp.split(" ")))

dp = [0 for i in range(b+1)]

for i in range(1,a+1):
    for j in range(m,0,-1):
        if j>=w[i]:
            f[j] = max(f[j], f[j-w[i]]+v[i])
        else:
            break

print(f[-1])



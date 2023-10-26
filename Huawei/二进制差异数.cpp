


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
using ll = long long;
/*
题目等价于 求 (a[i] ^ a[j] ) > (a[i] & a[j]) 的对数
    00     ^ == &
    10/01  ^ > &
    11     ^ < &
等价于： 求 最高位位置不同 的 数对 个数
*/
int main(){
    int n,x,i;
    ll cnt[32], pre = 0,ans = 0;  // cnt[i] 最高位在i位 -> 计数
    memset(cnt,0,sizeof(cnt)); 
    scanf("%d",&n);
    while(n--) {
        scanf("%d",&x);
        for(i = 0; x > 0; x /= 2, i++); 
        cnt[i]++;
    }
    for(i = 0; i < 32; i++){
        ans += cnt[i] * pre;
        pre += cnt[i];
    }
    printf("%lld\n",ans);
    return 0;
}

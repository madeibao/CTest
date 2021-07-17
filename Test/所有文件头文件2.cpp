
/**

while (~scanf("%d%d",&n,&k)) {

}

从文件来读取其中的值 放在main函数的下面:
int main() {
    freopen("./in.txt", "r", stdin);
    freopen("./out.txt", "w", stdout);
    return 0;
}
#include<iostream>
#include<bits/stdc++.h>

ctrl+shift+c可以快速注释掉多行。
ctrl+shift+x可以取消注释，

    数组的大小的计算式，数组中的元素的个数。
    int ma[] = {2,23,4,3,4,5,5,};
    int len  = sizeof(ma)/sizeof(int);
    cout<<len<<endl;
    int len2 = sizeof(ma)/sizeof(ma[0]);
    cout<<len2<<endl;

*/

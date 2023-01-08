
/**
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
*/

#include <iostream>
using namespace std;
const int N = 1010;
int p[N], n, m;

//查找父亲节点

int find(int x) {
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}
int main() {
    while(true) {
        //处理输入
        cin>>n;
        if(n == 0) break;
        cin>>m;
        //初始化并查集
        for(int i = 1; i <= n; i++)
            p[i] = i;
        while(m--) {
            int a, b;
            cin>>a>>b;
            p[find(a)] = find(b); //合并集合
        }
        int res = 0;
        for(int i = 1; i <= n; i++)
            if(p[i] == i) //找到集合的根节点
                res++;
        cout<<res - 1<<endl;
    }
    return 0;
}



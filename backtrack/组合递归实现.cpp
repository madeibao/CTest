

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
 
using namespace std;
 
const int N = 26;
int n, m;
int sta[N];   //用于存储方案
bool used[N]; //有没有被用过
void dfs(int x)
{
    if (x > m)  //位数符合，可以输出
    {
        for (int i = 1; i <= m; i++)
        {
            printf("%d ", sta[i]);
        }
        printf("\n");
        return;
    }
    for (int i = sta[x - 1] + 1; i <= n; i++) //由于输出是严格递增的由此当前位一定比上一位大
    {
        if (!used[i])  //当前数未被用则进行操作，否则跳过
        {
            sta[x] = i;  //当前位置选i
            used[i] = true; //标记当前位置已使用
            dfs(x + 1);  //向下递归
            used[i] = false; //状态回溯
        }
    } //之后继续寻找下一个没有用过的数
}
 
int main()
{
    scanf("%d%d", &n, &m);
    dfs(1);
    return 0;
}
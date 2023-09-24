
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 6010;
int n;
int happy[N];
int dp[N][2];
int e[N], ne[N], h[N], idx;     //邻接表。e[i]:存放新节点，ne[i]：新节点的next，h[i]：头指针，idx：指向全局的下标
bool has_father[N];             // 判断下表i对应的节点是否有父节点。

void add(int a, int b) {        // 头插法，将b插入到a中，a为父节点，b为子节点
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;       // 构建节点b，让b的next指向a的next，让a的next指向b，更新idx。
}

void dfs(int u) {
    dp[u][1] = happy[u];                        // 初始化构建快乐数
    for(int i = h[u]; i != -1; i = ne[i]) {     // 从树的根节点开始，遍历它下一层的所有孩子节点
        int j = e[i];                           // 找到节点u的孩子节点
        dfs(j);                                 // 采用后序遍历，先向下回溯遍历，再计算结果，将结果结果传递给上一层
        // 注意：这里加的时候要加到最初的起始节点处
        dp[u][0] += max(dp[j][1], dp[j][0]);    // 第一种情况：不选u，则可能最大值为选择孩子或不选孩子
        dp[u][1] += dp[j][0];                   // 第二种情况：选择当前节点，则就不选孩子节点（注意此时可选孙子节点）。
    }
}

int main() {
    // 1、输入数据，构建关系树
    cin >> n;
    for(int i = 1; i <= n; i++) {
    	cin >> happy[i];
    }

    memset(h, -1, sizeof(h));

    for(int i = 0; i < n - 1; i++) {
        int b, a;
        cin >> b >> a;              // b为下级，a为直接上司
        has_father[b] = true;       // b存在父节点
        add(a, b);                  // 构建a为b的父节点关系结构
    }


    // 2、寻找根节点
    int root = 1;
    while(has_father[root] == true) {
    	root++;
    }
    
    // 3、找到最大快乐数
    dfs(root);
    cout << max(dp[root][0], dp[root][1]) << endl;
    
    return 0;
}



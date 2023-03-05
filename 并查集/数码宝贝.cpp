/**

7 5
1 2
2 3
3 1
1 4
5 6

*/


// ----------------------------------------------------------------
// 分成3组

#include<iostream>
using namespace std;

const int N = 100;

int a, b, m, n;             //m, n分别为组数和个数  a, b表示每次在同一个集合的两个数
int father[N];              //集

//在合并之前初始化每个节点为该集合的根节点(每个数都是一个集合)
void init(int n) {
    for (int i = 1; i <= n; i ++ ) father[i] = i;
}

//找到元素x在该集合中的根节点(根节点满足x == father[x])
int findFather(int x) {     //查
    int a = x;  //记录初始节点
    while (x != father[x]) x = father[x];   //循环结束后的x为该集合的根节点
    //路径压缩，将寻找根节点路途中的每个节点指向其根节点，优化之后的查找速度，可不写
    while (a != father[a]) {
        int b = a;      //记录a，防止后面被覆盖
        a = father[a];  //让a指向其父节点
        father[b] = x;  //指向根节点
    }
    return x;
}

//将a b合并到一个集合中
void Union(int a, int b) {  //并
    //分别找到a, b所在结合的根节点
    int Ra = findFather(a);
    int Rb = findFather(b);
    //当a, b不在同一个集合中时将Ra指向Rb或者将Rb指向Rb指向ba
    if (Ra != Rb) {
        father[Ra] = Rb;    //将Ra指向Rb
        //father[Rb] = Ra; 也可以
    }
}

int main() {
    cin >> n >> m;
    init(n);    //在合并集合之前需初始化，勿遗忘
    while (m -- ) {
        cin >> a >> b;
        Union(a, b);    //每输入两个数，将其合并到一个集合中
    }
    int ans = 0;    //用来记录集合的个数
    //遍历所有数，根节点的数量即为集合的数量
    for (int i = 1; i <= n; i ++ ) {
        if (i == findFather(i)) ans ++ ;    //i为其所在结合的根节点
    }
    cout << ans << endl;
    return 0;
}




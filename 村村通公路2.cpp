

// 村村通公路的畅通工程：
// 并查集的算法。


   某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。
    省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？
输入描述:
    测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，
    分别是城镇数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。 
    注意:两个城市之间可以有多条道路相通,也就是说
    3 3
    1 2
    1 2
    2 1
    这种输入也是合法的
    当N为0时，输入结束，该用例不被处理。
输出描述:
    对每个测试用例，在1行里输出最少还需要建设的道路数目。



// ---------------------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000;
int father[maxn];
int height[maxn];

void Initial(int n){
    for(int i=0;i<=n;i++){
        father[i] = i;
        height[i] = 0;
    }
}

int Find(int n){
    if(father[n]!=n){
        father[n] = Find(father[n]);
    }
    return father[n];
}

void Union(int x, int y){
    int xr = Find(x);
    int yr = Find(y);
    if(xr!=yr){
        if(height[xr]<height[yr]){
        father[xr] = yr;
    }else if(height[xr]>height[yr]){
        father[yr] = xr;
    }else{
        father[yr] = xr;
        height[xr]++;
    }
    }
    
    return;
}

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            break;
        }
        int m;
        scanf("%d",&m);
        Initial(n);
        while(m--){
            int a,b;
            scanf("%d",&a);
            scanf("%d",&b);
            Union(a,b);
        }
        int ans = -1;
        for(int i=1;i<=n;i++){
            if(Find(i)==i){
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
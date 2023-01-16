

// ----------------------------------------------------------------
// 并查集的经典应用

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const static int N = 205;
    int parent[N];
    int count = 0;

    // 查找 x 的根结点
    int find(int x){
        return x==parent[x]?x:find(parent[x]);
    }
    // 合并,把 y 合并到 x内
    void megre(int x,int y){
        int root1 = find(x);
        int root2 = find(y);
        // 判断 x与y 是否位于同一个并查集分量内，是就返回，不需要合并
        if(root1 == root2) return;
        // y的根结点的父亲更新为x的根结点
        parent[root2] = root1;
        // 合并成功说明少了一个点
        --count;
    }
    // 初始化并查集数据
    void init(int n){
        // 所有点的根结点初始默认是本身
        for(int i=0;i<n;++i)
            parent[i]=i;
        // 初始count大小就是n
        count = n;
    }

    // 并查集的 第一题 实战
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // 初始化并查集
        init(n);
        for(int i = 0;i<n;++i){
            for(int j=0;j<n;++j){
                if(isConnected[i][j]==1){
                    megre(i,j);
                }
            }
        }
        return count;
    }
};

int main(int argc, char** argv) {
	vector<vector<int> > isconnected = {{1,1,0},
                                        {1,1,0},
                                        {0,0,1}};
	Solution s2;
	cout<<s2.findCircleNum(isconnected)<<endl;
	return 0;
}

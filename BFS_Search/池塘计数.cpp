
农夫约翰有一片 N∗MN∗M 的矩形土地。

最近，由于降雨的原因，部分土地被水淹没了。

现在用一个字符矩阵来表示他的土地。

每个单元格内，如果包含雨水，则用”W”表示，如果不含雨水，则用”.”表示。

现在，约翰想知道他的土地中形成了多少片池塘。

每组相连的积水单元格集合可以看作是一片池塘。

每个单元格视为与其上、下、左、右、左上、右上、左下、右下八个邻近单元格相连。

请你输出共有多少片池塘，即矩阵中共有多少片相连的”W”块。

输入格式
第一行包含两个整数 NN 和 MM。

接下来 NN 行，每行包含 MM 个字符，字符为”W”或”.”，用以表示矩形土地的积水状况，字符之间没有空格。

输出格式
输出一个整数，表示池塘数目。

数据范围
1≤N,M≤10001≤N,M≤1000
输入样例：


10 12
W…WW.
.WWW…WWW
…WW…WW.
…WW.
…W…
…W…W…
.W.W…WW.
W.W.W…W.
.W.W…W.
…W…W.


输出样例：
3


//----------------------------------------------------------------
//---------------------------------------------------------------------------------________________________________________________________________

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

const int N = 1005;
char g[N][N];
int n, m;
typedef pair<int, int> PII;

int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,1,-1,1,-1};

void bfs(int i, int j) {
    g[u][v] = '.';
    queue<PII> q;
    q.push({u, v});
    while (!q.empty()) {

    	auto t = q.front();
    	q.pop();
    	for(int i=0;i<8;i++) {

    		int x = t.first + dx[i];
    		int y = t.second + dy[i];

    		if(a>=0&&b>=0&&a<n&&b<m&&g[a][b]=='W') {
                g[a][b] = '.';
                q.push({a, b});
            }
    	}
    }
}

int main(int argc, char** argv) {

   	scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%s", g[i]);
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j]=='W') {
                ans++;
                bfs(i, j);
            }
        }
    }
	return 0;
}
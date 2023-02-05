#include<iostream>
#include<algorithm>
#include<cstdio>
#include<math.h>
#include<cstring>
#include<bitset>
#include<vector>
#include<queue>

//#define ls (p<<1)
//#define rs (p<<1|1)

#define over(i,s,t) for(register int i = s;i <= t;++i)
#define lver(i,t,s) for(register int i = t;i >= s;--i)
//#define int __int128
#define lowbit(p) p&(-p)
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int M = 2007;

char ch;

struct node{
    char val;
    node *ls;
    node *rs;
};

void build(node *&t){//注意要用引用变量
    cin>>ch;
    if(ch == '#')t = NULL;
    else {
        t = new node;
        t->val = ch;
        build(t->ls);
        build(t->rs);
    }
}

void print(node *t) {
    if(t) {
        print(t->ls);
        cout<<(t->val);
        print(t->rs);
    }
}

void solve(){
    node *t = NULL;
    build(t);
    print(t);
}
int main()
{
    solve();
    return 0;
}


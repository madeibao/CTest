


const int maxn = 1e5 + 50;
bool vis[maxn];
int son[maxn][26],idx;
class Trie {
public:
    Trie() {
        memset(vis,false,sizeof vis);
        memset(son,0,sizeof son);
        idx = 0;
    }
    
    void insert(string word) {
        int p = 0;
        for(auto x : word){
            int u = x - 'a';
            if(!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        vis[p] = true;
    }
    
    bool search(string word) {
        int p = 0;
        for(auto x : word){
            int u = x - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
        }
        return vis[p];
    }
    
    bool startsWith(string prefix) {
        int p = 0;
        for(auto x : prefix){
            int u = x - 'a';
            if(!son[p][u]) return false;
            p = son[p][u];
        }
        return true;
    }
};




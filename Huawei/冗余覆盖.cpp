

//在s2中找到第一个包含s1中所有字符，且长度等于s1+k的子串的起始位置
//滑动窗口
//怎么快速判断子串包含了s1中所有的字符？ 
//int cnt[26]; 依次比较即可   1e5*26  1e6
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+10;

string s1, s2;
int k;
int cnt1[26], cnt2[26];

bool check(){
    for(int i = 0; i < 26; i++){
        if(cnt2[i] < cnt1[i])
            return false;
    }
    return true;
}

int main(){
    cin >> s1 >> s2;
    cin >> k;
    int n1 = s1.size();
    int n2 = s2.size();
    for(int i = 0; i < n1; i++) cnt1[s1[i]-'a']++;
    int l = 0, r = 0;
    for( ; r < n2; r++){
        cnt2[s2[r]-'a']++;
        if(r-l+1 < n1+k) continue;
        else{
            if(check()) 
                break;
            cnt2[s2[l++]-'a']--;
        }
    }
    if(l == n2-n1-k+1) cout << -1 << endl; 
    else cout << l << endl;
    return 0;
}

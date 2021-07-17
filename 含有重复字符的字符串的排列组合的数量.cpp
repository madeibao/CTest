



#include <bits/stdc++.h>
using namespace std;
int main()
{
    char s[10];
    if(!cin.getline(s,10)) {
        printf("0\n");
        return 0;
    }
    int l = strlen(s);
    if(l <= 0){
        printf("0\n");
        return 0;
    }
    sort(s, s+l);

    
    set<string> st;
    do{
        string t = "";
        for(int i = 0 ; i < l ; i++){
            t += s[i];
        }
        st.insert(t);
    }while(next_permutation(s, s+l));
    int ans = st.size();
    printf("%d\n",ans);
    return 0;
}




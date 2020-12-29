

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char *argv[]) {
    string a,b;
    while(cin>>a>>b){
         string res="1/"; 
         int n = (int)a.size(),m = (int)b.size();
         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
         dp[0][0] = 0;//dp[x][y]代表将a字符串前x个字符修改成b字符串前y个字符
         for (int i=1; i<=m; ++i) dp[0][i] = i;
         for (int i=1; i<=n; ++i) dp[i][0] = i;
         for (int i=1; i<=n; ++i) {
            for (int j=1; j<=m; ++j) {
                 int one = dp[i-1][j] +1,two = dp[i][j-1]+1,three = dp[i-1][j-1];
                 if(a[i-1]!=b[j-1]) three+=1;
                     dp[i][j] = min(min(one,two),three);
             }
         }
        
         res+=to_string(1+dp[n][m]);

         cout<<res<<endl;
    }
    return 0;
}




/*

#include<stdio.h>
#include<string.h>

int min(int a,int b,int c){
    int min;
    if(a<b)
        min=a;
        
    else
        min=b;
       
    if(c<min)
        min=c;
        
    return min;  
}



int main(){
    char a[1000];
    char b[1000];
    
    while(scanf("%s\n%s\n",&a,&b)!=EOF){
        int i,j,k;
        int d[1000][1000];
        int lena=strlen(a);
        int lenb=strlen(b);
        
        for(i=0;i<=lena;i++)
            d[i][0]=i;
        
        for(j=0;j<=lenb;j++)
            d[0][j]=j;
        
        for(i=1;i<=lena;i++){
            for(j=1;j<=lenb;j++){
                if(a[i-1]==b[j-1])
                    d[i][j]=d[i-1][j-1];
                else
                    d[i][j]=min(d[i-1][j-1],d[i-1][j],d[i][j-1])+1;
            }
        }
            
        printf("1/%d\n",(d[lena][lenb]+1));
        
        
    }
    
    return 0;
    
}
*/

//------------------------------------------------------------------------------------------------

#include<stdio.h>
#include<string.h>
int min(int a,int b,int c){
    int min;
    if(a<b)
        min=a;
        
    else
        min=b;
       
    if(c<min)
        min=c;
        
    return min;  
}

int main(){
    char s[1000];
    char t[1000];
    
    while(scanf("%s\n%s\n",&s,&t)!=EOF){
        int len1=strlen(s);
        int len2=strlen(t);
        int d[1000][1000]={0};
        int i,j,k;
        
        for(i=0;i<=len1;i++)
            d[i][0]=i;
        for(j=0;j<=len2;j++)
            d[0][j]=j;
        
        for(i=1;i<=len1;i++){
            for(j=1;j<=len2;j++){
                if(s[i-1]==t[j-1])
                    d[i][j]=d[i-1][j-1];
                else
                    d[i][j]=min(d[i-1][j-1],d[i][j-1],d[i-1][j])+1;
                
            }
        }
        printf("1/%d\n",(d[len1][len2]+1));    
        
        
    }
    return 0;
}











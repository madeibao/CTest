//默认字符为26个字母，如果不是，更改str_c的数组长度即可
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str_a[1024]={0};
    char str_b[101]={0};
    scanf("%s",str_a);
    scanf("%s",str_b);
    int n_a=strlen(str_a);
    int n_b=strlen(str_b);
    int str_c[26]={0};
    for(int i=0;i<n_b;i++)
    {
 
        for(int j=0;j<n_a;j++)
        {
            if(str_a[j]==str_b[i])
            {
                str_c[str_b[i]-'a']=1;
            }
        }
 
    }
    for(int i=0;i<26;i++)
    {
        if(str_c[i]==1)
        {
            printf("%c",i+'a');
        }
 
    }
    return 0;
}



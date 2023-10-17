#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define ll long long

ll N;
ll ans=-1;
int len;
char s[105];
char op;

bool check(ll x,char op){
	if(op=='-') x-=N;
	else if(op=='*') x*=N;
	else if(op=='+') x+=N;
	int number = x%10;
	while(x){
		if(x%10!=number) return false;
		x/=10;
	}
	return true;
}

int main(){
	scanf("%s",s+1);// 读入字符串
	len=strlen(s+1);
	scanf("%lld",&N);// 读入密钥数字
	scanf("%c",&op);// 读入运算符k
	// 滤去多余字符如'\n'等，保证运算符为+-*
	while(op!='+'&&op!='-'&&op!='*') scanf("%c",&op);
	// 最长12位，但是字符串可能不足12，取小
	int m=min(len,12);
	ll mod,tmp;
	for(int i=m;i>=3;--i){
		mod=pow(10,i-1);
		tmp=0;
		for(int j=1;j<i;++j){
			tmp=tmp*10+s[j]-'0';
		}
		for(int j=i;j<=len;++j){
			tmp=tmp*10+s[j]-'0';//循环运算，每次取模去掉最高位，再*10 加上当前位为当前数字
			if(check(tmp,op)){// 判断答案
				ans=max(ans,tmp);
			}
			tmp%=mod;
		}
	}
	printf("%lld",ans);

	return 0;
}

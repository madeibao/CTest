

//20170609周五下午,自己先做，没做对，然后看参考答案
#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    int num[128]={0};
    int count=0;
    gets(s);
    for(int i=0;i<strlen(s);i++) {
        if(s[i]>=0&&s[i]<=127)  num[s[i]]++;
    }
    for(int j=0;j<128;j++) {
        if(num[j]>0)  count++;
    }
        
    printf("%d",count);
    return 0;
}
//以上为我自己写的代码，经调试结果不对


#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main(int argc, char* argv[]) {


	char s[1000];
	int num[128] = {0};

	int res = 0;
	gets(s);

	for(int i=0;i<strlen(s);i++) {
		if(s[i]>=0 && s[i]<=127) {
			num[s[i]] +=1;
		}
	}

	for(int j=0;j<128;j++) {
		if(num[j]>0) {
			res += 1;
		}
	}
	cout<<res<<endl;
	return 0;
}